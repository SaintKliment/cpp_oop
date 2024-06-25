#include <iostream>
#include <clocale>
#include <string>

using std::string;

class Person {
private: // приватно! только для данного класса и больше никому --> (юзерам, классам насследникам)
    string name, type;
    short age;
    string hobbies[3];

// protected:
//     short age; // доступен в классах наследниках
// class Player final ... ==> класс не имеет насследников

public:
    Person(string name, short age, string type, string* p, short n) {
        this->name = name;
        this->age = age;
        this->type = type;
        for(short i = 0; i < n; i++) {
        hobbies[i] = *(p + i);
        }
    }
    explicit Person(string name, short age, string type) {
        this->name = name;
        this->age = age;
        this->type = type;
    }
};

class Player : public Person {
private:
    string magic_power;
public:
    Player(string name, short age, string type, string magic_power) : Person(name, age, type) {
        this->magic_power = magic_power;
    }
};

class Enemy : public Person {
    
};

int main() {
    setlocale(LC_ALL, "Russian");

    // string hobbies[3] = {"football", "tennis", "basketball"};
    // string* p = hobbies;
    Player user("user1", 32, "player", "heal");
    
    // Enemy user2("user2", 10, "enemy", "lox");


    return 0;
}