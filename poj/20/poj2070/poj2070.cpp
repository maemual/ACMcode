#include <cstdio>

int main()
{
	double speed,weight,strength;
	while (1)
	{
		scanf("%lf%lf%lf",&speed,&weight,&strength);
		if (speed==0&weight==0&&strength==0)
		  break;
		bool flag = true;
		if (speed<=4.5&&weight>=150&&strength>=200)
		{
			flag = false;
			printf("Wide Receiver");
		}
		if (speed<=6.0&&weight>=300&&strength>=500)
		{
			if (!flag)
			  printf(" ");
			flag = false;
			printf("Lineman");
		}
		if (speed<=5.0&&weight>=200&&strength>=300)
		{
			if (!flag)
			  printf(" ");
			flag = false;
			printf("Quarterback");
		}
		if (flag)
		  printf("No positions");
		printf("\n");
	}
	return 0;
}
