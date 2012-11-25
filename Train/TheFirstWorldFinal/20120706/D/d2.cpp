#include <cstdio>
#include <cstring>
int main()
{
	int a,b;
	char s[40];
	scanf("%d:%d",&a,&b);
	getchar();
	gets(s);
	printf("%02d:%02d %s\n",a,b,s);
	return 0;
}
