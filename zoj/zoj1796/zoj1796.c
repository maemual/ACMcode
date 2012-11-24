#include <stdio.h>

int main()
{
	int aw,al,bw,bl,cw,cl;
	while (1)
	{
		scanf("%d %d %d %d %d %d",&aw,&al,&bw,&bl,&cw,&cl);
		if (aw==0 && al==0 && bw==0 && bl==0 && cw==0 && cl==0)
		  break;
		printf("Anna's won-loss record is %d-%d.\n",(aw+al)*2-(aw+bw+cw),(aw+al)*2-(al+bl+cl));
	}
	return 0;
}
