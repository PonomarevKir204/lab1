#include "datetime.h"

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
    timeinfo.tm_year = A.year - 1900;
    timeinfo.tm_mon = A.month - 1;
    timeinfo.tm_mday = A.day;
    timeinfo.tm_hour = A.hour;
    timeinfo.tm_min = A.minute;
    timeinfo.tm_sec = A.second;
    time_t unix_time = mktime(&timeinfo);
    return unix_time;
}

void Get_normal_time(time_t unix_time, datetime& A)
{
    tm timeinfo;
    localtime_s(&timeinfo, &unix_time);
    A.hour = timeinfo.tm_hour;
    A.minute = timeinfo.tm_min;
    A.second = timeinfo.tm_sec;
    A.day = timeinfo.tm_mday;
    A.month = timeinfo.tm_mon + 1;
    A.year = timeinfo.tm_year + 1900;
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
