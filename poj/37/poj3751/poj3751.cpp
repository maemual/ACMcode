#include <cstdio>

int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int year,month,day,hour,minite,second;
		scanf("%d/%d/%d-%d:%d:%d",&year,&month,&day,&hour,&minite,&second);
		if (hour>0 && hour <12)
		  printf("%02d/%02d/%04d-%02d:%02d:%02dam\n",month,day,year,hour,minite,second);
		else if (hour>12 && hour<=24)
		  printf("%02d/%02d/%04d-%02d:%02d:%02dpm\n",month,day,year,hour-12,minite,second);
		else if (hour == 0)
		  printf("%02d/%02d/%04d-%02d:%02d:%02dam\n",month,day,year,hour+12,minite,second);
		else if (hour == 12)
		  printf("%02d/%02d/%04d-%02d:%02d:%02dpm\n",month,day,year,hour,minite,second);
	}
	return 0;
}
