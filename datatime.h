#pragma once
#include <iostream>

using namespace std;

struct datatime
{
	int create(int number, int minute, int hour, int day, int month, int year, int second);
	int  number, minute, hour, day, month, year, second;
	int print();

};

struct list
{
	datatime* back;
	datatime* next;
	datatime* prev;

	list();
};
