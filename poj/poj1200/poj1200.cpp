#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_LEN = 20000000;
bool hash[MAX_LEN];
int map[30];
char s[MAX_LEN+5];
int main()
{
	int n,nc;
	while (scanf("%d%d",&n,&nc) != EOF)
	{
		memset(hash,0,sizeof(hash));
		memset(map,0,sizeof(map));
		scanf("%s",s);
		
		//string st="";
		int k=0;
		int len=strlen(s);
		for (int i=0;i<len;i++)
		{
			if (map[s[i]-'a'] == 0)
			{
				map[s[i]-'a'] = k++;
			}
			if (k == nc)
				break;
		}
		int cnt = 0;
		for (int i=0;i<=len-n;i++)
		{
			//st = "";
			int sum = 0;
			for (int j=0;j<n;j++)
			{
				sum = sum*nc+map[s[i+j]-'a'];
			}
			//printf("%d\n",sum);
			if (hash[sum] == false)
			{
				hash[sum] = true;
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
