#pragma once
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

struct datetime
{
    int hour;
    int minute;
    int second;

    int day;
    int month;
    int year;

    void Output();
    void System_time(datetime& system);
    void Get_next_date(datetime& next);
    void Get_prev_date(datetime& prev);
};

