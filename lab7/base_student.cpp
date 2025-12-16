#include "base_student.h"
#include <stdexcept>

int BaseStudent::nextID = 1000;

BaseStudent::BaseStudent(const char* name, int course, int group, int recordBook)
    : studentID(nextID++), currentCourse(course), groupNumber(group), recordBookID(recordBook) {
    if (!name || strlen(name) == 0) {
        throw std::invalid_argument("Name cannot be empty");
    }
    if (course < 1 || course > 6) {
        throw std::invalid_argument("Course must be between 1 and 6");
    }
    if (group < 100 || group > 999) {
        throw std::invalid_argument("Group must be between 100 and 999");
    }
    copyName(name);
}

BaseStudent::BaseStudent(const BaseStudent& other)
    : studentID(nextID++), currentCourse(other.currentCourse), 
      groupNumber(other.groupNumber), recordBookID(other.recordBookID) {
    copyName(other.fullName);
}

BaseStudent::~BaseStudent() {
    delete[] fullName;
}

void BaseStudent::copyName(const char* name) {
    if (name) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    } else {
        fullName = new char[1];
        fullName[0] = '\0';
    }
}

void BaseStudent::setFullName(const char* name) {
    if (!name || strlen(name) == 0) {
        throw std::invalid_argument("Name cannot be empty");
    }
    delete[] fullName;
    copyName(name);
}

void BaseStudent::setCurrentCourse(int course) {
    if (course < 1 || course > 6) {
        throw std::invalid_argument("Course must be between 1 and 6");
    }
    currentCourse = course;
}

void BaseStudent::setGroupNumber(int group) {
    if (group < 100 || group > 999) {
        throw std::invalid_argument("Group must be between 100 and 999");
    }
    groupNumber = group;
}

void BaseStudent::displayInfo(std::ostream& os) const {
    os << "Student ID: " << studentID << "\n"
       << "Name: " << fullName << "\n"
       << "Course: " << currentCourse << "\n"
       << "Group: " << groupNumber << "\n"
       << "Record Book ID: " << recordBookID << "\n";
}

std::ostream& operator<<(std::ostream& os, const BaseStudent& student) {
    student.displayInfo(os);
    return os;
}
