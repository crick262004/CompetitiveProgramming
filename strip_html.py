import os
import re

dir_path = 'STRINGS'

def strip_html_and_stars(content):
    # Regex to match HTML tags
    content = re.sub(r'<[^>]+>', '', content)
    
    # Remove markdown bold/italics from code keywords 
    # e.g., **struct**, *const*
    content = re.sub(r'\*\*(.*?)\*\*', r'\1', content)
    content = re.sub(r'\*(.*?)\*', r'\1', content)
    
    return content

def fix_all_md_files():
    for file in os.listdir(dir_path):
        if not file.endswith('.md'):
            continue
        
        filepath = os.path.join(dir_path, file)
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()

        new_content = strip_html_and_stars(content)
        
        # fix multiple empty lines
        new_content = re.sub(r'\n{3,}', '\n\n', new_content)

        # After stripping html, maybe some files are more than 60% C++ now
        lines = [line.strip() for line in new_content.split('\n') if line.strip()]
        num_code_lines = sum(1 for line in lines if line.endswith(';') or line.endswith('{') or line.endswith('}') or line.startswith('//'))
        
        is_cpp = False
        if len(lines) > 0 and num_code_lines / len(lines) > 0.5:
            is_cpp = True

        if is_cpp:
            new_content = re.sub(r'^#+\s+(.*)', r'// \1', new_content, flags=re.MULTILINE)
            # Remove image links if it's becoming a cpp? Cpp shouldn't have images
            if '![' not in new_content:
                new_name = file.replace('.md', '.cpp')
                with open(os.path.join(dir_path, new_name), 'w', encoding='utf-8') as f:
                    f.write(new_content)
                os.remove(filepath)
                print(f"Renamed {file} to {new_name} and cleaned")
                continue

        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print(f"Cleaned {file}")

fix_all_md_files()
