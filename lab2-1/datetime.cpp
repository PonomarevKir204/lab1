#include "datetime.h"

int datetime::Get_hour() {return hour;}
int datetime::Get_minute() {return minute;}
int datetime::Get_second() {return second;}
int datetime::Get_day() {return day;}
int datetime::Get_month() {return month;}
int datetime::Get_year() {return year;}

void datetime::Set_hour(int hour) 
{ 
    if(hour >= 0) 
        this->hour = hour;
}
void datetime::Set_minute(int minute) 
{
    if(minute >= 0) 
        this->minute = minute;
}
void datetime::Set_second(int second)
{ 
    if(second >= 0) 
        this->second = second;
}
void datetime::Set_day(int day)
{ 
    if(day >= 0) 
        this->day = day;
}
void datetime::Set_month(int month)
{ 
    if(month >= 0) 
        this->month = month;
}
void datetime::Set_year(int year)
{ 
    if(year >= 0) 
        this->year = year;
}

void datetime::Output()
{
    printf("%i:%i:%i %i/%i/%i", hour, minute, second, day, month, year);
}

void datetime::System_time(datetime& system)
{
    time_t rawtime;
    tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    system.hour = timeinfo.tm_hour;
    system.minute = timeinfo.tm_min;
    system.second = timeinfo.tm_sec;
    system.day = timeinfo.tm_mday;
    system.month = timeinfo.tm_mon + 1;
    system.year = timeinfo.tm_year + 1900;
}

time_t Get_unix_time(datetime A)
{
    tm timeinfo;
    timeinfo.tm_year = A.Get_year() - 1900;
    timeinfo.tm_mon = A.Get_month() - 1;
    timeinfo.tm_mday = A.Get_day();
    timeinfo.tm_hour = A.Get_hour();
    timeinfo.tm_min = A.Get_minute();
    timeinfo.tm_sec = A.Get_second();
    time_t unix_time = mktime(&timeinfo);
    return unix_time;
}

void Get_normal_time(time_t unix_time, datetime& A)
{
    tm timeinfo;
    localtime_s(&timeinfo, &unix_time);
    A.Set_hour(timeinfo.tm_hour);
    A.Set_minute(timeinfo.tm_min);
    A.Set_second(timeinfo.tm_sec);
    A.Set_day(timeinfo.tm_mday);
    A.Set_month(timeinfo.tm_mon + 1);
    A.Set_year(timeinfo.tm_year + 1900);
}

void datetime::Get_next_date(datetime& next)
{
    int min = 2419200 * 2;
    int max = 31536000;
    Get_normal_time(Get_unix_time(*this) + (min + rand() % (max - min + 1)), next);
}

void datetime::Get_prev_date(datetime& prev)
{
    int min = 2419200 * 2;
    int max = 31536000;
    Get_normal_time(Get_unix_time(*this) - (min + rand() % (max - min + 1)), prev);
}

