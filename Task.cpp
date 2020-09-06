#include "Task.h"
#include "Input.h"

Task::Task(int id, const string &name) : id(id), name(name) {}

int Task::getId() const {
    return id;
}

void Task::setId(int id) {
    Task::id = id;
}

const string &Task::getName() const {
    return name;
}

void Task::setName(const string &name) {
    Task::name = name;
}

ostream &operator<<(ostream &os, const Task &task) {
    os << "Номер факультатива: " << task.id << endl << "Название: " << task.name << endl;
    return os;
}

istream &operator>>(istream &is, Task &task) {
    cout << "Введите идентификационный номер факультатива: ";
    task.id = Error::Input::InputNumber(0, 1000000);
    cout << "Введите тему задания: ";
    task.name = string(Error::Input::inputStringWithoutNumbers());
    return is;
}
