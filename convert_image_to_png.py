"""
JPEG/JPG → PNG Batch Converter
Date: 2025-09-27

Scans the current working directory for .jpg/.jpeg files and strips them
 of their metadata, it then converts them into .png format inside a 
 'converted_pngs' folder.
"""


from PIL import Image
import os

input_folder = os.getcwd()  # current working directory
output_folder = os.path.join(input_folder, "converted_pngs")
os.makedirs(output_folder, exist_ok=True)

for file_name in os.listdir(input_folder):
    if file_name.lower().endswith((".jpg", ".jpeg")):
        input_path = os.path.join(input_folder, file_name)
        output_path = os.path.join(
            output_folder, os.path.splitext(file_name)[0] + ".png"
        )
        with Image.open(input_path) as img:
            img.convert("RGB").save(output_path, "PNG", optimize=True)

print("Done! Converted files are in:", output_folder)
