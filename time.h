//
// Created by ali-masa on 2/21/20.
//

#ifndef OS_SCHEDULER_TIME_H
#define OS_SCHEDULER_TIME_H
class Time {

    friend Time operator+(const Time& time1, const Time& time2);
    friend Time operator-(const Time& time1, const Time& time2);

public:
    Time(unsigned long t = 0);

    unsigned long getTime() const ;

    void now() const;

    Time& operator+=(const Time& t);
    Time& operator-=(const Time& t);

    bool operator<(const Time& t) const ;
    bool operator>(const Time& t) const ;
    bool operator==(const Time& t) const ;
    bool operator!=(const Time& t) const ;
    bool operator<=(const Time& t) const ;
    bool operator>=(const Time& t) const ;

private:
    unsigned long time;
};
#endif //OS_SCHEDULER_TIME_H
