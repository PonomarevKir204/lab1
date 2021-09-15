#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "datetime.h"

using namespace std;

datetime* Read_file_date(string file_name, int& n)
{
    ifstream file(file_name);
    string line;
    n = 0;
    while (getline(file, line))
    {
        n++;
    }
    datetime* Date = new datetime[n];
    int i = 0;
    file.clear();
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        istringstream line_(line);
        line_ >> Date[i].hour >> Date[i].minute >> Date[i].second >> Date[i].day >> Date[i].month >> Date[i].year;
        i++;
    }
    file.close();
    return Date;
}

int main()
{
    srand(time(0));
    datetime date, next, prev;
    int n;
    datetime* Date = Read_file_date("data.txt", n);
    datetime* Prev = new datetime[n];
    date.System_time(date); printf("\n\nSystem time: "); date.Output();
    printf("\n\n\tData read from file:\n\n");
    for (int i = 0; i < n; i++)
    {
        Date[i].Get_next_date(next);
        Date[i].Get_prev_date(prev);
        printf("%i)\t", i + 1);
        Date[i].Output(); 
        printf("\t");
        next.Output();
        printf("\t");
        prev.Output();
        printf("\n");
        Prev[i] = prev;
    }
  
    delete[] Date;
    delete[] Prev;
    return 0;
}