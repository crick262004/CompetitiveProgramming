import os
import re

dir_path = "STRINGS"

for file in os.listdir(dir_path):
    if not os.path.isfile(os.path.join(dir_path, file)): continue
    if not file.endswith((".cpp", ".md")): continue
    
    with open(os.path.join(dir_path, file), "r") as f:
        lines = f.readlines()
        
    new_lines = []
    for line in lines:
        if line.startswith("     "): # 5 spaces is typical notion junk
            line = line[5:]
        elif line.startswith("    "): # keep 4 spaces for C++ indent
            pass
        elif line.startswith("  "):
            line = line[2:]
        new_lines.append(line)
        
    content = "".join(new_lines)
    content = re.sub(r'\n{3,}', '\n\n', content)
    
    with open(os.path.join(dir_path, file), "w") as f:
        f.write(content)
