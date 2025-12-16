#include "student_second_session.h"
#include <iomanip>
#include <stdexcept>

StudentSecondSession::StudentSecondSession(const char* name, int course, int group, 
                                         int recordBook, const int firstGrades[FIRST_SESSION_COURSES],
                                         const int secondGrades[SECOND_SESSION_COURSES])
    : StudentFirstSession(name, course, group, recordBook, firstGrades) {
    for (int i = 0; i < SECOND_SESSION_COURSES; ++i) {
        if (secondGrades[i] < 0 || secondGrades[i] > 10) {
            throw std::invalid_argument("Grades must be between 0 and 10");
        }
        secondSessionGrades[i] = secondGrades[i];
    }
}

StudentSecondSession::StudentSecondSession(const StudentSecondSession& other)
    : StudentFirstSession(other) {
    for (int i = 0; i < SECOND_SESSION_COURSES; ++i) {
        secondSessionGrades[i] = other.secondSessionGrades[i];
    }
}

int StudentSecondSession::getSecondSessionGrade(int index) const {
    if (index < 0 || index >= SECOND_SESSION_COURSES) {
        throw std::out_of_range("Grade index out of range");
    }
    return secondSessionGrades[index];
}

void StudentSecondSession::setSecondSessionGrade(int index, int grade) {
    if (index < 0 || index >= SECOND_SESSION_COURSES) {
        throw std::out_of_range("Grade index out of range");
    }
    if (grade < 0 || grade > 10) {
        throw std::invalid_argument("Grade must be between 0 and 10");
    }
    secondSessionGrades[index] = grade;
}

double StudentSecondSession::calculateAverage() const {
    double sum = 0;
    
    // Add first session grades
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        sum += firstSessionGrades[i];
    }
    
    // Add second session grades
    for (int i = 0; i < SECOND_SESSION_COURSES; ++i) {
        sum += secondSessionGrades[i];
    }
    
    return sum / (FIRST_SESSION_COURSES + SECOND_SESSION_COURSES);
}

void StudentSecondSession::displayInfo(std::ostream& os) const {
    BaseStudent::displayInfo(os);
    os << "First Session Grades: ";
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        os << firstSessionGrades[i] << " ";
    }
    os << "\nSecond Session Grades: ";
    for (int i = 0; i < SECOND_SESSION_COURSES; ++i) {
        os << secondSessionGrades[i] << " ";
    }
    os << "\nYear Average Score: " 
       << std::fixed << std::setprecision(2) 
       << calculateAverage() << "\n";
}

std::ostream& operator<<(std::ostream& os, const StudentSecondSession& student) {
    student.displayInfo(os);
    return os;
}