import os

dump_path = "/Users/arnavgupta/Library/Application Support/Code/User/workspaceStorage/9eaff483b6d1bb18a6dacf210a30e1af/GitHub.copilot-chat/chat-session-resources/114fe609-5850-430b-b848-242f658a210c/call_MHxyWUY5VnRIV0dPc0k0aXNLUEE__vscode-1775335016854/content.txt"

with open(dump_path, 'r', encoding='utf-8') as f:
    text = f.read()

j1 = text.find("# Split string by “ “ : Combine")
j2 = text.find("# String parsing/ formatting")
if j1 != -1 and j2 != -1:
    extracted2 = text[j1:j2]
    with open("STRINGS/Split string by “ “.md", "w") as out:
        out.write(extracted2)
    print("Restored Split string by “ “.md")

i1 = text.find("# String parsing/ formatting")
i2 = text.find("# String to Integer (atoi) :")
if i1 != -1 and i2 != -1:
    extracted = text[i1:i2]
    with open("STRINGS/String parsing- formatting.md", "w") as out:
        out.write(extracted)
    print("Restored String parsing- formatting.md")
