import os
import re

files = [
    "STRINGS/Roman to Integer.md",
    "STRINGS/Split string by “ “.md",
    "STRINGS/String to Integer (atoi).md",
    "STRINGS/String parsing- formatting.md",
    "STRINGS/Z-Function.md"
]

for file in files:
    print(f"--- {os.path.basename(file)} ---")
    with open(file, 'r', encoding='utf-8') as f:
        print(f.read()[:500])
        print("...")
