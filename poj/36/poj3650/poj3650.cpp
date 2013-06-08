#include <cstdio>
int main()
{
	char ch;
	while (1)
	{
		scanf("%c",&ch);
		if (ch == '#')
		  break;
		switch (ch)
		{
			case ' ':printf("%%20");break;
			case '!':printf("%%21");break;
			case '$':printf("%%24");break;
			case '%':printf("%%25");break;
			case '(':printf("%%28");break;
			case ')':printf("%%29");break;
			case '*':printf("%%2a");break;
			default:printf("%c",ch);break;
		}
	}
	return 0;
}
