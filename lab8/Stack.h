#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <algorithm>

template <typename T>
class Stack {
private:
    T* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Stack() : size(0), capacity(10) {
        data = new T[capacity]();
    }

    ~Stack() {
        delete[] data;
    }

    Stack(const Stack& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity]();
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity]();
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push(const T& value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    T pop() {
        if (size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return data[--size];
    }

    T top() const {
        if (size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return data[size-1];
    }

    bool operator==(const Stack& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator<(const Stack& other) const {
        int minSize = std::min(size, other.size);
        for (int i = 0; i < minSize; i++) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return size < other.size;
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    Stack& operator<<(const T& value) {
        push(value);
        return *this;
    }

    Stack& operator>>(T& value) {
        value = pop();
        return *this;
    }

    int getSize() const {
        return size;
    }
    
    bool isEmpty() const {
        return size == 0;
    }
};

#endif
