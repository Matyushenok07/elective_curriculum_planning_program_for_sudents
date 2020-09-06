#include "Student.h"
#include "Input.h"

Student::Student(const string &name, int bYear, int numberOfLectures) : name(name), bYear(bYear), numberOfLectures(numberOfLectures) {}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

int Student::getBYear() const {
    return bYear;
}

void Student::setBYear(int bYear) {
    Student::bYear = bYear;
}

int Student::getNumberOfLectures() const {
    return numberOfLectures;
}

void Student::setNumberOfLectures(int numberOfLectures) {
    Student::numberOfLectures = numberOfLectures;
}

ostream &operator<<(ostream &os, const Student &student) {
    cout << "Фамилия: " << student.name << endl << "Год рождения:" << student.bYear << endl << "Количество "
            "проведённых факультативов: " << student.numberOfLectures << endl;
    return os;
}

istream &operator>>(istream &is, Student &student) {
    cout << "Введите фамилию преподавателя факультатива: ";
    student.name = std::string(Error::Input::inputStringWithoutNumbers());
    cout << "Введите год рождения: ";
    student.bYear = Error::Input::InputNumber(1900, 2019);
    cout << "Введите количество факультативов, которые провёл данный студент/преподаватель: ";
    student.numberOfLectures = Error::Input::InputNumber(0, 1000000);
    return is;
}
