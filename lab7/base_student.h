#ifndef BASE_STUDENT_H
#define BASE_STUDENT_H

#include <iostream>

class BaseStudent {
protected:
    static int nextID;
    const int studentID;
    char* fullName;
    int currentCourse;
    int groupNumber;
    const int recordBookID;

    BaseStudent() = delete;

public:
    BaseStudent(const char* name, int course, int group, int recordBook);
    BaseStudent(const BaseStudent& other);
    virtual ~BaseStudent();

    int getStudentID() const;
    const char* getFullName() const;
    int getCurrentCourse() const;
    int getGroupNumber() const;
    int getRecordBookID() const;

    void setFullName(const char* name);
    void setCurrentCourse(int course);
    void setGroupNumber(int group);

    virtual double calculateAverage() const;
    
    virtual void displayInfo(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const BaseStudent& student);

protected:
    void copyFullName(const char* source);
};

#endif
