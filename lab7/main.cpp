#include <iostream>
#include <iomanip>
#include "student_second_session.h"

double calculateGroupAverageAfterFirstSession(StudentFirstSession** studentsArray, 
                                            int arraySize, int targetGroup) {
    double totalSum = 0;
    int studentCount = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        if (studentsArray[i]->getGroupNumber() == targetGroup) {
            totalSum += studentsArray[i]->calculateAverage();
            studentCount++;
        }
    }
    
    return studentCount > 0 ? totalSum / studentCount : 0.0;
}

double calculateGroupAverageAfterSecondSession(StudentSecondSession** studentsArray, 
                                             int arraySize, int targetGroup) {
    double totalSum = 0;
    int studentCount = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        if (studentsArray[i]->getGroupNumber() == targetGroup) {
            totalSum += studentsArray[i]->calculateAverage();
            studentCount++;
        }
    }
    
    return studentCount > 0 ? totalSum / studentCount : 0.0;
}

double calculateOverallAverage(BaseStudent** studentsArray, int arraySize) {
    double totalSum = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        totalSum += studentsArray[i]->calculateAverage();
    }
    
    return arraySize > 0 ? totalSum / arraySize : 0.0;
}

int main() {
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
    
    std::cout << "=== All Students Information ===\n";
    std::cout << student1 << std::endl;
    std::cout << student2 << std::endl;
    std::cout << student3 << std::endl;
    std::cout << student4 << std::endl;
    std::cout << student5 << std::endl;
    
    student1.setFullName("Ivanov I.I.");
    student1.setCurrentCourse(2);
    student2.setFirstSessionGrade(0, 10);
    student4.setSecondSessionGrade(0, 9);
    
    StudentFirstSession* firstSessionArray[2] = {&student2, &student3};
    StudentSecondSession* secondSessionArray[2] = {&student4, &student5};
    
    std::cout << "\n=== Group Averages ===\n";
    std::cout << "Group 101 after first session: " 
              << std::fixed << std::setprecision(2)
              << calculateGroupAverageAfterFirstSession(firstSessionArray, 2, 101) << std::endl;
    
    std::cout << "Group 101 after two sessions: " 
              << calculateGroupAverageAfterSecondSession(secondSessionArray, 2, 101) << std::endl;
    
    std::cout << "Group 102 after first session: " 
              << calculateGroupAverageAfterFirstSession(firstSessionArray, 2, 102) << std::endl;
    
    std::cout << "Group 102 after two sessions: " 
              << calculateGroupAverageAfterSecondSession(secondSessionArray, 2, 102) << std::endl;
    
    BaseStudent* allStudentsArray[5] = {&student1, &student2, &student3, &student4, &student5};
    
    std::cout << "\n=== Overall Average ===\n";
    std::cout << "Overall average: " << calculateOverallAverage(allStudentsArray, 5) << std::endl;
    
    std::cout << "\n=== Polymorphism Demonstration ===\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << allStudentsArray[i]->getFullName() << ": " 
                  << allStudentsArray[i]->calculateAverage() << std::endl;
    }
    
    return 0;
}
