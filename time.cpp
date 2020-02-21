//
// Created by ali-masa on 2/21/20.
//

#include "time.h"
#include "scheduler.h"

Time::Time(unsigned long t):m_time(t) {}

unsigned long Time::getTime() const {
    return m_time;
}

void Time::now(){
    *this = Scheduler::currentTime();
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
    return this->m_time < t.m_time;
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
    return Time(time1.m_time + time2.m_time);
}

Time operator-(const Time &time1, const Time &time2) {
    return Time(time1.m_time - time2.m_time);
}

std::ostream &operator<<(std::ostream &os, Time &time) {
    os << "Time is : " << time.m_time;
    return os;
}

