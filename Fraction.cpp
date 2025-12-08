#include "Fraction.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

static int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен 0");
    }
    
    int g = gcd(numerator, denominator);
    if (g != 0) {
        numerator /= g;
        denominator /= g;
    }
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
        throw std::invalid_argument("Знаменатель не может быть равен 0");
    }
    reduce();
}

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

int Fraction::getNumerator() const { 
    return numerator; 
}

int Fraction::getDenominator() const { 
    return denominator; 
}

Fraction Fraction::add(const Fraction& other) const {
    int n = numerator * other.denominator + other.numerator * denominator;
    int d = denominator * other.denominator;
    return Fraction(n, d);
}

Fraction Fraction::multiply(const Fraction& other) const {
    int n = numerator * other.numerator;
    int d = denominator * other.denominator;
    return Fraction(n, d);
}

Fraction Fraction::divide(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Деление на ноль");
    }
    int n = numerator * other.denominator;
    int d = denominator * other.numerator;
    return Fraction(n, d);
}

void Fraction::print() const {
    if (denominator == 1) {
        std::cout << numerator;
    } else if (numerator == 0) {
        std::cout << 0;
    } else {
        std::cout << numerator << "/" << denominator;
    }
}