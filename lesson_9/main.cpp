#include <iostream>

class Singleton {
    int data { 0 };
    static Singleton* instance_ptr;

    Singleton() = default;
public:
    Singleton(const Singleton& ) = delete;
    ~Singleton() { instance_ptr = nullptr; }

    static Singleton* get_instance() {
        if (instance_ptr == nullptr) { instance_ptr = new Singleton(); }
        return instance_ptr;
    }

    void set_data(int d ) {data = d;}
    int get_data() { return data; }
};

Singleton* Singleton::instance_ptr = nullptr;

int main() {

    Singleton* s = Singleton::get_instance();
    s->set_data(1);
    Singleton* s2 = Singleton::get_instance();

    std::cout << s->get_data() << "\t" << s2->get_data() << std::endl;

    delete s;

    return 0;
}