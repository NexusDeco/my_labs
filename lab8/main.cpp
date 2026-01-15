#include "Calculator.h"
#include <iostream>
#include <string>

int main() {
    Calculator calc;
    std::string expression;
    
    std::cout << "=== Simple Calculator ===" << std::endl;
    std::cout << "Enter a mathematical expression (e.g., (2+6)/(7-5)): ";
    std::getline(std::cin, expression);
    
    std::cout << "\nProcessing expression: " << expression << std::endl;
    
    calc.setExpression(expression);
    
    if (calc.validateExpression()) {
        std::cout << "✓ Expression is valid!" << std::endl;
        
        try {
            int result = calc.evaluate();
            std::cout << "\nResult: " << expression << " = " << result << std::endl;
            std::cout << "Calculation completed successfully!" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "✗ Error during calculation: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "✗ Invalid expression format!" << std::endl;
        std::cerr << "Please check your expression and try again." << std::endl;
    }
    
    return 0;
}
