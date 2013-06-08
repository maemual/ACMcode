/*************************************************************************
	> File Name: zoj1710.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月04日 星期一 17时48分10秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int day;
	double height;
	double H,D,U,F;
	int flag;
	while (1)
	{
		scanf("%lf %lf %lf %lf",&H,&U,&D,&F);
		if (H == 0)
			break;
		day = 0;
		height = 0;
		F = U * F / 100;;
		while (1)
		{
			height += U;
			day++;
			if (height > H)
			{
				printf("success on day %d\n",day);
				break;
			}
			U = U - F;
			if (U < 0)
				U = 0;
			height -= D;
			if (height < 0)
			{
				printf("failure on day %d\n",day);
				break;
			}
		}
	}
	return 0;
}
