#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED
#include <string>

void setTime(int, int, int);
void addHour();
void addSecond();
void addMinute();
std::string get12HourFormat();
std::string get24HourFormat();

std::string pad(int);
std::string getSuffix();

#endif