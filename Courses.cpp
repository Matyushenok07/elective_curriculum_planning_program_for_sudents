#include "Courses.h"
#include "Input.h"
#include "File.h"
#include "Queue.h"
#include "Student.h"
#include "Teacher.h"
#include "QueueException.h"

Courses::Courses(int id, const string &name, int numberOfLectures, const string &lecturerName) 
    : Task(id, name), numberOfLectures(numberOfLectures),lecturerName(lecturerName) {}

int Courses::getNumberOfLectures() const {
    return numberOfLectures;
}

void Courses::setNumberOfLectures(int numberOfLectures) {
    Courses::numberOfLectures = numberOfLectures;
}

const string &Courses::getLecturerName() const {
    return lecturerName;
}

void Courses::setLecturerName(const string &lecturerName) {
    Courses::lecturerName = lecturerName;
}

ostream &operator<<(ostream &os, const Courses &courses) {
    os << static_cast<const Task &>(courses) << "Количество занятий, которые ещё нужно провести: " <<
    courses.numberOfLectures << endl << "Фамилия преподавателя: "
       << courses.lecturerName << endl;
    return os;
}

istream &operator>>(istream &is, Courses &courses) {
    is >> static_cast<Task&>(courses);
    cout << "Выберите кто будет вести факультативы: (1. Преподаватель. 2. Студент) ";
    int num = Error::Input::InputNumber(1,2);
    switch(num) {
        case 1:
        {
            Queue<Teacher> queueT;
            File<Teacher>::openTeacher(queueT, "teacher.txt");
            if (!queueT.size()) {
                throw QueueException(1);
            } else {
                queueT.output();
                cout << "Выберите номер преподавателя для проведения факультатива: ";
                num = Error::Input::InputNumber(1, queueT.size());
                courses.lecturerName = queueT[num - 1].getName();
            }
            break;
        }
        case 2:
        {
            Queue<Student> queueS;
            File<Student>::openStudent(queueS, "student.txt");
            if (!queueS.size()) {
                throw QueueException(1);
            } else {
                queueS.output();
                cout << "Выберите номер студента для проведения факультатива: ";
                num = Error::Input::InputNumber(1, queueS.size());
                courses.lecturerName = queueS[num - 1].getName();
            }
            break;
        }
    }
    cout << "Введите количество планируемых занятий на данном факультативе: ";
    courses.numberOfLectures = Error::Input::InputNumber(0, 100000);
    return is;
}
