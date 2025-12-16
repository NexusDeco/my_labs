#ifndef STUDENT_FIRST_SESSION_H
#define STUDENT_FIRST_SESSION_H

#include "base_student.h"

class StudentFirstSession : public BaseStudent {
protected:
    static const int FIRST_SESSION_COURSES = 4;
    int firstSessionGrades[FIRST_SESSION_COURSES];

public:
    StudentFirstSession() = delete;
    StudentFirstSession(const char* name, int course, int group, int recordBook,
                       const int grades[FIRST_SESSION_COURSES]);
    StudentFirstSession(const StudentFirstSession& other);
    
    int getFirstSessionGrade(int index) const;
    void setFirstSessionGrade(int index, int grade);
    const int* getAllFirstSessionGrades() const { return firstSessionGrades; }
    
    double calculateAverage() const override;
    double getFirstSessionAverage() const override;
    bool hasFirstSession() const override { return true; }
    
    virtual void displayInfo(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const StudentFirstSession& student);
};

#endif
