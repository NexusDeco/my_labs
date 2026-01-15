#include "Calculator.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_simple_expressions() {
    Calculator calc;
    
    calc.setExpression("3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 3);
    
    calc.setExpression("10");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 10);
    
    calc.setExpression("123");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 123);
}

void test_basic_operations() {
    Calculator calc;
    
    calc.setExpression("3+5");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 8);
    
    calc.setExpression("10-2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 8);
    
    calc.setExpression("4*5");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 20);
    
    calc.setExpression("10/2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
}

void test_operator_precedence() {
    Calculator calc;
    
    calc.setExpression("3+5*2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 13);
    
    calc.setExpression("10-2*3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 4);
    
    calc.setExpression("10/2+3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 8);
    
    calc.setExpression("3*2+4/2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 8);
}

void test_parentheses() {
    Calculator calc;
    
    calc.setExpression("(3+5)*2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 16);
    
    calc.setExpression("10-(2*3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 4);
    
    calc.setExpression("(10/2)+3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 8);
    
    calc.setExpression("3*(2+4)/2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 9);
    
    calc.setExpression("((2+3)*4)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 20);
    
    calc.setExpression("(5)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
    
    calc.setExpression("((3))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 3);
}

void test_unary_minus_beginning() {
    Calculator calc;
    
    calc.setExpression("-5");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("-5+3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -2);
    
    calc.setExpression("-10+20");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 10);
    
    calc.setExpression("-3*4");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -12);
    
    calc.setExpression("-10/2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
}

void test_unary_minus_in_parentheses() {
    Calculator calc;
    
    calc.setExpression("(-5)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("(2+(-3))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -1);
    
    calc.setExpression("(10+(-5))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
    
    calc.setExpression("5*(-3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -15);
    
    calc.setExpression("10/(-2)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("(-2)*(-3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 6);
    
    calc.setExpression("(-10)/(-2)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
}

void test_unary_minus_after_opening_paren() {
    Calculator calc;
    
    calc.setExpression("-(2+3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("-(10-5)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("-(2*3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -6);
    
    calc.setExpression("-(10/2)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("-(2+(-3))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 1);
    
    calc.setExpression("-(-5)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
    
    calc.setExpression("-(-(2+3))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
}

void test_nested_unary_minus() {
    Calculator calc;
    
    calc.setExpression("-(-(-5))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("(-(-5))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
    
    calc.setExpression("2*(-(-3))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 6);
    
    calc.setExpression("-(-(2+(-3)))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -1);
}

void test_binary_minus_with_negative_numbers() {
    Calculator calc;
    
    calc.setExpression("2-(-3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
    
    calc.setExpression("(-2)-3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == -5);
    
    calc.setExpression("(-2)-(-3)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 1);
    
    calc.setExpression("10-(-5)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 15);
}

void test_invalid_expressions() {
    Calculator calc;
    
    calc.setExpression("3+");
    assert(!calc.validateExpression());
    
    calc.setExpression("5-");
    assert(!calc.validateExpression());
    
    calc.setExpression("+5");
    assert(!calc.validateExpression());
    
    calc.setExpression("*5");
    assert(!calc.validateExpression());
    
    calc.setExpression("/5");
    assert(!calc.validateExpression());
    
    calc.setExpression("(3+)");
    assert(!calc.validateExpression());
    
    calc.setExpression("3+");
    assert(!calc.validateExpression());
    
    calc.setExpression("(5+7/2");
    assert(!calc.validateExpression());
    
    calc.setExpression("3+4)");
    assert(!calc.validateExpression());
    
    calc.setExpression(")(");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2+3))");
    assert(!calc.validateExpression());
    
    calc.setExpression("()");
    assert(!calc.validateExpression());
    
    calc.setExpression("(())");
    assert(!calc.validateExpression());
    
    calc.setExpression("(()())");
    assert(!calc.validateExpression());
    
    calc.setExpression("(()");
    assert(!calc.validateExpression());
    
    calc.setExpression("())");
    assert(!calc.validateExpression());
    
    calc.setExpression("( )");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2+3)4");
    assert(!calc.validateExpression());
    
    calc.setExpression("5(2+3)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2+3)(4+5)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(3())");
    assert(!calc.validateExpression());
    
    calc.setExpression("(()3)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(()+3)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(3+())");
    assert(!calc.validateExpression());
    
    calc.setExpression("2++3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2--3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2*-3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2/-3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2+-3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2-+3");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2+-3)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2-+3)");
    assert(!calc.validateExpression());
    
    calc.setExpression("3+-4");
    assert(!calc.validateExpression());
    
    calc.setExpression("(+-5)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2+(*3))");
    assert(!calc.validateExpression());
    
    calc.setExpression("2.5+3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2a+3");
    assert(!calc.validateExpression());
    
    calc.setExpression("2+3!");
    assert(!calc.validateExpression());
    
    calc.setExpression(")(2+3)");
    assert(!calc.validateExpression());
    
    calc.setExpression("(2+3)(");
    assert(!calc.validateExpression());
}

void test_division_by_zero() {
    Calculator calc;
    
    bool caughtException = false;
    try {
        calc.setExpression("10/0");
        calc.evaluate();
    } catch (const std::runtime_error&) {
        caughtException = true;
    }
    assert(caughtException);
    
    caughtException = false;
    try {
        calc.setExpression("5/(3-3)");
        calc.evaluate();
    } catch (const std::runtime_error&) {
        caughtException = true;
    }
    assert(caughtException);
    
    caughtException = false;
    try {
        calc.setExpression("10/(2-2)");
        calc.evaluate();
    } catch (const std::runtime_error&) {
        caughtException = true;
    }
    assert(caughtException);
}

void test_complex_expressions() {
    Calculator calc;
    
    calc.setExpression("(2+6)/(7-5)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 4);
    
    calc.setExpression("(10+5)*2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 30);
    
    calc.setExpression("5*4-3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 17);
    
    calc.setExpression("(3+5*2)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 13);
    
    calc.setExpression("((2+3)*4-5)/3");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 5);
    
    calc.setExpression("(-(2+3))*-4");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 20);
    
    calc.setExpression("2*(3+(-1))");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 4);
    
    calc.setExpression("(10-(-5))*2");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 30);
    
    calc.setExpression("(-(10-5))*(-2)");
    assert(calc.validateExpression());
    assert(calc.evaluate() == 10);
}

int main() {
    test_simple_expressions();
    test_basic_operations();
    test_operator_precedence();
    test_parentheses();
    test_unary_minus_beginning();
    test_unary_minus_in_parentheses();
    test_unary_minus_after_opening_paren();
    test_nested_unary_minus();
    test_binary_minus_with_negative_numbers();
    test_invalid_expressions();
    test_division_by_zero();
    test_complex_expressions();
    
    std::cout << "All Calculator tests passed!" << std::endl;
    return 0;
}
