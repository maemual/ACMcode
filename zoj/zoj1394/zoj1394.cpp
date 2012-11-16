#include <cstdio>
#include <cstring>
const double PI = 3.14159;
int main()
{
	char s[20];
	int x,y,z;
	while (scanf("%s",s) != EOF)
	{
		if (!strcmp(s,"ENDOFINPUT"))
		  break;
		scanf("%d%d%d",&x,&y,&z);
		scanf("%s",s);

		if (z>180)
		  z = 360-z;
		double length = 2*x*z*PI/180;
		if (length>5*y)
			printf("NO %d\n",5*y);
		else
			printf("YES %d\n",(int)(y-length/5));
	}
	return 0;
}
