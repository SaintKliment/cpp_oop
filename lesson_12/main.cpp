#include <iostream>

class TimeDay {
    unsigned long time{0};
    friend class Clock;
public:
    TimeDay() : time(0) { }
    TimeDay(unsigned char hs, unsigned char ms, unsigned char ss, unsigned int ds = 0) : time(ss + ms * 60 + hs * 3600 + ds * 86400) { }
    TimeDay(unsigned long tm) : time(tm) { } 

    void get_time(unsigned int& days, unsigned char& hours, unsigned char& mins, unsigned char& secs) const {
        secs = time % 60;
        mins = time / 60 % 60;
        hours = time / 3600 % 24;
        days = time / 86400;
    }

    unsigned long get_time() const { return time; }
    friend unsigned long operator+(const TimeDay& left, const TimeDay& right);
};

class Clock {
public:
    void show_time(const TimeDay& t) {
        unsigned char secs = t.time % 60;
        unsigned char mins = t.time / 60 % 60;
        unsigned char hours = t.time / 3600 % 24;

        printf("%02u:%02u:%02u \n", hours, mins, secs);
    }
};

unsigned long operator+(const TimeDay& left, const TimeDay& right) {
    return left.time + right.time;
} 

int main() {
    TimeDay t1(10, 45, 13), t2(4, 11, 50);
    TimeDay res = 10 + t1;

    Clock c;
    c.show_time(res);

    return 0;
}