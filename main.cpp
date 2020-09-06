#include <iostream>
#include "windows.h"
#include "User.h"
#include "Interface.h"
#include "Teacher.h"
#include "Courses.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int select;
    User* user = Interface<User>::authorization();
    if (user == nullptr) {
        return 0;
    }
    if (user->isAdmin()) {
        while (true) {
            std::cout << "Выберите данные для работы с ними:" << std::endl;
            std::cout << "1. Студенты." << std::endl;
            std::cout << "2. Преподаватели." << std::endl;
            std::cout << "3. Факультативы." << std::endl;
            std::cout << "4. Выход." << std::endl;
            select = Error::Input::InputNumber(1, 4);
            switch (select) {
                case 1: {
                    Queue<Student> queue;
                    File<Student>::openStudent(queue, "student.txt");
                    Interface<Student>::adminMenu(queue);
                    File<Student>::saveStudent(queue, "student.txt");
                    break;
                }
                case 2:
                {
                    Queue<Teacher> queue;
                    File<Teacher>::openTeacher(queue, "teacher.txt");
                    Interface<Teacher>::adminMenu(queue);
                    File<Teacher>::saveTeacher(queue, "teacher.txt");
                    break;
                }
                case 3:
                {
                    Queue<Courses> queue;
                    File<Courses>::openCourses(queue, "courses.txt");
                    Interface<Courses>::adminMenu(queue);
                    File<Courses>::saveCourses(queue, "courses.txt");
                    break;
                }
                case 4: {
                    return 0;
                }
            }
        }
    } else {
        while (true) {
            std::cout << "Выберите данные для работы с ними:" << std::endl;
            std::cout << "1. Студенты." << std::endl;
            std::cout << "2. Преподаватели." << std::endl;
            std::cout << "3. Факультативы." << std::endl;
            std::cout << "4. Выход." << std::endl;
            select = Error::Input::InputNumber(1, 4);
            switch (select) {
                case 1: {
                    Queue<Student> queue;
                    File<Student>::openStudent(queue, "student.txt");
                    Interface<Student>::menu(queue);
                    File<Student>::saveStudent(queue, "student.txt");
                    break;
                }
                case 2:
                {
                    Queue<Teacher> queue;
                    File<Teacher>::openTeacher(queue, "teacher.txt");
                    Interface<Teacher>::menu(queue);
                    File<Teacher>::saveTeacher(queue, "teacher.txt");
                    break;
                }
                case 3:
                {
                    Queue<Courses> queue;
                    File<Courses>::openCourses(queue, "courses.txt");
                    Interface<Courses>::menu(queue);
                    File<Courses>::saveCourses(queue, "courses.txt");
                    break;
                }
                case 4: {
                    return 0;
                }
            }
        }
    }
    return 0;
}