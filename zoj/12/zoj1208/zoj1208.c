/*************************************************************************
	> File Name: zoj1208.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月04日 星期一 16时57分25秒
 ************************************************************************/

#include<stdio.h>

int right[7][7] = {{0},
	{0,0,3,5,2,4,0},
	{0,4,0,1,6,0,3},
	{0,2,6,0,0,1,5},
	{0,5,1,0,0,6,2},
	{0,3,0,6,1,0,4},
	{0,0,4,2,5,3,0},
};
int main()
{
	int top,front;
	int x,y;
	char str[100];
	int p;
	char ch;
	int tmp;
	printf("Problem 2 by team x\n");
	while (scanf("%d %d",&top,&front) != EOF)
	{
		p = 0;
		x = y = 0;
		printf("\n");
		if (right[top][front] == 0)
		{
			printf("Invalid initial orientation:     ");
			printf("top =%2d  front =%2d\n",top,front);
			gets(str);
			continue;
		}
		printf("Initial orientation:             ");
		printf("top =%2d  front =%2d\n",top,front);
		printf("Moves:");
		while ((ch = getchar()) != '\n')
		{
			printf("%c",ch);
			if (ch != ' ')
			{
				switch (ch)
				{
					case 'E':
						x++;
						top = 7 - right[top][front];
						break;
					case 'W':
						x--;
						top = right[top][front];
						break;
					case 'S':
						y--;
						tmp = front;
						front = top;
						top = 7 - tmp;
						break;
					case 'N':
						y++;
						tmp = top;
						top = front;
						front = 7 - tmp;
						break;
					default:break;
				}
			}
		}
		printf("\n");
		printf("Final orientation and position:  top =%2d  front =%2d  x =%4d  y =%4d\n",top,front,x,y);
	}
	printf("End of problem 2 by team x\n");
	return 0;
}
