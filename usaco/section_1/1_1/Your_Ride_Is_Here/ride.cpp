/*
 ID: maemual
 TASK: ride
 LANG: C++
 */

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	char s1[7], s2[7];
	scanf("%s", s1);
	scanf("%s", s2);
	int num1, num2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	num1 = num2 = 1;
	for (int i = 0; i < len1; i++)
		num1 *= s1[i] - 'A' + 1;
	for (int i = 0; i < len2; i++)
		num2 *= s2[i] - 'A' + 1;
	if (num1 % 47 == num2 % 47)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}
