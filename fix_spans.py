import re

files = ["STRINGS/Split string by “ “.md", "STRINGS/String parsing- formatting.md", "STRINGS/Z-Function.md"]
for file in files:
    with open(file, "r") as f:
        content = f.read()
    
    content = re.sub(r'<span[^>]*>', '', content)
    content = re.sub(r'</span>', '', content)
    
    # Remove markdown bold/italics from code keywords 
    # e.g., **struct**, *const*
    content = re.sub(r'\*\*(.*?)\*\*', r'\1', content)
    content = re.sub(r'\*(.*?)\*', r'\1', content)
    
    with open(file, "w") as f:
        f.write(content)
