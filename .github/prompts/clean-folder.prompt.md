---
description: "Clean up a specific Competitive Programming folder, fix markdown, remove unused images, and push to remote."
name: "Clean Folder"
agent: "agent"
argument-hint: "Folder name and any additional instructions"
---

# Clean and Push Folder Workflow

You are tasked to clean up and push a subfolder in the Competitive Programming workspace based on the user's input.

**Target Folder & Instructions**: The user will provide the folder name and any extra instructions when calling this prompt.

Follow these strict rules based on our previous cleanups:

1. **Analyze Folder**: Check the contents of the specified folder using terminal or workspace tools. Look specifically for `.md` files, `images/`, and `attachments/`.
2. **Clean Markdown Files & Clumped Entities**: Ensure no strange HTML tags (like `<span style="...">` or inline CSS) are left from exports. Convert them to standard Markdown. Fix heading structures if they just awkwardly duplicate the file name, and explicitly remove trailing empty headers (like `# ` lines with nothing else).
    
    - **Fix heavily indented and spaced elements**: Markdown might contain elements like `     # [URL](...)` or `     CODE:`. Remove the excessive leading spaces so they are flush with the left margin. Standardize awkward titles like `CODE:` or `THEORY:` to normal markdown headers (`## CODE`, `## THEORY`).
    - **Fix Displaced Code Comments**: Sometimes single-line C++ comments (e.g. `// ...`) are violently broken apart from their associated code, placing them 1-2 empty lines below the line of code they describe (like `int x = 5;\n\n // some comment`). Use regex or string matching to pull these floating `//` comments back onto the same line as the preceding code, especially focusing on those trailing after `;` or `{`.
    - **Handle Extreme Splitting inside Code**: Some C++ declarations might be randomly split across lines (e.g. `const \n\n int mod = 1e9 + 7;`). Make sure to merge them into valid single-line declarations (`const int mod = 1e9 + 7;`).
    - **Handle Variable Image/Link whitespace**: When fixing clumped images or links, the regex `\)\s+!\[` (for any amount of whitespace) should be used instead of just replacing `) ![` since exports sometimes drop 50+ spaces between links or images!
        
    - **Fix Clumped Links and Images**: Note-taking apps frequently export multiple images or links jammed onto the exact same line with spaces between them (e.g., `![img1](...)     ![img2](...)`). You MUST strictly separate them so every image and link is on its own line. Use regex or string matching to find `) ![` sequences.
    - **Remove Stray Indentation**: Remove awkward leading spaces (e.g., 4 or 5 spaces) before normal text and markdown links that accidentally cause Markdown to parse them as preformatted code blocks. Look out for C++ lambdas formatted as `[int a, int b](...)` that were accidentally parsed as broken Markdown links, and wrap them in backticks (\`).
3. **Handle Empty/Stub Files**: Identify files that are completely empty. Only delete files if they are strictly empty. Do not delete small files (like Catalog pages) just because they have few characters.
4. **Fix Unfenced & Highlighted Raw Code Exports**: Note-taking apps often export C++ code completely without markdown code blocks, leaving bare code sitting in the file. Look for typical C++ keywords (like `#include`, `using namespace`, `const int`, `vector<`, `struct`, `for (int`) that are floating in the markdown without fences.
    - You **MUST** explicitly wrap ALL of this raw C++ code inside proper ```cpp ... ``` fences.
    - If the code was exported as literal Markdown bold/italics (e.g., `**struct**`, `***Matrix***`, `*const*`), actively strip out all the Markdown text formatting (asterisks, underscores) from the raw code.
    - Remove trailing formatting from comments (like `// some comment *` -> `// some comment`).
    - Fix the indentation and merge fragmented blocks together into a cohesive fenced C++ block.



5. **Convert to C++ Files where Appropriate**: If a markdown file only contains a single heading and then a block of C++ code (or code you just fixed within `cpp` fences), convert it to a `.cpp` file (e.g. move the code to the `.cpp` file and use the heading as a top-level comment or the file's name). **Crucial**: Strip the Markdown code fences (``cpp` and ``) when moving code into a `.cpp` file to avoid compilation errors. Otherwise, retain it as a markdown file.
6. **Clean Images**: Very carefully verify that every single image in `images/` is referenced in the markdown files. Be aware of the Global vs Local Images Context: explicitly check both the local `images/` directory and root `images/` directory for references, as the workspace structure may vary. Delete any unused or dangling images to save space.
7. **Clean Attachments**: Check `attachments/`. If it is empty or the files are unused, delete the folder/files.
8. **Rename Files**: If the user's instructions specify, or if file names are overly long/messy (like standard export artifacts), rename them to concise, readable names. **Crucial**: Ensure any internal links to images remain perfectly valid if you alter files.
9. **Ignore OS Artifacts**: Delete any `.DS_Store` files before committing, as these macOS artifacts tend to sneak into folders.
10. **Git Operations**:
    - Stage the specific folder only: `git add "<folder>"`
    - Commit with a meaningful message: `git commit -m "Clean up and add <folder> notes"`
    - Push to the remote: `git push`

Execute these steps thoroughly and sequentially. Wait to evaluate findings at each step before moving on. Use the terminal extensively for git commands and workspace investigation, and use edit tools to standardize the Markdown.
