#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool setDay(int newDay);
    bool setMonth(int newMonth);
    bool setYear(int newYear);
    bool validate() const;
    void printInfo() const;
};

#endif  // DATE_H