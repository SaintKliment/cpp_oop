#include <iostream>
#include <clocale>
#include <string>

using std::string;

class Person {
public:
    string name;
    short age;
    bool isHappy;
    string hobbies[3];

    void set_data(string name, short age, bool isHappy);
    void set_hobbies(string* p, short n);
    void get_data();
};


int main() {
    setlocale(LC_ALL, "Russian");

    Person user1;
    user1.name = "zhenya";
    user1.age = 10;
    user1.isHappy = true;

    Person* p_user1 = &user1;
    std::cout  << "TEST P0INTER NAME = " << p_user1->name << std::endl;

    Person user2;
    user1.name = "petya";
    user1.age = 20;
    user1.isHappy = false;

    Person user3;
    user3.set_data("vasya", 43, true);
    string hobbies[3] = {"football", "basketball", "regbi"};
    string* p = hobbies;
    user3.set_hobbies(p, 3);
    user3.get_data();

    Person* max = new Person;
    max->isHappy = true;
    max->set_data("Max", 50, max->isHappy);
    std::cout << max->name << "\t" << max->isHappy << std::endl;
    delete max;

    return 0;
}


void Person::set_data(string name, short age, bool isHappy) {
        this->name = name;
        this->age = age;
        this->isHappy = isHappy;
    }

void Person::set_hobbies(string* p, short n) {
    for(short i = 0; i < n; i++) {
        hobbies[i] = *(p + i);
    }

}

void Person::get_data() {
    std::cout << "Name: " << name << std::endl << "Age: " << age << std::endl << "IsHappy: " << isHappy << std::endl;
    std::cout << "Hobbies: ";
    for(short i = 0; i < 3; i++) {
    std::cout << hobbies[i] << ", ";
    }
    std::cout << std::endl;
}