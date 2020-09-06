#pragma once
#include <iostream>

template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
};

template <class T>
class Queue {
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int amount = 0;
public:
    Queue() {};
    ~Queue();

    //Длина списка
    int size() { return this->amount; }
    void pushHead(T obj);
    void pushTail(T input_object);
    T popHead();
    T popTail();
    T& operator[](int num);
    Node<T>* begin();
    Node<T>* end();
    void sort(int type);
    void output();
    void deleteAll();
};

template<class T>
void Queue<T>::pushHead(T obj) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
    } else {
        auto *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->previous = nullptr;
        head->previous = node;
        head = node;
        amount++;
    }
}

//Добавление в конец
template<class T>
void Queue<T>::pushTail(T input_object) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = input_object;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    amount++;
}

//Удаление от головы
template<class T>
T Queue<T>::popHead() {
    if (!(head)) return T();
    T data = head->data;
    Node<T>* node = head;
    if (head != tail) {
        head = head->next;
        head->previous = nullptr;
        Node<T>* tmp = head;
    } 
	else 
	{
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

//Удаление из конца
template<class T>
T Queue<T>::popTail() {
    if (!(head)) return T();
    T data = tail->data;
    Node<T> *node = tail;
    if (tail != head) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& Queue<T>::operator[](int num) {
    Node<T> *curr = head;
    if (num < 0 || num >= amount) return curr->data;
    for (int i = 0; i < num; i++)
        curr = curr->next;
    return curr->data;
}

// Функции для работы с итератором
template<class T>
Node<T>* Queue<T>::begin() { return head; }

template<class T>
Node<T>* Queue<T>::end() {
    if (tail != nullptr) return tail->next;
    return tail;
}

// Вывод на экран содержимого списка
template<class T>
void Queue<T>::output() {
    int i = 0;
    for (Node<T> *node = head; node != nullptr; node = node->next) {
        std::cout << "|№" << i + 1 << std::endl << node->data;
        std::cout << std::endl;
        i++;
    }
}



template<class T>
Queue<T>::~Queue() { while (this->head) { this->popHead(); } }

template<class T>
void Queue<T>::sort(int type) {
    switch (type) {
        case 1: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getId() > another->data.getId()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 2: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getId() < another->data.getId()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 3: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getName() > another->data.getName()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 4: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getName() < another->data.getName()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
    }
}

template<class T>
void Queue<T>::deleteAll() {
    while (this->head) { this->popHead(); }
}


