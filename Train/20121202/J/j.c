#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100005
#define MAX 105
int main()
{
	char str[MAX_LEN];
	char ans1[MAX],ans2[MAX];
	int len;
	ans1[0] = '\0';
	int i;
	while (1)
	{
		gets(str);
	//	printf("%s\n",str);
		int i = 0,j = 0;
		len = strlen(str);
		for (i = 0; i < len; )
		{
			while (j <= len && (isalpha(str[j]) || str[j] == '-')) 
			  j++;
			if (j - i > strlen(ans2))
			{
				int k;
				for (k = 0; k < j - i; k++)
				{
					ans1[k] = str[k+i];
				}
				ans1[j-i] = '\0';
				if (strcmp(ans1,"E-N-D"))
				  strcpy(ans2,ans1);
			}
			while (j <= len && !isalpha(str[j]) && str[j] != '-') 
			  j++;
			i = j;
		}
		if (len >= 5)
		{
			if (str[len-1] == 'D' && str[len-2] == '-' && str[len-3] == 'N'
				&& str[len-4] == '-' && str[len-5] == 'E')
			{
			//	if (!strcmp(ans,"E-N-D"))
			//	  break;
				for (i = 0; i < strlen(ans2);i++)
				  printf("%c",tolower(ans2[i]));
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
