#pragma once

#include <vector>
#include <iomanip>
#include "User.h"
#include "Queue.h"
#include "File.h"
#include "Algorithm.h"

template<class T>
class Interface {
public:
    static void menu(Queue<T>& queue);
    static void adminMenu(Queue<T>& queue);
    static User* authorization();
};


template<class T>
void Interface<T>::menu(Queue<T>& queue) {
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<int> place;
    int select = 0;
    do {
        std::cout << "Вас приветствует система по проведению факультативов!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить студента/преподавателя/факультатив в систему" << std::endl;
        std::cout << "2. Посмотреть список студентов/преподавателей/факультатива" << std::endl;
        std::cout << "3. Удалить первого студента/преподавателя/факультатив из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретном студенте/преподавателе/факультативе" << std::endl;
        std::cout << "5. Отмена предыдущего действия" << std::endl;
        std::cout << "6. Отсортировать список" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = Error::Input::InputNumber(0, 6);
            switch (select) {
                case 1: //Добавить студента/преподавателя/факультатив
                {
                    Algorithm<T>::add(queue, ReturnPrev, action);
                    break;
                }
                case 2: //Посмотреть список студентов/преподавателей/факультативов
                {
                    if (queue.size() == 0) {
                        throw QueueException(1);
                    } else {
                        queue.output();
                        std::cout << std::endl;
                    }
                    break;
                }
                case 3: //Удалить первого студента/преподавателя/факультатив из системы
                {
                    Algorithm<T>::remove(queue, ReturnPrev, action);
                    break;
                }
                case 4: //Изменить данные о конкретном студенте/преподавателе/факультативе
                {
                    Algorithm<T>::update(queue, ReturnPrev, action, place);
                    break;
                }
                case 5: //Отмена предыдущего действия со студентом/преподавателем/факультативов
                {
                    Algorithm<T>::cancel(queue, ReturnPrev, action, place);
                    break;
                }
                case 6: //Отсортировать список студентов/преподавателей/факультативов
                {
                    Algorithm<T>::sort(queue);
                    break;
                }
            }
        }
        catch (QueueException e) {
            e.ErrorText();
            std::cin.sync();
            std::cin.clear();
            rewind(stdin);
        }
    } while (select != 0);
}

template<class T>
User *Interface<T>::authorization() {
    int select = 0;
    do {
        //system("cls");
        std::cout << "Авторизация в систему проведения факультативов!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Авторизация в систему" << std::endl;
        std::cout << "2. Регистрация нового пользователя" << std::endl;
        std::cout << "3. Выход из системы" << std::endl;
        select = Error::Input::InputNumber(1, 3);
        switch (select) {
            case 1: {
                User *currentUser = Algorithm<User>::authorization();
                if (currentUser != nullptr) {
                    return currentUser;
                }
                break;
            }
            case 2: {
                Algorithm<User>::registration();
                break;
            }
            case 3: exit(0);
        }
    } while (select != 3);
    return nullptr;
}

template<class T>
void Interface<T>::adminMenu(Queue<T>& queue) {
    Queue<User> userQueue;
    File<User>::openUser(userQueue, "users.txt");
    std::vector<T> ReturnPrev;
    std::vector<int> action;
    std::vector<User> ReturnPrevForUsers;
    std::vector<int> actionOfUsers;
    std::vector<int> place;
    int select = 0;
    do {
        //system("cls");
        std::cout << "Вас приветствует система по проведению факультативов!" << std::endl;
        std::cout << "Выберите действие, которое хотите совершить : " << std::endl;
        std::cout << "1. Добавить студента/преподавателя/факультатив в систему" << std::endl;
        std::cout << "2. Посмотреть список студентов/преподавателей/факультатива" << std::endl;
        std::cout << "3. Удалить первого студента/преподавателя/факультатив из системы" << std::endl;
        std::cout << "4. Изменить данные о конкретном студенте/преподавателе/факультативе" << std::endl;
        std::cout << "5. Отмена предыдущего действия" << std::endl;
        std::cout << "6. Отсортировать список" << std::endl;
        std::cout << "7. Добавить пользователя" << std::endl;
        std::cout << "8. Просмотреть список пользователей" << std::endl;
        std::cout << "9. Удалить пользователя" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        try {
            select = Error::Input::InputNumber(0, 9);
            switch (select) {
                case 1:
                {
                    //system("cls");
                    Algorithm<T>::add(queue, ReturnPrev, action);
                    break;
                }
                case 2:
                {
                    //system("cls");
                    if (queue.size() == 0) {
                        throw QueueException(1);
                    } else {
                        queue.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 3:
                {
                    //system("cls");
                    Algorithm<T>::remove(queue, ReturnPrev, action);
                    break;
                }
                case 4:
                {
                    //system("cls");
                    Algorithm<T>::update(queue, ReturnPrev, action, place);
                    break;
                }
                case 5:
                {
                    //system("cls");
                    Algorithm<T>::cancel(queue, ReturnPrev, action, place);
                    break;
                }
                case 6:
                {
                    //system("cls");
                    Algorithm<T>::sort(queue);
                    break;
                }
                case 7: {
                    //system("cls");
                    Algorithm<User>::add(userQueue, ReturnPrevForUsers, actionOfUsers);
                    break;
                }
                case 8: {
                    //system("cls");
                    if (userQueue.size() == 0) {
                        throw QueueException(1);
                    } else {
                        userQueue.output();
                        std::cout << std::endl;
                        system("pause");
                    }
                    break;
                }
                case 9: {
                    //system("cls");
                    Algorithm<User>::remove(userQueue, ReturnPrevForUsers, actionOfUsers);
                    break;
                }
            }
        }
        catch (QueueException e) {
            e.ErrorText();
            system("pause");
            std::cin.sync();
            std::cin.clear();
            rewind(stdin);
        }
    } while (select != 0);
}

