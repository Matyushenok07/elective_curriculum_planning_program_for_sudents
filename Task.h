#pragma once

#include <iostream>
using namespace std;

class Task {
protected:
    int id;
    string name;
public:
    explicit Task(int id = 0, const string &name = "");
    int getId() const;
    void setId(int id);
    const string &getName() const;
    void setName(const string &name);

    friend ostream &operator<<(ostream &os, const Task &task);
    friend istream &operator>>(istream &is, Task &task);
};
/*
- explicit ставится перед конструктором и предотвращает неявное преобразование типов при инициализации
*/