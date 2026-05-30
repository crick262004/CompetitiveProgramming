import os
import re
import urllib.parse

def check_md_files(base_dir):
    issues = {}
    
    # Regex for finding markdown links [text](path) or images ![text](path)
    link_pattern = re.compile(r'!?\[.*?\]\(([^)]+)\)')

    for root, dirs, files in os.walk(base_dir):
        # Ignore hidden directories like .git
        dirs[:] = [d for d in dirs if not d.startswith('.')]
        for file in files:
            if file.endswith('.md'):
                filepath = os.path.join(root, file)
                file_issues = []
                
                try:
                    with open(filepath, 'r', encoding='utf-8') as f:
                        content = f.read()
                        
                        # 2. Check broken local links
                        links = link_pattern.findall(content)
                        for link in links:
                            link = link.strip()
                            if not link.startswith(('http://', 'https://', '#', 'mailto:')):
                                # Clean up link if there is a '#' anchor in it
                                path = link.split('#')[0].strip()
                                # Handle URL encoded spaces and other characters
                                path = urllib.parse.unquote(path)
                                
                                if path:
                                    target_path = os.path.join(root, path) # Assume relative path
                                    if not os.path.exists(target_path):
                                        file_issues.append(f"Broken link: '{link}' (resolved to {target_path})")

                        # 3. Code Block formatting issues (odd number of ```)
                        code_blocks_count = content.count('```')
                        if code_blocks_count % 2 != 0:
                            file_issues.append(f"Unclosed code block (found {code_blocks_count} '```' markers)")

                        # 4. Math Block formatting issues (odd number of $$)
                        math_blocks_count = content.count('$$')
                        if math_blocks_count % 2 != 0:
                            file_issues.append(f"Unclosed math block (found {math_blocks_count} '$$' markers)")
                            
                        # Simple inline math check ($)
                        inline_math_count = len(re.findall(r'(?<!\\)\$', re.sub(r'\$\$.*?\$\$', '', content, flags=re.DOTALL)))
                        if inline_math_count % 2 != 0:
                            file_issues.append(f"Possible unclosed inline math block (odd number of $ markers)")

                except Exception as e:
                    file_issues.append(f"Error reading file: {e}")

                if file_issues:
                    rel_path = os.path.relpath(filepath, start='.')
                    issues[rel_path] = file_issues

    return issues

if __name__ == "__main__":
    target_directory = "."
    if not os.path.exists(target_directory):
        print(f"Directory {target_directory} not found.")
    else:
        results = check_md_files(target_directory)
        if not results:
            print("No issues found in any Markdown files!")
        else:
            print("Issues Found:\n" + "-"*40)
            for file, problems in results.items():
                print(f"[file] {file}:")
                for p in problems:
                    print(f"  - {p}")
                print()
