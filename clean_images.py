import os
import re

md_files = [f for f in os.listdir("STRINGS") if f.endswith(".md")]
used_images = set()

for md in md_files:
    with open(os.path.join("STRINGS", md), "r") as f:
        content = f.read()
    found = re.findall(r'!\[[^\]]*\]\((.*?)\)', content)
    for img in found:
        if img.startswith("images/"):
            used_images.add(img[7:])
        elif img.startswith("attachments/"):
            used_images.add(img)

# Now check images directory
images_dir = "STRINGS/images"
if os.path.isdir(images_dir):
    for f in os.listdir(images_dir):
        if f not in used_images:
            os.remove(os.path.join(images_dir, f))
            print("Removed unused image:", f)

# check attachments
attachments_dir = "STRINGS/attachments"
if os.path.exists(attachments_dir):
    if not os.listdir(attachments_dir):
        os.rmdir(attachments_dir)
        print("Removed empty attachments dir")
