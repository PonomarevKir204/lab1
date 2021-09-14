#include <iostream>
#include "datatime.h"
using namespace std;
int main()
	{ 
		int n = 5;
		cin >> n;
		datatime* arr = new datatime[n];
		for(int i=0; i < n; i++)
			{
			arr[i].create(i+1, 1, 2, 3, 4, 5, i + 2020);
			arr[i].print();
				}



		return 0;

	}