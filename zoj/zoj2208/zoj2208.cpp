#include <cstdio>
#include <cstring>
const int MAX_SIZE = 20;
const int MAX_LEN = 200;
char strmap[MAX_LEN+5][MAX_SIZE+5];
char s[MAX_LEN+5];
int main()
{
	int row,col;
	while (1)
	{
		scanf("%d",&col);
		if (col == 0)
		  break;
		scanf("%s",s);
		int len = strlen(s);
		int k=0;
		row = 0;
		bool flag = false;
		for (int i=0;;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (i%2==0)
					strmap[i][j] = s[k++];
				else 
					strmap[i][col-j-1] = s[k++];
				if (k >= len)
				{  
					flag = true;
					break;
				}
			}
			row++;
			if (flag)
			  break;
		}
		//row++;
		for (int i=0;i<col;i++)
			for (int j=0;j<row;j++)
				 printf("%c",strmap[j][i]);
		printf("\n");
	}
	return 0;
}
