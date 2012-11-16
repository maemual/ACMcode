#include <stdio.h>
#include <string.h>
#define MAX_LEN 70

char plaincode[100],ciphercode[100];
int main()
{
	int n,k;
	int i;
	while (1)
	{
		scanf("%d",&k);
		if (k == 0)
		  break;
		scanf("%s",plaincode);
		n = strlen(plaincode);
		for (i = 0; i < n; i++)
		{
			switch (plaincode[i])
			{
				case '_' : plaincode[i] = 0;break;
				case '.' : plaincode[i] = 27;break;
				default  : plaincode[i] = plaincode[i] - 'a' + 1;break;
			}
			ciphercode[k * i % n] = (plaincode[i] + i) % 28;
		}
		for (i = 0; i < n; i++)
		{
			switch (ciphercode[i])
			{
				case 0	: ciphercode[i] = '_';break;
				case 27	: ciphercode[i] = '.';break;
				default	: ciphercode[i] = ciphercode[i] + 'a' - 1;
			}
		}
		for (i = 0; i < n; i++)
		  printf("%c",ciphercode[i]);
		printf("\n");
	}
	return 0;
}
