import os
import re

folder_path = "Greedy + Constructive-Ad-hoc - Non Algo Stuff"

def clean_markdown(content):
    # Remove span tags
    content = re.sub(r'<span[^>]*>', '', content)
    content = re.sub(r'</span>', '', content)
    
    # Remove u tags
    content = re.sub(r'<u>|</u>', '', content)
    
    # Fix clumped images / links: ") ![" -> ")\n!["
    content = re.sub(r'\)[ \t\xa0\u200b]+!\[', ')\n![', content)
    content = re.sub(r'\)[ \t\xa0\u200b]+<', ')\n<', content)
    content = re.sub(r'>[ \t\xa0\u200b]+!\[', '>\n![', content)
    
    # Remove leading spaces from lines, BUT we have to be careful if it's code. 
    # In these text heavy files, let's just strip lines that start with spaces but are mostly text formatting.
    # We will strip spaces before text, # , *, and links.
    lines = content.split('\n')
    new_lines = []
    
    # Check if we are inside a code block (though there may be no fences initially)
    in_code = False
    
    for line in lines:
        if line.strip().startswith('```'):
            in_code = not in_code
            new_lines.append(line.rstrip())
            continue
            
        if not in_code:
            # strip trailing
            l = line.rstrip()
            # strip excessive leading spaces if it's a markdown element
            stripped = l.lstrip()
            if stripped.startswith('#') or stripped.startswith('*') or stripped.startswith('[') or stripped.startswith('!') or stripped.startswith('**'):
                # just remove leading space completely
                new_lines.append(stripped)
            else:
                # also just regular text we strip generally if it's deeply indented and mostly text
                new_lines.append(stripped)
        else:
            new_lines.append(line.rstrip())
            
    content = '\n'.join(new_lines)
    
    # Ensure standard headers
    content = re.sub(r'^CODE:\s*$', '## CODE', content, flags=re.MULTILINE)
    content = re.sub(r'^THEORY:\s*$', '## THEORY', content, flags=re.MULTILINE)
    
    # Fix trailing space in headers
    content = re.sub(r'^(#+)\s*$', '', content, flags=re.MULTILINE)
    
    # Squeeze multiple blank lines into double
    content = re.sub(r'\n{3,}', '\n\n', content)
    
    return content.strip() + '\n'

for f in os.listdir(folder_path):
    if f.endswith('.md'):
        path = os.path.join(folder_path, f)
        with open(path, 'r', encoding='utf-8') as file:
            content = file.read()
        
        new_content = clean_markdown(content)
        
        with open(path, 'w', encoding='utf-8') as file:
            file.write(new_content)
    
print("Cleaned!")
