#include "Calculator.h"
#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstring>

void Calculator::setExpression(const std::string& expr) {
    expression = "";
    for (char c : expr) {
        if (!isspace(static_cast<unsigned char>(c))) {
            expression += c;
        }
    }
}

bool Calculator::validateParentheses() {
    Stack<char> stack;
    for (char c : expression) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.isEmpty()) {
                return false;
            }
            char top = stack.pop();
            if (top != '(') {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

bool Calculator::validateTokens() {
    if (expression.empty()) {
        return false;
    }

    char firstChar = expression[0];
    if (firstChar == ')' || firstChar == '*' || firstChar == '/' || firstChar == '+') {
        return false;
    }

    char lastChar = expression[expression.length() - 1];
    if (lastChar == '(' || lastChar == '+' || lastChar == '*' || lastChar == '/' || lastChar == '-') {
        return false;
    }

    int parenBalance = 0;
    
    int state = 0;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        
        if (c >= '0' && c <= '9') {
            if (state != 0) {
                return false;
            }
            
            while (i + 1 < expression.length() && expression[i + 1] >= '0' && expression[i + 1] <= '9') {
                ++i;
            }
            
            state = 1;
        } else if (c == '(') {
            parenBalance++;
            
            if (state == 1) {
                return false;
            }
            
            state = 0;
        } else if (c == ')') {
            if (parenBalance <= 0 || state != 1) {
                return false;
            }
            
            parenBalance--;
            state = 1;
        } else if (c == '+' || c == '*' || c == '/') {
            if (state != 1) {
                return false;
            }
            
            state = 0;
        } else if (c == '-') {
            bool canBeUnary = (i == 0) || (expression[i-1] == '(');
            
            if (canBeUnary && state == 0) {
                continue;
            } else if (state == 1) {
                state = 0;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return parenBalance == 0 && state == 1;
}

bool Calculator::validateExpression() {
    return validateParentheses() && validateTokens();
}

std::vector<std::string> Calculator::infixToPostfix() {
    std::vector<std::string> output;
    Stack<char> operators;
    std::string number;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        
        if (c >= '0' && c <= '9') {
            number = "";
            while (i < expression.length() && expression[i] >= '0' && expression[i] <= '9') {
                number += expression[i];
                ++i;
            }
            output.push_back(number);
            --i;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                output.push_back(std::string(1, operators.pop()));
            }
            if (!operators.isEmpty() && operators.top() == '(') {
                operators.pop();
            } else {
                throw std::runtime_error("Mismatched parentheses");
            }
        }
        else if (c == '+' || c == '*' || c == '/') {
            int currPrec = (c == '+') ? 1 : 2;
            
            while (!operators.isEmpty() && operators.top() != '(') {
                char topOp = operators.top();
                int topPrec = (topOp == '+' || topOp == '-') ? 1 : 2;
                
                if (topPrec >= currPrec) {
                    output.push_back(std::string(1, operators.pop()));
                } else {
                    break;
                }
            }
            operators.push(c);
        }
        else if (c == '-') {
            bool isUnary = (i == 0) || (expression[i-1] == '(');
            
            if (isUnary) {
                number = "-";
                i++;
                
                if (i < expression.length() && expression[i] == '(') {
                    operators.push('~');
                    continue;
                }
                
                while (i < expression.length() && expression[i] >= '0' && expression[i] <= '9') {
                    number += expression[i];
                    i++;
                }
                output.push_back(number);
                i--;
            } else {
                int currPrec = 1;
                
                while (!operators.isEmpty() && operators.top() != '(') {
                    char topOp = operators.top();
                    int topPrec = (topOp == '+' || topOp == '-') ? 1 : 2;
                    
                    if (topPrec >= currPrec) {
                        output.push_back(std::string(1, operators.pop()));
                    } else {
                        break;
                    }
                }
                operators.push(c);
            }
        }
    }

    while (!operators.isEmpty()) {
        if (operators.top() == '(') {
            throw std::runtime_error("Mismatched parentheses");
        }
        output.push_back(std::string(1, operators.pop()));
    }
    
    return output;
}

int Calculator::evaluatePostfix(const std::vector<std::string>& tokens) {
    Stack<int> operands;
    
    for (const std::string& token : tokens) {
        if (!token.empty() && (token[0] >= '0' && token[0] <= '9' || (token[0] == '-' && token.length() > 1 && token[1] >= '0' && token[1] <= '9'))) {
            operands.push(std::stoi(token));
        } else if (token == "~") {
            if (operands.isEmpty()) {
                throw std::runtime_error("Invalid expression: not enough operands for unary minus");
            }
            int val = operands.pop();
            operands.push(-val);
        } else {
            if (operands.getSize() < 2) {
                throw std::runtime_error("Invalid expression: not enough operands for operator");
            }
            
            int b = operands.pop();
            int a = operands.pop();
            int result;
            
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) throw std::runtime_error("Division by zero");
                    result = a / b;
                    break;
                default: throw std::runtime_error("Invalid operator");
            }
            operands.push(result);
        }
    }
    
    if (operands.getSize() != 1) {
        throw std::runtime_error("Invalid expression: incorrect number of operands");
    }
    
    return operands.pop();
}

int Calculator::evaluate() {
    if (!validateExpression()) {
        throw std::runtime_error("Expression is not valid");
    }
    std::vector<std::string> postfix = infixToPostfix();
    return evaluatePostfix(postfix);
}
