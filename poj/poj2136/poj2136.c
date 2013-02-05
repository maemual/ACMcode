#include <stdio.h>
#include <string.h>

int main()
{
	int num[30]={0};
	char ch;
	int cnt = 0;
	int i;
	while (1)
	{
		ch = getchar();
		if (ch == '\n')
		  cnt++;
		if (cnt == 4)
		  break;
		if (ch >= 'A' && ch <= 'Z')
		  num[ch - 'A']++;
	}
	int max = 0;
	int pos = 0;
	for (i = 0; i < 26; i++)
	{
		if (num[i] > max)
			max = num[i];
	}
	while (max > 0)
	{
		for (i = 0; i < 26; i++)
		{
			if (num[i] >= max)
			  printf("*");
			else
			  printf(" ");
			if (i != 25)
			  printf(" ");
		}
		printf("\n");
		max--;
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	return 0;
}
