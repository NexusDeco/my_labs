#ifndef STUDENT_SECOND_SESSION_H
#define STUDENT_SECOND_SESSION_H

#include "student_first_session.h"

class StudentSecondSession : public StudentFirstSession {
private:
    static const int SECOND_SESSION_COURSES = 5;
    int secondSessionGrades[SECOND_SESSION_COURSES];

public:
    StudentSecondSession() = delete;
    StudentSecondSession(const char* name, int course, int group, int recordBook,
                        const int firstGrades[FIRST_SESSION_COURSES],
                        const int secondGrades[SECOND_SESSION_COURSES]);
    StudentSecondSession(const StudentSecondSession& other);
    
    // Access methods for grades
    int getSecondSessionGrade(int index) const;
    void setSecondSessionGrade(int index, int grade);
    const int* getAllSecondSessionGrades() const { return secondSessionGrades; }
    
    // Overridden methods
    double calculateAverage() const override;
    bool hasSecondSession() const override { return true; }
    
    virtual void displayInfo(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const StudentSecondSession& student);
};

#endif
