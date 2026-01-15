#include "Stack.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_constructor_and_push() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    assert(s.getSize() == 2);
    assert(s[0] == 10);
    assert(s[1] == 20);
}

void test_pop() {
    Stack<int> s;
    s.push(5);
    s.push(15);
    assert(s.pop() == 15);
    assert(s.pop() == 5);
    assert(s.getSize() == 0);
}

void test_comparison_operators() {
    Stack<int> s1, s2;
    s1.push(1); s1.push(2);
    s2.push(1); s2.push(2);
    assert(s1 == s2);
    
    s2.push(3);
    assert(!(s1 == s2));
    
    Stack<int> s3;
    s3.push(1); s3.push(3);
    assert(s1 < s3);
    
    Stack<int> s4;
    s4.push(2);
    assert(s1 < s4);
}

void test_subscript_operator() {
    Stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    assert(s[0] == 100);
    assert(s[1] == 200);
    assert(s[2] == 300);
    
    bool caughtException = false;
    try {
        s[3];
    } catch (const std::out_of_range&) {
        caughtException = true;
    }
    assert(caughtException);
}

void test_top_operator() {
    Stack<int> s;
    s.push(42);
    assert(s.top() == 42);
    s.push(84);
    assert(s.top() == 84);
    s.pop();
    assert(s.top() == 42);
}

void test_assignment_operator() {
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    Stack<int> s2 = s1;
    assert(s2 == s1);
    
    s2.push(3);
    assert(!(s1 == s2));
}

void test_empty_stack() {
    Stack<int> s;
    bool caughtException = false;
    try {
        s.pop();
    } catch (const std::out_of_range&) {
        caughtException = true;
    }
    assert(caughtException);
    
    caughtException = false;
    try {
        s.top();
    } catch (const std::out_of_range&) {
        caughtException = true;
    }
    assert(caughtException);
}

void test_shift_left_operator() {
    Stack<int> s;
    s << 1 << 2 << 3;
    assert(s.getSize() == 3);
    assert(s[0] == 1);
    assert(s[1] == 2);
    assert(s[2] == 3);
}

void test_shift_right_operator() {
    Stack<int> s;
    s << 10 << 20 << 30;
    
    int a, b, c;
    s >> a >> b >> c;
    assert(a == 30);
    assert(b == 20);
    assert(c == 10);
    assert(s.getSize() == 0);
}

void test_shift_operators_chain() {
    Stack<int> s;
    s << 5 << 15 << 25 << 35;
    
    int x, y, z, w;
    s >> x >> y >> z >> w;
    assert(x == 35);
    assert(y == 25);
    assert(z == 15);
    assert(w == 5);
    assert(s.isEmpty());
}

int main() {
    test_constructor_and_push();
    test_pop();
    test_comparison_operators();
    test_subscript_operator();
    test_top_operator();
    test_assignment_operator();
    test_empty_stack();
    test_shift_left_operator();
    test_shift_right_operator();
    test_shift_operators_chain();
    std::cout << "All Stack tests passed!" << std::endl;
    return 0;
}
