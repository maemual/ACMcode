#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
bool state[5];
int start=-1;
char str[110]="p";
bool val()
{
	int p,q;
	switch(str[++start])
	{
	case 'A':p=val();q=val();return p||q;
	case 'K':p=val();q=val();return p&&q;
	case 'N':return !val();
	case 'C':p=val();q=val();return !p||q;
	case 'E':return val()==val();
	default:return state[str[start]-'p'];
	}
}
int main()
{	
	//freopen("in.txt","r",stdin);
	while(~scanf("%s",str) && str[0]!='0')
	{
		bool res=1;
		for(int i=0;i<=1;i++)
		{
			state[0]=i;
			for(int j=0;j<=1;j++)
			{
				state[1]=j;
				for(int k=0;k<=1;k++)
				{
					state[2]=k;
					for(int l=0;l<=1;l++)
					{
						state[3]=l;
						for(int m=0;m<=1;m++)
						{
							state[4]=m;
							start=-1;
							res = res&&val();
						//	if(!res) 
						//		break;
						}
					}
				}
			}
		}
		puts(res?"tautology":"not");
	}
}
