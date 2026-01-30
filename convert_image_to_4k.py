"""
Image Resizer to 4K
-------------------------
This script scans the current directory for image files 
(JPG, PNG, BMP, TIFF, WEBP) and scales them to 4K resolution 
(3840x2160). The resized images are saved in a new folder 
called '4k_scaled'.

Bert Darnell
Date: September 27, 2025
"""

from PIL import Image
import os

input_folder = "."
output_folder = "./4k_scaled"
os.makedirs(output_folder, exist_ok=True)

target_size = (3840, 2160)

extensions = (".jpg", ".jpeg", ".png", ".bmp", ".tiff", ".webp")

for filename in os.listdir(input_folder):
    if filename.lower().endswith(extensions):
        infile = os.path.join(input_folder, filename)
        outfile = os.path.join(
            output_folder, f"{os.path.splitext(filename)[0]}_4k.jpg"
        )
        
        img = Image.open(infile)
        img_resized = img.resize(target_size, Image.Resampling.LANCZOS)
        
        img_resized.save(outfile, quality=95)
        print(f"Saved {outfile}")
