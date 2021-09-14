#include "datatime.h"

int datatime::print()
{
	std::cout << "number" << number << std::endl;
	std::cout << "data" << day << ':' << month << ":" << year << std::endl;
	return 0;
	
}
	int datatime::create(int number, int minute, int hour, int day, int month, int year, int second)
{
	this->number = number;
	this->minute = minute;
	this->hour = hour;
	this->day = day;
	this->month = month;
	this->year = year;
	this->second = year;
		return 0;
};

