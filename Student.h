#pragma  once

#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int bYear;
    int numberOfLectures;
public:
    explicit Student(const string &name = "", int bYear = 0, int numberOfLectures = 0);
    const string &getName() const;
    void setName(const string &name);
    int getBYear() const;
    void setBYear(int bYear);
    int getNumberOfLectures() const;
    void setNumberOfLectures(int numberOfLectures);

    friend ostream &operator<<(ostream &os, const Student &student);
    friend istream &operator>>(istream &is, Student &student);

    int getId() const {return 0;};

};
