#include <iostream>

class TimeDay {
    unsigned long time{0};
public:
    TimeDay() : time(0) { }
    TimeDay(unsigned char hs, unsigned char ms, unsigned char ss, unsigned int ds = 0) : time(ss + ms * 60 + hs * 3600 + ds * 86400) { }
    TimeDay(unsigned long tm) : time(tm) { } // конструктор преобразования ( создает временный обьект для числа стр 35)

    void get_time(unsigned int& days, unsigned char& hours, unsigned char& mins, unsigned char& secs) const {
        secs = time % 60;
        mins = time / 60 % 60;
        hours = time / 3600 % 24;
        days = time / 86400;
    }

    unsigned long get_time() const { return time; }

    // TimeDay operator+(const TimeDay& right) const { возвращает обьект
    //     return TimeDay(this->time + right.time);
    // }

    // unsigned long operator+(const TimeDay& right) const { // возвращает число
    //     return(this->time + right.time);
    // }
};

unsigned long operator+(const TimeDay& left, const TimeDay& right) {
    return left.get_time() + right.get_time();
} 

int main() {
    TimeDay t1(10, 45, 13), t2(4, 11, 50);
    // TimeDay res = t1 + t2; // equi t1.operator+(t2);
    // TimeDay res = t1 + 10;
    TimeDay res = 10 + t1;

    unsigned d;
    unsigned char h, m, s;

    res.get_time(d, h, m, s);
    printf("%u: %02u:%02u:%02u \n", d, h, m ,s);

    return 0;
}