#pragma  once

#include <ostream>
#include "Student.h"

class Teacher : public Student {
private:
    int workExperience;
    int numberOFCreatedCourses;
public:
    explicit Teacher(const string &name = "", int bYear = 0, int numberOfLectures = 0,
    int workExperience = 0, int numberOfCreatedCourses = 0);
    int getWorkExperience() const;
    void setWorkExperience(int workExperience);
    int getNumberOfCreatedCourses() const;
    void setNumberOfCreatedCourses(int numberOfCreatedCourses);
    friend ostream &operator<<(ostream &os, const Teacher &teacher);
    friend istream &operator>>(istream &is, Teacher &teacher);
};
