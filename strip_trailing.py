import os
import re

dir_path = "STRINGS"

for file in os.listdir(dir_path):
    if not os.path.isfile(os.path.join(dir_path, file)): continue
    if not file.endswith((".cpp", ".md")): continue
    
    with open(os.path.join(dir_path, file), "r") as f:
        lines = f.readlines()
        
    new_content = "\\n".join([line.rstrip() for line in lines])
    new_content = new_content.replace("\\\\n", "\\n")
    new_content = new_content.replace("```cpp\\n", "```cpp\\n")
    
    with open(os.path.join(dir_path, file), "w") as f:
        f.write(new_content)
