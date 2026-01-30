
<#
.SYNOPSIS
    Creates a detailed system baseline snapshot after a fresh Windows 11 installation.
.DESCRIPTION
    Collects system, network, process, and service information into timestamped reports 
    for forensic comparison and security monitoring.

## How to Use This Script

1. **Open PowerShell as Administrator**
2. **Paste script into `Create-Win11-Baseline.ps1`**
3. Run:

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force
.\create-win-baseline.ps1
```
#>


function Write-BaselineStatus {
    param(
        [string]$Message
    )
    $timestamp = (Get-Date).ToString("yyyy-MM-dd HH:mm:ss")
    Write-Host "[$timestamp] $Message"
}

# Ensure the script is running as Administrator
if (-not ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole(
    [Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Warning "Please run this script as Administrator!"
    pause
    exit
}

# Setup: Create a timedate directory in user's \Documents\baseline
$documents  = [Environment]::GetFolderPath("MyDocuments")
$parentDir  = Join-Path $documents "baseline"
$timestamp  = Get-Date -Format "yyyy-MM-dd-HHmmss"
$baselineDir = Join-Path $parentDir $timestamp

# Ensure Baseline directory exists
if (-not (Test-Path $parentDir)) {
    New-Item -ItemType Directory -Path $parentDir | Out-Null
}

# Create timestamped snapshot folder
New-Item -ItemType Directory -Force -Path $baselineDir | Out-Null


Write-BaselineStatus "Saving baseline to: $baselineDir"

# 1. System Info
Write-BaselineStatus "Collecting system info..."
systeminfo > "$baselineDir\systeminfo.txt"

# 2. Installed Programs
Write-BaselineStatus "Collecting installed programs..."
Get-ItemProperty HKLM:\Software\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall\* |
    Select-Object DisplayName, DisplayVersion, Publisher, InstallDate |
    Sort-Object DisplayName |
    Out-File "$baselineDir\installed-programs.txt"

# 3. Running Processes with Signatures
Write-BaselineStatus "Collecting running processes with signatures..."
Get-WmiObject Win32_Process | ForEach-Object {
    $path = $_.ExecutablePath
    $signed = if ($path -and (Test-Path $path)) {
        (Get-AuthenticodeSignature $path).Status
    } else {
        "N/A"
    }
    [PSCustomObject]@{
        Name   = $_.Name
        PID    = $_.ProcessId
        Path   = $path
        Signed = $signed
    }
} | Out-File "$baselineDir\processes-with-signature.txt"

# 4. Services
Write-BaselineStatus "Collecting service details..."
Get-WmiObject Win32_Service |
    Select-Object DisplayName, Name, StartMode, State, PathName |
    Sort-Object DisplayName |
    Out-File "$baselineDir\services-detailed.txt"

# 5. Network Info
Write-BaselineStatus "Collecting network configuration..."
Get-NetAdapter > "$baselineDir\net-adapters.txt"
Get-NetIPAddress > "$baselineDir\net-ipconfig.txt"
ipconfig /all > "$baselineDir\ipconfig.txt"

# 6. Listening Ports and Connections
Write-BaselineStatus "Collecting network connections (netstat)..."
netstat -ano > "$baselineDir\netstat.txt"

Write-BaselineStatus "Collecting active TCP connections..."
Get-NetTCPConnection |
    Select-Object LocalAddress, LocalPort, RemoteAddress, RemotePort, State, OwningProcess |
    Out-File "$baselineDir\tcp-connections.txt"

# 7. Scheduled Tasks
Write-BaselineStatus "Collecting scheduled tasks..."
schtasks /query /fo LIST /v > "$baselineDir\scheduled-tasks.txt"

# 8. Windows Defender Status
Write-BaselineStatus "Collecting Windows Defender status..."
Get-MpComputerStatus > "$baselineDir\defender-status.txt"

# 9. Drivers
Write-BaselineStatus "Collecting driver list..."
driverquery /V > "$baselineDir\drivers.txt"

# 10. Startup Items (Autoruns)
$autorunPath  = "$baselineDir\autoruns.txt"
$autorunZip   = "$parentDir\Autoruns.zip"
$autorunsDir  = "$parentDir\Autoruns"
$autorunExe = Join-Path $autorunsDir "autorunsc.exe"

if (-not (Test-Path $autorunExe)) {
    Write-BaselineStatus "Downloading Autoruns from Sysinternals..."
    Invoke-WebRequest -Uri "https://download.sysinternals.com/files/Autoruns.zip" -OutFile $autorunZip
    Expand-Archive $autorunZip -DestinationPath $autorunsDir -Force
    Write-BaselineStatus "Autoruns extracted to: $autorunsDir"
} else {
    Write-BaselineStatus "Autoruns already present. Skipping download."
}

Write-BaselineStatus "Running Autorunsc to capture startup programs..."
& $autorunExe -accepteula -a * > $autorunPath

# 11. File Hashing - System32 (optional, may take time)
Write-BaselineStatus "Hashing files in C:\Windows\System32 (this may take a while)..."
$hashLog      = "$baselineDir\win32-hashes.txt"
$errorLogPath = "$baselineDir\win32-hashes-errors.txt"

Get-ChildItem C:\Windows\System32 -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object {
    try {
        $hash = Get-FileHash $_.FullName -Algorithm SHA256 -ErrorAction Stop
        "$($hash.Algorithm) $($hash.Hash) $($hash.Path)" | Out-File $hashLog -Append
    } catch {
        # Log errors quietly without showing in console
        "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] Failed: $($_.Exception.Message)`nPath: $($_.FullName)`n" |
            Out-File $errorLogPath -Append
    }
}

# Restore error preference
$ErrorActionPreference = "Continue"

# 12. Windows Optional Features
Write-BaselineStatus "Collecting Windows optional feature list..."
DISM /Online /Get-Features /Format:Table > "$baselineDir\windows-features.txt"

# 13. Windows Defender Preferences
Write-BaselineStatus "Collecting Windows Defender configuration preferences..."
Get-MpPreference | Out-File "$baselineDir\defender-preferences.txt"


# END
Write-BaselineStatus "Baseline snapshot complete."
Write-Host "All files saved in: $baselineDir" -ForegroundColor Green