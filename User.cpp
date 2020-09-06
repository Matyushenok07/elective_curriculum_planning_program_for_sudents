#include <cmath>
#include "User.h"

User::User(std::string username, std::string password, bool admin) : username(username), password(password) , admin(admin) {
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    this->username = username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    this->password = password;
}

bool User::isAdmin() const {
    return admin;
}

void User::setAdmin(bool admin) {
    User::admin = admin;
}

std::ostream &operator<<(std::ostream &os, const User &User) {
    os << "Имя пользователя: " << User.username << std::endl << "Пароль: " << User.password << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, User &User) {
    rewind(stdin);
    std::cout << "Введите имя пользователя: ";
    is >> User.username;
    std::cout << "Введите пароль: ";
    char* BUFFER = new char[20];
    is >> BUFFER;
    for (int j = 0; BUFFER[j] != '\0'; ++j) {
        BUFFER[j] = 6 * BUFFER[j] - BUFFER[j] / 6;
    }
    User.password = std::string(BUFFER);
    User.admin = false;
    return is;
}

User &User::operator=(const User &User) {
    this->username = User.username;
    this->password = User.password;
    this->admin = User.admin;
    return *this;
}
