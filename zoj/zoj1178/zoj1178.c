/*************************************************************************
  > File Name: zoj1178.c
  > Author: maemual
  > Mail: maemual@gmail.com 
  > Created Time: 2013年03月02日 星期六 14时20分55秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAX_LEN 105

struct node{
	int left,right;
}sheet_front[MAX_LEN],sheet_back[MAX_LEN];
int main()
{
	int n;
	int page,sheets,tmp;
	int i;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
			break;
		memset(sheet_front,0,sizeof(sheet_front));
		memset(sheet_back,0,sizeof(sheet_back));

		int sheets = n / 4;
		if (n % 4 != 0)
			sheets++;
		tmp = n;
		page = 1;
		for (i = 1; i <= sheets; i++)
		{
			sheet_front[i].right = page++;
			tmp--;
			if (tmp == 0)
				break;
			sheet_back[i].left = page++;
			tmp--;
			if (tmp == 0)
				break;
		}

		i--;
		if (tmp != 0)
		{
			for (; i >= 1; i--)
			{
				sheet_back[i].right = page++;
				tmp--;
				if (tmp == 0)
					break;
				sheet_front[i].left = page++;
				tmp--;
				if (tmp == 0)
					break;
			}
		}
		printf("Printing order for %d pages:\n",n);
		for (i = 1; i <= sheets; i++)
		{
			if (sheet_front[i].left == 0 && sheet_front[i].right != 0)
				printf("Sheet %d, front: Blank, %d\n",i,sheet_front[i].right);
			else if (sheet_front[i].left != 0 && sheet_front[i].right == 0)
				printf("Sheet %d, front: %d, Blank\n",i,sheet_front[i].left);
			else if (sheet_front[i].left != 0 && sheet_front[i].right != 0)
				printf("Sheet %d, front: %d, %d\n",i,sheet_front[i].left,sheet_front[i].right);

			if (sheet_back[i].left == 0 && sheet_back[i].right != 0)
				printf("Sheet %d, back : Blank, %d\n",i,sheet_back[i].right);
			else if (sheet_back[i].left != 0 && sheet_back[i].right == 0)
				printf("Sheet %d, back : %d, Blank\n",i,sheet_back[i].left);
			else if (sheet_back[i].left != 0 && sheet_back[i].right != 0)
				printf("Sheet %d, back : %d, %d\n",i,sheet_back[i].left,sheet_back[i].right);
		}
	}
	return 0;
}
