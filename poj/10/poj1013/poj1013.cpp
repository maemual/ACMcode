#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAX_LEN = 12;
int map[MAX_LEN+5];
bool maptemp[MAX_LEN+5];
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		memset(map,0,sizeof(map));
		char s1[MAX_LEN],s2[MAX_LEN],s3[MAX_LEN];
		for (int i=0;i<3;i++)
		{
			scanf("%s%s%s",s1,s2,s3);
			if (!strcmp(s3,"even"))
			{
				for (int i=0;i<strlen(s1);i++)
				{
					map[s1[i]-'A'] = 10;
					map[s2[i]-'A'] = 10;
				}
			}else if (!strcmp(s3,"up"))
			{
				memset(maptemp,0,sizeof(maptemp));
				for (int i=0;i<strlen(s1);i++)
				{
					maptemp[s1[i]-'A'] = true;
					maptemp[s2[i]-'A'] = true;
				}
				for (int i=0;i<MAX_LEN;i++)
				{
					if (!maptemp[i])
					  map[i] = 10;
				}
				for (int i=0;i<strlen(s1);i++)
				{
					if (map[s1[i]-'A'] != 10)
					  map[s1[i]-'A']++;
					if (map[s2[i]-'A'] != 10)
					  map[s2[i]-'A']--;
				}
			}else if (!strcmp(s3,"down"))
			{	
				memset(maptemp,0,sizeof(maptemp));
				for (int i=0;i<strlen(s1);i++)
				{
					maptemp[s1[i]-'A'] = true;
					maptemp[s2[i]-'A'] = true;
				}
				for (int i=0;i<MAX_LEN;i++)
				{
					if (!maptemp[i])
					  map[i] = 10;
				}
				for (int i=0;i<strlen(s1);i++)
				{
					if (map[s1[i]-'A'] != 10)
					  map[s1[i]-'A']--;
					if (map[s2[i]-'A'] != 10)
					  map[s2[i]-'A']++;
				}
			}
		}
		int max=-1;
		int maxid = 0;
		for (int i=0;i<MAX_LEN;i++)
		{
			if (map[i] != 10)
			{
				if (max < abs(map[i]))
				{
					max = abs(map[i]);
					maxid = i;
				}
			}
		}
		if (map[maxid] > 0)
		{
			printf("%c is the counterfeit coin and it is heavy.\n",maxid+'A');
		}else
		{
			printf("%c is the counterfeit coin and it is light.\n",maxid+'A');
		}
	}
	return 0;
}
