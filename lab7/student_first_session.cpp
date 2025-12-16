#include "student_first_session.h"
#include <iomanip>
#include <stdexcept>

StudentFirstSession::StudentFirstSession(const char* name, int course, int group, 
                                       int recordBook, const int grades[FIRST_SESSION_COURSES])
    : BaseStudent(name, course, group, recordBook) {
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        if (grades[i] < 0 || grades[i] > 10) {
            throw std::invalid_argument("Grades must be between 0 and 10");
        }
        firstSessionGrades[i] = grades[i];
    }
}

StudentFirstSession::StudentFirstSession(const StudentFirstSession& other)
    : BaseStudent(other) {
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        firstSessionGrades[i] = other.firstSessionGrades[i];
    }
}

int StudentFirstSession::getFirstSessionGrade(int index) const {
    if (index < 0 || index >= FIRST_SESSION_COURSES) {
        throw std::out_of_range("Grade index out of range");
    }
    return firstSessionGrades[index];
}

void StudentFirstSession::setFirstSessionGrade(int index, int grade) {
    if (index < 0 || index >= FIRST_SESSION_COURSES) {
        throw std::out_of_range("Grade index out of range");
    }
    if (grade < 0 || grade > 10) {
        throw std::invalid_argument("Grade must be between 0 and 10");
    }
    firstSessionGrades[index] = grade;
}

double StudentFirstSession::calculateAverage() const {
    double sum = 0;
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        sum += firstSessionGrades[i];
    }
    return sum / FIRST_SESSION_COURSES;
}

double StudentFirstSession::getFirstSessionAverage() const {
    return calculateAverage();
}

void StudentFirstSession::displayInfo(std::ostream& os) const {
    BaseStudent::displayInfo(os);
    os << "First Session Grades: ";
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        os << firstSessionGrades[i] << " ";
    }
    os << "\nAverage After First Session: " 
       << std::fixed << std::setprecision(2) 
       << calculateAverage() << "\n";
}

std::ostream& operator<<(std::ostream& os, const StudentFirstSession& student) {
    student.displayInfo(os);
    return os;
}
