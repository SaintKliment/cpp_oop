#include <iostream>
#include <clocale>
#include <string>

using std::string;
class Person {
private:
    short secret_key;
public:
    string name;
    short age;
    bool isHappy;
    string hobbies[3];

    Person(string name, short age, bool isHappy) {
        this->name = name;
        this->age = age;
        this->isHappy = isHappy;
    }
    Person() {}
    Person(string name, short age, bool isHappy, string* p, short n) {
        this->name = name;
        this->age = age;
        this->isHappy = isHappy;
        for(short i = 0; i < n; i++) {
        hobbies[i] = *(p + i);
        }
    }
    
    Person& increase_age(short age) {
        this->age += age;
        return *this;
    }

    ~Person() {
        std::cout << "Person " << name << " is deleted!" << std::endl;
    }
    
    void get_hobbies();
    void view_age();
    void set_secret_key(short secret_key);
    void view_secret_key();

};

int main() {
    setlocale(LC_ALL, "Russian");

    Person user = Person("olyx", 35, false);
    
    Person fake_user = Person();

    string hobbies[3] = {"football", "basketball", "regbi"};
    string* p = hobbies;
    Person full_user = Person("xylo", 53, true, p, 3);
    
    full_user.get_hobbies();

    full_user.increase_age(19).increase_age(1000);
    full_user.view_age();
    full_user.set_secret_key(17361);
    full_user.view_secret_key();


    return 0;
}

void Person::get_hobbies() {
    for(short i = 0; i < 3; i++) {
    std::cout << hobbies[i] << "\t";
    }
    std::cout << "\n";
}

void Person::view_age() {
    std::cout << "age = " << age << "\n";
}
void Person::set_secret_key(short secret_key) {
    this->secret_key = secret_key;
}
void Person::view_secret_key() {
    std::cout << "SECRET_KEY = " << secret_key << "\n";
}