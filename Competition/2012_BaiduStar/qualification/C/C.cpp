#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	double x;
	while (cin >> x)
	{
		double sum=x;
		for (int i=1;i<12;i++)
		{
			cin >> x;
			sum+=x;
		}
		printf("$%.2f\n",sum/12);
	}
	return 0;
}
