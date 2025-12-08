#include "student_first_session.h"
#include <iomanip>
#include <stdexcept>

StudentFirstSession::StudentFirstSession(const char* name, int course, int group, 
                                       int recordBook, const int grades[FIRST_SESSION_COURSES])
    : BaseStudent(name, course, group, recordBook) {
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
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
        return -1;
    }
    return firstSessionGrades[index];
}

void StudentFirstSession::setFirstSessionGrade(int index, int grade) {
    if (index >= 0 && index < FIRST_SESSION_COURSES && grade >= 0 && grade <= 10) {
        firstSessionGrades[index] = grade;
    }
}

double StudentFirstSession::calculateAverage() const {
    double sum = 0;
    for (int i = 0; i < FIRST_SESSION_COURSES; ++i) {
        sum += firstSessionGrades[i];
    }
    return sum / FIRST_SESSION_COURSES;
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