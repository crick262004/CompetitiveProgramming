# POSTFIX, PREFIX, INFIX : IDK, RAKH LE IG

# 
# POSTFIX TO PREFIX

bool isOperator(char x) {
        switch (x) {
            case '+':
            case '-':
            case '/':
            case '*':
                return true;
        }
        return false;
    }

    string postToPre(string post_exp) {
        stack<string> s;

        // length of expression
        int length = post_exp.size();

        // reading from right to left
        for (int i = 0; i < length; i++) {

            // check if symbol is operator
            if (isOperator(post_exp[i])) {

                // pop two operands from stack
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();

                // concat the operands and operator
                string temp = post_exp[i] + op2 + op1;

                // Push string temp back to stack
                s.push(temp);
            }

            // if symbol is an operand
            else {

                // push the operand to the stack
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


# POSTFIX TO INFIX

// Function to check if a character is an operand.
    bool isOperand(char x) {
        return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
    }

    // Function to convert postfix expression to infix expression.
    string postToInfix(string exp) {
        stack<string> s;
        int n = exp.size();

        // Iterating through each character in the expression.
        for (int i = 0; i < n; i++) {
            // If the character is an operand, push it to the stack.
            if (isOperand(exp[i])) {
                string op(1, exp[i]);
                s.push(op);
            } else {
                // If the character is an operator, pop two operands from the stack,
                // create a new string in the format (op2 operator op1), and push it back to the stack.
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
                s.push("(" + op2 + exp[i] + op1 + ")");
            }
        }
        // Return the final infix expression stored in the stack.
        return s.top();
    }

# PREFIX TO POSTFIX

bool isOperator(char x) {
        switch (x) {
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                return true;
        }
        return false;
    }

    // Convert prefix to Postfix expression
    string preToPost(string pre_exp) {

        stack<string> s;
        // length of expression
        int length = pre_exp.size();

        // reading from right to left
        for (int i = length - 1; i >= 0; i--) {
            // check if symbol is operator
            if (isOperator(pre_exp[i])) {
                // pop two operands from stack
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();

                // concat the operands and operator
                string temp = op1 + op2 + pre_exp[i];

                // Push string temp back to stack
                s.push(temp);
            }

            // if symbol is an operand
            else {

                // push the operand to the stack
                s.push(string(1, pre_exp[i]));
            }
        }

        // stack contains only the Postfix expression
        return s.top();
    }


# PREFIX TO INFIX

bool isOperator(char x) {
  **switch** (x) {
  **case** '+':
  **case** '-':
  **case** '/':
  **case** '*':
  **case** '^':
  **case** '%':
    **return** true;
  }
  **return** false;
}

*// Convert prefix to Infix expression*
string preToInfix(string pre_exp) {
  stack<string> s;

  *// length of expression*
  int length = pre_exp.size();

  *// reading from right to left*
  **for** (int i = length - 1; i >= 0; i--) {

    *// check if symbol is operator*
    **if** (isOperator(pre_exp[i])) {

      *// pop two operands from stack*
      string op1 = s.top();   s.pop();
      string op2 = s.top();   s.pop();

      *// concat the operands and operator*
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";

      *// Push string temp back to stack*
      s.push(temp);
    }

    *// if symbol is an operand*
    **else** {

      *// push the operand to the stack*
      s.push(string(1, pre_exp[i]));
    }
  }

  *// Stack now contains the Infix expression*
  **return** s.top();
}

# INFIX TO PREFIX


bool isOperator(char c) {
  return (!isalpha(c) && !isdigit(c));
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

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  int l = infix.size();
  stack < char > char_stack;
  string output;

  for (int i = 0; i < l; i++) {

    *// If the scanned character is an*
    *// operand, add it to output.*
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    *// If the scanned character is an*
    *// ‘(‘, push it to the stack.*
    else if (infix[i] == '(')
      char_stack.push('(');

    *// If the scanned character is an*
    *// ‘)’, pop and output from the stack*
    *// until an ‘(‘ is encountered.*
    else if (infix[i] == ')') {
      while (char_stack.top() != '(') {
        output += char_stack.top();
        char_stack.pop();
      }

      *// Remove '(' from the stack*
      char_stack.pop();
    }

    *// Operator found*
    else {
      if (isOperator(char_stack.top())) {
        if (infix[i] == '^') {
          while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
            output += char_stack.top();
            char_stack.pop();
          }

        } else {
          while (getPriority(infix[i]) < getPriority(char_stack.top())) {
            output += char_stack.top();
            char_stack.pop();
          }

        }

        *// Push current Operator on stack*
        char_stack.push(infix[i]);
      }
    }
  }
  while (!char_stack.empty()) {
    output += char_stack.top();
    char_stack.pop();
  }
  return output;
}

string infixToPrefix(string infix) {
  */* Reverse String
   * Replace ( with ) and vice versa
   * Get Postfix
   * Reverse Postfix  *  */*
  int l = infix.size();

  *// Reverse infix*
  reverse(infix.begin(), infix.end());

  *// Replace ( with ) and vice versa*
  for (int i = 0; i < l; i++) {

    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
      infix[i] = '(';
      i++;
    }
  }

  string prefix = infixToPostfix(infix);

  *// Reverse postfix*
  reverse(prefix.begin(), prefix.end());

  return prefix;
}

# INFIX TO POSTFIX

*//Function to return precedence of operators*
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

*// The main function to convert infix expression*
*//to postfix expression*
void infixToPostfix(string s) {

  stack < char > st; *//For stack operations, we are using C++ built in stack*
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    *// If the scanned character is*
    *// an operand, add it to output string.*
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    *// If the scanned character is an*
    *// ‘(‘, push it to the stack.*
    else if (c == '(')
      st.push('(');

    *// If the scanned character is an ‘)’,*
    *// pop and to output string from the stack*
    *// until an ‘(‘ is encountered.*
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    *//If an operator is scanned*
    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  *// Pop all the remaining elements from the stack*
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Prefix expression: " << result << endl;
}
