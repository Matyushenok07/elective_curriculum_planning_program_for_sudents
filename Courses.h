#pragma  once

#include <ostream>
#include "Task.h"

class Courses : public Task {
private:
    int numberOfLectures;
    string lecturerName;
public:
    explicit Courses(int id = 0, const string &name = "", int numberOfLectures = 0, const string &lecturerName = "");

    int getNumberOfLectures() const;
    void setNumberOfLectures(int numberOfLectures);
    const string &getLecturerName() const;
    void setLecturerName(const string &lecturerName);

    friend ostream &operator<<(ostream &os, const Courses &courses);
    friend istream &operator>>(istream &is, Courses &courses);
};
