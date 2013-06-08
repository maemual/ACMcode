#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	char ch;
	int m;
	int i,j;
	int sum;
	while (1)
	{
		scanf("%s",s);
		if (!strcmp(s,"#"))
		  break;
		sum = 0;
		while (1)
		{
			if (!strcmp(s,"0"))
			  break;
			scanf("%s",s);
			scanf("%d %c",&m,&ch);
			if (ch == 'F')
			{
				sum += m * 2;
			}else if (ch == 'B')
			{
				sum += (int) m * 1.5;
			}else if (ch == 'Y')
			{
				if (m < 500)
				  sum += 500;
				else
				  sum += m;
			}
			scanf("%s",s);
		}
		printf("%d\n",sum);
	}
	return 0;
}
