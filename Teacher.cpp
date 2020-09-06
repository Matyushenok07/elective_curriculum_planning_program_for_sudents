#include "Teacher.h"
#include "Input.h"

Teacher::Teacher(const string &name, int bYear, int numberOfLectures, int workExperience, int numberOfCreatedCourses) :
    Student(name, bYear, numberOfLectures), workExperience(workExperience),numberOFCreatedCourses(numberOfCreatedCourses) {}

int Teacher::getWorkExperience() const {
    return workExperience;
}

void Teacher::setWorkExperience(int workExperience) {
    Teacher::workExperience = workExperience;
}

int Teacher::getNumberOfCreatedCourses() const {
    return numberOFCreatedCourses;
}

void Teacher::setNumberOfCreatedCourses(int numberOfCreatedCourses) {
    numberOFCreatedCourses = numberOfCreatedCourses;
}

ostream &operator<<(ostream &os, const Teacher &teacher) {
    os << static_cast<const Student &>(teacher) << "Опыт работы: " << teacher.workExperience << endl
    << "Количество составленных факультативов: " << teacher.numberOFCreatedCourses << endl;
    return os;
}

istream &operator>>(istream &is, Teacher &teacher) {
    is >> static_cast<Student&>(teacher);
    cout << "Введите опыт работы: ";
    teacher.workExperience = Error::Input::InputNumber(0, 100);
    cout << "Введите количество разработанных факультативов: ";
    teacher.numberOFCreatedCourses = Error::Input::InputNumber(0, 1000000);
    return is;
}
