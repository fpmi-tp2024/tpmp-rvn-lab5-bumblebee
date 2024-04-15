#include "../include/date.h"

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year) {}

Date::Date(){
}
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

bool Date::setDay(int newDay) {
    if (newDay < 1 || newDay > 31) {
        return false;
    }

    day = newDay;
    return true;
}

bool Date::setMonth(int newMonth) {
    if (newMonth < 1 || newMonth > 12) {
        return false;
    }

    month = newMonth;
    return true;
}

bool Date::setYear(int newYear) {
    if (newYear < 0) {
        return false;
    }

    year = newYear;
    return true;
}

bool Date::validate() const {
    return day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0;
}

void Date::printInfo() const {
    std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
}