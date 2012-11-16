#include <cstdio>
#include <cstring>
const int MAX_LEN = 200;
char s[MAX_LEN+5];
char map[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
int main()
{
	char st[MAX_LEN+5];
	while (1)
	{
		scanf("%s",st);
		if (!strcmp(st,"ENDOFINPUT"))
		  break;
		getchar();
		gets(s);	
		scanf("%s",st);
		int len=strlen(s);
		for (int i=0;i<len;i++)
		{
			if (s[i]>='A' && s[i]<='Z')
			{
				printf("%c",map[s[i]-'A']);
			}else 
				printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
