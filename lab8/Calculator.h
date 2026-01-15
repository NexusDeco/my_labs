#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Stack.h"
#include <string>
#include <vector>

class Calculator {
private:
    std::string expression;

    bool validateParentheses();
    bool validateTokens();
    int evaluatePostfix(const std::vector<std::string>& tokens);
    std::vector<std::string> infixToPostfix();

public:
    Calculator() = default;
    Calculator(const std::string& expr) : expression(expr) {}

    void setExpression(const std::string& expr);
    bool validateExpression();
    int evaluate();
};

#endif
