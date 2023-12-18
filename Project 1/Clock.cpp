#include "Clock.h"

int hours;
int minutes;
int seconds;

void setTime(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

std::string pad(int value)
{
	if (value >= 0 && value <= 9) {
		//if the number is between 0 and 9, add a leading '0'
		return "0" + std::to_string(value);
	}
	else {
		//if the number is not a single number, then just converting to string
		return std::to_string(value);
	}
}

std::string getSuffix()
{
	return std::string();
}

void addHour() 
{
	//checking if the hours is between 0 and 23
	if (hours >= 0 && hours <= 22) {
		//Increment the hour by 1 and set it as a new hours
		hours += 1;
	}
	else if (hours == 23) {
		//if the hour is 23, then will set hour back to zero
		hours = 0;
	}
}
void addMinute()
{
	//checking if the minutes is between 0 and 58
	if (minutes >= 0 && minutes <= 58) {
		//increment the minutes
		minutes += 1;
	}
	//if the minutes is 59 then set it to 0 and call the addHour function
	else if (minutes == 59) {
		minutes = 0;
		addHour();
	}
}


void addSecond()
{
	//checking is the seconds is between 0 and 58, then increment to 1
	if (seconds >= 0 && seconds <= 58) {
		seconds += 1;
	}
	// if seconds is 59 then set seconds to zero and call the addMinute method
	else if (seconds ==59) {
		seconds = 0;
		addMinute();
	}
}

std::string get12HourFormat()
{
	std::string dayOrNight;
	//copying the original hours to avoid modification and the 24-format stays 24-hormat
	int adjustedHours = hours;
	//dayTime AM
	if (adjustedHours < 12) {
		dayOrNight = "AM";
		//converting 24hour 00:00:00 to 12:00:00 AM
		if (adjustedHours == 0) {
			adjustedHours = 12;
		}
	}
	//night time PM
	else {
		dayOrNight = "PM";
		//converting 24-hour format to 12-hour so instead of 13:00:00 it will be 1:00:00 PM
		if (adjustedHours > 12) {
			adjustedHours -= 12;
		}
	}
	//Formatting as two digit strings 
	std::string formattedTime = pad(adjustedHours) + ":" + pad(minutes) + ":" + pad(seconds) + " " + dayOrNight;

	return formattedTime;
}

std::string get24HourFormat()
{
	//formatting as two digit strings
	return std::string(pad(hours) + ":" + pad(minutes) + ":" + pad(seconds));
}


