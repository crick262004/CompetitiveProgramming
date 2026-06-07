#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// --- Helper Functions ---

bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}

bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}


// --- POSTFIX TO PREFIX ---

string postToPre(string post_exp) {
    stack<string> s;
    int length = post_exp.size();

    // reading from right to left
    for (int i = 0; i < length; i++) {
        if (isOperator(post_exp[i])) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = post_exp[i] + op2 + op1;
            s.push(temp);
        } else {
            s.push(string(1, post_exp[i]));
        }
    }

    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}


// --- POSTFIX TO INFIX ---

string postToInfix(string exp) {
    stack<string> s;
    int n = exp.size();

    for (int i = 0; i < n; i++) {
        if (isOperand(exp[i])) {
            string op(1, exp[i]);
            s.push(op);
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}


// --- PREFIX TO POSTFIX ---

string preToPost(string pre_exp) {
    stack<string> s;
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + op2 + pre_exp[i];
            s.push(temp);
        } else {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}


// --- PREFIX TO INFIX ---

string preToInfix(string pre_exp) {
    stack<string> s;
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op1 + pre_exp[i] + op2 + ")";
            s.push(temp);
        } else {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}


// --- INFIX TO POSTFIX ---

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isOperand(c)) {
            result += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}


// --- INFIX TO PREFIX ---

string infixToPostfixForPrefix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {
        if (isOperand(infix[i])) {
            output += infix[i];
        } else if (infix[i] == '(') {
            char_stack.push('(');
        } else if (infix[i] == ')') {
            while (!char_stack.empty() && char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            if(!char_stack.empty()) char_stack.pop();
        } else {
            while (!char_stack.empty() && isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    if (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    } else {
                        break;
                    }
                } else {
                    if (getPriority(infix[i]) < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    } else {
                        break;
                    }
                }
            }
            char_stack.push(infix[i]);
        }
    }
    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}

string infixToPrefix(string infix) {
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfixForPrefix(infix);

    // Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    return 0;
}