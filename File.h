#pragma once

#include "Queue.h"
#include <iomanip>
#include <fstream>
using namespace std;

template<class T>
class File {
public:
	static void openUser(Queue<T>& queue, const char* file);
	static void openStudent(Queue<T>& queue, const char* file);
	static void openTeacher(Queue<T>& queue, const char* file);
	static void openCourses(Queue<T>& queue, const char* file);

	static void saveUser(Queue<T>& queue, const char* file);
	static void saveStudent(Queue<T>& queue, const char* file);
	static void saveTeacher(Queue<T>& queue, const char* file);
	static void saveCourses(Queue<T>& queue, const char* file);
};


template<class T>
void File<T>::openUser(Queue<T> &queue, const char *file) {
	ifstream in;
	in.open(file);
	if (!in.is_open()) {
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	int val3;
	string val1, val2;
	while (EOF) {
		int i = 0;
		in >> val1;
		if (!in || val1 == "%") {
			break;
		}
		in >> val2 >> val3;
		T t(val1, val2, val3);
		queue.pushTail(t);
	}
	in.close();
}

template<class T>
void File<T>::saveUser(Queue<T> &queue, const char *file) {
	ofstream on;
	on.open(file, ios_base::out);
	if (!on.is_open()) {
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < queue.size(); i++) {
		on << setw(20) << queue[i].getUsername() << setw(20) << queue[i].getPassword() << setw(20) << queue[i].isAdmin();
		on << endl;
	}
	on << "%";
	on.close();
}

template<class T>
void File<T>::openStudent(Queue<T> &queue, const char *file) {
	ifstream in;
	in.open(file);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	int val2, val3;
	string val1;
	while (EOF) {
		int i = 0;
		in >> val1;
		if (!in || val1 == "%") {
			break;
		}
		in >> val2 >> val3;
		T t(val1, val2, val3);
		queue.pushTail(t);
	}
	in.close();
}

template<class T>
void File<T>::openTeacher(Queue<T> &queue, const char *file) {
	std::ifstream in;
	in.open(file);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	int val2, val3, val4, val5;
	string val1;
	while (EOF) {
		int i = 0;
		in >> val1;
		if (!in || val1 == "%") {
			break;
		}
		in >> val2 >> val3 >> val4 >> val5;
		T t(val1, val2, val3, val4, val5);
		queue.pushTail(t);
	}
	in.close();
}

template<class T>
void File<T>::openCourses(Queue<T> &queue, const char *file) {
	ifstream in;
	in.open(file);
	if (!in.is_open()) {
		std::cout << "Невозможно открыть файл!" << std::endl;
		return;
	}
	int val1, val3;
	string val2, val4;
	while (EOF) {
		int i = 0;
		in >> val1;
		if (!in) {
			break;
		}
		in >> val2 >> val3 >> val4;
		T t(val1, val2, val3, val4);
		queue.pushTail(t);
	}
	in.close();
}

template<class T>
void File<T>::saveStudent(Queue<T> &queue, const char *file) {
	ofstream on;
	on.open(file, ios_base::out);
	if (!on.is_open()) {
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < queue.size(); i++) {
		on << setw(20) << queue[i].getName() << setw(20) << queue[i].getBYear() << setw(20) << queue[i].getNumberOfLectures();
		on << endl;
	}
	on << "%";
	on.close();
}

template<class T>
void File<T>::saveTeacher(Queue<T> &queue, const char *file) {
	ofstream on;
	on.open(file, ios_base::out);
	if (!on.is_open()) {
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < queue.size(); i++) {
		on << setw(20) << queue[i].getName() << setw(20) << queue[i].getBYear() << setw(20) <<
			queue[i].getNumberOfLectures() << setw(20) << queue[i].getWorkExperience() << setw(20) << queue[i].getNumberOfCreatedCourses();
		on << endl;
	}
	on << "%";
	on.close();
}

template<class T>
void File<T>::saveCourses(Queue<T> &queue, const char *file) {
	ofstream on;
	on.open(file, ios_base::out);
	if (!on.is_open()) {
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < queue.size(); i++) {
		on << setw(20) << queue[i].getId() << setw(20) << queue[i].getName() <<
			setw(20) << queue[i].getNumberOfLectures() << setw(20) << queue[i].getLecturerName();
		on << endl;
	}
	on << "%";
	on.close();
}