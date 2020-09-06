#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Queue.h"
#include "QueueException.h"
#include "Input.h"
#include "User.h"
#include "File.h"

template <class T>
class Algorithm {
public:
    static void add(Queue<T>& queue, std::vector<T>& returnPrev, std::vector<int>& action);
    static void remove(Queue<T> &queue, std::vector<T> &returnPrev, std::vector<int> &action);
    static void update(Queue<T> &queue, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place);
    static void sort(Queue<T> &queue);
    static void cancel(Queue<T>& queue, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place);
    static User *authorization();
    static void registration();
    static void giveAdminRole(Queue<T>& queue);
};

template<class T>
void Algorithm<T>::add(Queue<T>& queue, std::vector<T>& returnPrev, std::vector<int>& action) {
    T tmp;
    std::cin >> tmp;
    queue.pushTail(tmp);
    returnPrev.insert(returnPrev.end(), tmp);// помещение элемента tmp в конец очереди 
    action.insert(action.end(), 1);
    system("pause");
}

template<class T>
void Algorithm<T>::remove(Queue<T> &queue, std::vector<T> &returnPrev, std::vector<int> &action) {
    if (queue.size() == 0) {
        throw QueueException(1);
    } 
	else {
        T tmp = queue[0];
        returnPrev.insert(returnPrev.end(), tmp);
        action.insert(action.end(), 2);
        queue.popHead();
    }
    system("pause");
}

template<class T>
void Algorithm<T>::update(Queue<T> &queue, std::vector<T> &returnPrev, std::vector<int> &action, std::vector<int> &place) {
    if (!queue.size()) {
        throw QueueException(1);
    }
    queue.output();
    std::cout << std::endl;
    std::cout << "Введите номер для изменения: ";
    int tempNum = Error::Input::InputNumber(1, queue.size());
    T tmp;
    std::cin >> tmp;
    returnPrev.insert(returnPrev.end(), queue[tempNum - 1]);
    action.insert(action.end(), 3);
    place.insert(place.end(), tempNum);
    queue[tempNum - 1] = tmp;
    system("pause");
}

template<class T>
void Algorithm<T>::sort(Queue<T> &queue) {
    if (!queue.size()) {
        throw QueueException(1);
    }
    queue.output();
    std::cout << std::endl;
    std::cout << "Выберите по какому признаку отсортировать:" << std::endl;
    std::string classname = std::string(typeid(queue[0]).name());
    if (classname == "class Courses") {
        cout << "1. По идентификационному номеру по возрастанию.\n2. По идентификационному номеру по убыванию.\n"
                "3. По названию по возрастанию\n4. По названию по убыванию.\n\n";
        int type = Error::Input::InputNumber(1, 4);
        queue.sort(type);
    } else {
        cout << "1. По фамилии по возрастанию\n2. По фамилии по убыванию.\n\n";
        int type = Error::Input::InputNumber(1, 2);
        queue.sort(type + 2);
    }
}

template<class T>
void Algorithm<T>::cancel(Queue<T>& queue, std::vector<T>& returnPrev, std::vector<int>& action, std::vector<int>& place) {
    if (!action.size()) {
        throw QueueException(2);
    }
    switch (action.back()) {
        case 1: {
            queue.popTail();
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
        case 2: {
            queue.pushHead(returnPrev.back());
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
        case 3: {
            queue[place.back() - 1] = returnPrev.back();
            place.erase(place.end() - 1);
            action.erase(action.end() - 1);
            returnPrev.erase(returnPrev.end() - 1);
            break;
        }
    }
}

template<class T>
User* Algorithm<T>::authorization() {
    Queue<User> users;
    File<User>::openUser(users, "users.txt");
    char BUFFER[20];
    std::string username;
    std::cout << "Введите логин: ";
    std::cin >> username;
    std::cout << "Введите пароль: ";
    int i = 0;
    std::cin >> BUFFER;
    for (int j = 0; BUFFER[j] != '\0'; ++j) {
		BUFFER[j] = 6 * BUFFER[j] - BUFFER[j] / 6;
    }
    std::string password(BUFFER);
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username && users[i].getPassword() == password) {
            return new User(users[i]);
        }
    }
    std::cout << "Неверный пользователь или пароль!" << std::endl;
    return nullptr;
}

template<class T>
void Algorithm<T>::registration() {
    Queue<User> users;
    File<User>::openUser(users, "users.txt");
    User newUser;
    std::cin >> newUser;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == newUser.getUsername() && users[i].getPassword() == newUser.getPassword()) {
            std::cout << "Данный пользователь уже существует!" << std::endl;
            return;
        }
    }
    users.pushTail(newUser);
    File<User>::saveUser(users, "users.txt");
}

template<class T>
void Algorithm<T>::giveAdminRole(Queue<T> &queue) {
    queue.output();
    std::cout << std::endl;
    std::cout << "Введите номер пользователя для предоставления прав администратора : ";
    int tempNum = Error::Input::InputNumber(1, queue.size());
    queue[tempNum - 1].setAdmin(1);
}
