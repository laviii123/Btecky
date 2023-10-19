#include <iostream>
#include <stack>
#include <cctype>

// Function to determine the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1; // For invalid operators
    }
}

// Function to convert infix to postfix
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> stack;
    std::string postfix;

    for (char token : infix) {
        if (std::isalnum(token)) {
            postfix += token;
        } else if (token == '(') {
            stack.push(token);
        } else if (token == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Pop '('
        } else {
            while (!stack.empty() && precedence(token) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(token);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    std::string infix, postfix;

    std::cout << "Enter infix expression: ";
    std::cin >> infix;

    postfix = infixToPostfix(infix);

    std::cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}
