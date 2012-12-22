#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char s[100010];
	scanf("%s",s);
	bool b = true;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (b && s[i] == '0')
		{
			b = false;
			continue;
		}
		if (!(b && i == len -1))
		  putchar(s[i]);

	}
	printf("\n");
	return 0;
}
