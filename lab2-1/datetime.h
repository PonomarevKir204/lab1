#pragma once
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

class datetime
{
private:
    int hour;
    int minute;
    int second;

    int day;
    int month;
    int year;
public:
    void Output();
    void System_time(datetime& system);
    void Get_next_date(datetime& next);
    void Get_prev_date(datetime& prev);

    int Get_hour();
    int Get_minute();
    int Get_second();
    int Get_day();
    int Get_month();
    int Get_year();

    void Set_hour(int hour);
    void Set_minute(int minute);
    void Set_second(int second);
    void Set_day(int day);
    void Set_month(int month);
    void Set_year(int year);
};
