#pragma once
#include <iostream>
#include "Exception.h"
class QueueException : public Exception {
public:
    explicit QueueException(int code = 0) : Exception(code) {};
    void ErrorText() override {
        std::cout << "Ошибка (код " << code << "): " << std::endl;
        switch (code) {
            case 1: {
                std::cout << "Список пуст" << std::endl;
                break;
            }
            case 2: {
                std::cout << "Невозможно отменить действие.";
                std::cout << " Все возможные последние действия cо студентами отменены." << std::endl;
                break;
            }
        }
    };
};
/*
 - explicit ставится перед конструктором и предотвращает неявное преобразование типов при инициализации
 - override -мы создали иерархию классову котрой в базовом классе есть виртуальная функция , чтобы gthtjghtltkbnm t` d ghjbpdjlyjv rkfcct
 для переопределения функции ( почти то же самое что и virtual)
*/