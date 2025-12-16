#include <iostream>
#include <iomanip>
#include "student_second_session.h"

double calculateGroupAverageAfterFirstSession(BaseStudent** studentsArray, 
                                            int arraySize, int targetGroup) {
    double totalSum = 0;
    int studentCount = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        if (studentsArray[i]->getGroupNumber() == targetGroup && 
            studentsArray[i]->hasFirstSession()) {
            totalSum += studentsArray[i]->getFirstSessionAverage();
            studentCount++;
        }
    }
    
    return studentCount > 0 ? totalSum / studentCount : 0.0;
}

double calculateGroupAverageAfterSecondSession(BaseStudent** studentsArray, 
                                             int arraySize, int targetGroup) {
    double totalSum = 0;
    int studentCount = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        if (studentsArray[i]->getGroupNumber() == targetGroup && 
            studentsArray[i]->hasSecondSession()) {
            totalSum += studentsArray[i]->calculateAverage();
            studentCount++;
        }
    }
    
    return studentCount > 0 ? totalSum / studentCount : 0.0;
}

double calculateOverallAverage(BaseStudent** studentsArray, int arraySize) {
    double totalSum = 0;
    int count = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        if (studentsArray[i]->hasFirstSession() || studentsArray[i]->hasSecondSession()) {
            totalSum += studentsArray[i]->calculateAverage();
            count++;
        }
    }
    
    return count > 0 ? totalSum / count : 0.0;
}

int main() {
    try {
        // Create students
        BaseStudent student1("Ivanov Ivan", 1, 101, 1001);
        
        int firstSessionGrades1[4] = {8, 9, 7, 8};
        StudentFirstSession student2("Petrov Petr", 1, 101, 1002, firstSessionGrades1);
        
        int firstSessionGrades2[4] = {9, 10, 8, 9};
        StudentFirstSession student3("Sidorov Alexey", 1, 102, 1003, firstSessionGrades2);
        
        int secondSessionGrades1[4] = {7, 8, 6, 7};
        int secondSessionGrades2[5] = {8, 9, 7, 8, 9};
        StudentSecondSession student4("Kozlova Maria", 1, 101, 1004, 
                                     secondSessionGrades1, secondSessionGrades2);
        
        int secondSessionGrades3[4] = {10, 10, 9, 10};
        int secondSessionGrades4[5] = {9, 10, 10, 9, 10};
        StudentSecondSession student5("Smirnov Dmitry", 1, 102, 1005,
                                     secondSessionGrades3, secondSessionGrades4);
        
        // Display all students
        std::cout << "=== All Students Information ===\n";
        std::cout << "Student 1 (BaseStudent):\n" << student1 << std::endl;
        std::cout << "Student 2 (After First Session):\n" << student2 << std::endl;
        std::cout << "Student 3 (After First Session):\n" << student3 << std::endl;
        std::cout << "Student 4 (After Second Session):\n" << student4 << std::endl;
        std::cout << "Student 5 (After Second Session):\n" << student5 << std::endl;
        
        // Demonstrate set methods
        std::cout << "\n=== Demonstrating Set Methods ===\n";
        student1.setFullName("Ivanov I.I.");
        student1.setCurrentCourse(2);
        student2.setFirstSessionGrade(0, 10);
        student4.setSecondSessionGrade(0, 9);
        
        std::cout << "After modifications:\n";
        std::cout << student1 << std::endl;
        std::cout << student2 << std::endl;
        
        // Create array of pointers for group calculations
        BaseStudent* allStudents[] = {&student1, &student2, &student3, &student4, &student5};
        int totalStudents = sizeof(allStudents) / sizeof(allStudents[0]);
        
        // Calculate group averages
        std::cout << "\n=== Group Averages ===\n";
        std::cout << std::fixed << std::setprecision(2);
        
        std::cout << "Group 101 after first session: " 
                  << calculateGroupAverageAfterFirstSession(allStudents, totalStudents, 101) << std::endl;
        
        std::cout << "Group 101 after two sessions: " 
                  << calculateGroupAverageAfterSecondSession(allStudents, totalStudents, 101) << std::endl;
        
        std::cout << "Group 102 after first session: " 
                  << calculateGroupAverageAfterFirstSession(allStudents, totalStudents, 102) << std::endl;
        
        std::cout << "Group 102 after two sessions: " 
                  << calculateGroupAverageAfterSecondSession(allStudents, totalStudents, 102) << std::endl;
        
        // Calculate overall average
        std::cout << "\n=== Overall Average ===\n";
        std::cout << "Overall average for all students with grades: " 
                  << calculateOverallAverage(allStudents, totalStudents) << std::endl;
        
        // Demonstrate polymorphism
        std::cout << "\n=== Polymorphism Demonstration ===\n";
        for (int i = 0; i < totalStudents; ++i) {
            std::cout << allStudents[i]->getFullName() << ": ";
            std::cout << "Type: ";
            if (dynamic_cast<StudentSecondSession*>(allStudents[i])) {
                std::cout << "StudentSecondSession";
            } else if (dynamic_cast<StudentFirstSession*>(allStudents[i])) {
                std::cout << "StudentFirstSession";
            } else {
                std::cout << "BaseStudent";
            }
            std::cout << ", Average: " << allStudents[i]->calculateAverage() << std::endl;
        }
        
        // Demonstrate exception handling
        std::cout << "\n=== Exception Handling Demonstration ===\n";
        try {
            student2.setFirstSessionGrade(10, 5); // Invalid index
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        try {
            student4.setSecondSessionGrade(2, 15); // Invalid grade
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
