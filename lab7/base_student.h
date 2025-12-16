#ifndef BASE_STUDENT_H
#define BASE_STUDENT_H

#include <iostream>
#include <cstring>

class BaseStudent {
protected:
    static int nextID;
    const int studentID;
    char* fullName;
    int currentCourse;
    int groupNumber;
    const int recordBookID;

    void copyName(const char* name);

public:
    BaseStudent() = delete;
    BaseStudent(const char* name, int course, int group, int recordBook);
    BaseStudent(const BaseStudent& other);
    virtual ~BaseStudent();

    int getStudentID() const { return studentID; }
    const char* getFullName() const { return fullName; }
    int getCurrentCourse() const { return currentCourse; }
    int getGroupNumber() const { return groupNumber; }
    int getRecordBookID() const { return recordBookID; }

    void setFullName(const char* name);
    void setCurrentCourse(int course);
    void setGroupNumber(int group);

    virtual double calculateAverage() const { return 0.0; }
    virtual void displayInfo(std::ostream& os) const;
    virtual bool hasFirstSession() const { return false; }
    virtual bool hasSecondSession() const { return false; }
    virtual double getFirstSessionAverage() const { return 0.0; }

    friend std::ostream& operator<<(std::ostream& os, const BaseStudent& student);
};

#endif
