//
// Created by ali-masa on 2/21/20.
//

#include "time.h"
#include "scheduler.h"

Time::Time(unsigned long t):time(t) {}

unsigned long Time::getTime() const {
    return time;
}

void Time::now(){
    this->time = Scheduler::currentTime();
}

Time &Time::operator+=(const Time &t) {
    *this = *this + t;
    return *this;
}

Time &Time::operator-=(const Time &t) {
    *this = *this - t;
    return *this;
}

bool Time::operator<(const Time &t) const {
    return time < t.time;
}

bool Time::operator>(const Time &t) const {
    return t < *this;
}

bool Time::operator==(const Time &t) const {
    return !(*this < t) && !(*this > t);
}

bool Time::operator!=(const Time &t) const {
    return (*this < t) || (*this > t);
}

bool Time::operator<=(const Time &t) const {
    return !(*this > t);
}

bool Time::operator>=(const Time &t) const {
    return !(*this < t);
}

Time operator+(const Time &time1, const Time &time2) {
    return Time(time1.time + time2.time);
}

Time operator-(const Time &time1, const Time &time2) {
    return Time(time1.time - time2.time);
}

std::ostream &operator<<(std::ostream &os, Time &time) {
    os << "Time is : " <<time.time;
    return os;
}

