#include "Fraction.h"
#include <iostream>

int main() {
    try {
        Fraction f1(2, 3);
        Fraction f2(3, 4);
        Fraction f3(-1, 2);
        Fraction f4(6, 8);
        
        std::cout << "f1 = "; f1.print(); std::cout << "\n";
        std::cout << "f2 = "; f2.print(); std::cout << "\n";
        std::cout << "f3 = "; f3.print(); std::cout << "\n";
        std::cout << "f4 = "; f4.print(); std::cout << "\n";
        
        Fraction f5(f1);
        std::cout << "f5 = "; f5.print(); std::cout << "\n";
        
        Fraction sum = f1.add(f2);
        std::cout << "sum = "; sum.print(); std::cout << "\n";
        
        Fraction product = f1.multiply(f2);
        std::cout << "product = "; product.print(); std::cout << "\n";
        
        Fraction quotient = f1.divide(f2);
        std::cout << "quotient = "; quotient.print(); std::cout << "\n";
        
        Fraction sum2 = f1.add(f3);
        std::cout << "sum2 = "; sum2.print(); std::cout << "\n";
        
        Fraction f6(1, 0);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
