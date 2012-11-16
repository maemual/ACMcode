#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int w,d,count = 1;
	int dec = 5730,result;
	double temp,a = 810,year;
	while(scanf("%d%d",&w,&d)!=EOF && w)
	{
		temp = a*w/d;
		year = dec* log(temp)/log(2);
		if( year <= 10000)
		  result = 100*(int)(year/100 + 0.5);
		else
		  result = 1000*(int)(year/1000 + 0.5);
		printf("Sample #%d\nThe approximate age is %d years.\n\n",count++,result);      
	}
	return 0;
}

