/*
 ID: maemual
 PROB: friday
 LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int week[8];
int day1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day2[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y){
	if ((y%400==0)||(y%4==0&&y%100!=0))
		return true;
	return false;
}
int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);

	int n;
	scanf("%d", &n);
	memset(week, 0, sizeof(week));
	int w = -1;
	for (int year = 1900; year <= 1900 + n - 1; year++){
		for (int month = 1; month <= 12; month++){
			int d = isLeap(year)?day1[month]:day2[month];
			for (int day = 1; day <= d; day++){
				w = (w + 1) % 7;
				if (day == 13){
					week[w]++;
				}
			}
		}
	}
	printf("%d %d", week[5], week[6]);
	for (int i = 0; i < 5; i++){
		printf(" %d", week[i]);
	}
	printf("\n");
	return 0;
}
