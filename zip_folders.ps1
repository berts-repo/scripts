#
# This powershell script individually zips each folder within a parent folder on Windows
#

# TODO: path variables to assign
$parentFolderPath = "C:\Path\To\Parent\Folder"
$destinationFolderPath = "C:\Path\To\Destination\Folder"

# Get all the subfolders within the parent folder
$subfolders = Get-ChildItem -Path $parentFolderPath -Directory

# Loop through each subfolder
foreach ($folder in $subfolders) {
    # Define the path to the output zip file in the destination folder
    $zipFilePath = Join-Path -Path $destinationFolderPath -ChildPath "$($folder.Name).zip"
    
    # Create the zip file
    Compress-Archive -Path $folder.FullName -DestinationPath $zipFilePath
}

Write-Output "All folders have been zipped successfully."

