#include <cstdio>
int cc[4]={0,5,3,1};
int main()
{
	int sum = 0;
	int a,b,c,d,e,f;
	while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f) != EOF)
	{
		if (a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
		  break;
		sum = d + e +f + (c+3)/4;
		int bb = 5*d+ cc[c%4];
		if (b>bb)
		  sum += (b-bb+8)/9;
		int aa = sum*36 - f*36 - e*25 - d*16 - c*9 - b*4;
		if (a>aa)
		  sum += (a-aa+35)/36;
		printf("%d\n",sum);
	}
	return 0;
}
