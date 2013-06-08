#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CNT 2
#define MAXSIZE 9
int main()
{
	int cnt;
	scanf("%d",&cnt);
	while( cnt-- )
	{
		char input[CNT][MAXSIZE];
		int  result[CNT] = {0,0};

		scanf("%s",input[0]);
		scanf("%s",input[1]);

		for(int j=0; j<2; j++)
		{
			for(int i=0; i<strlen(input[j]); i++)
			{
				if(isdigit(input[j][i]))
				{
					int temp = atoi(&input[j][i]);
					switch(input[j][++i])
					{
						case 'm':
							result[j] += 1000 * temp;
							break;
						case 'c':
							result[j] += 100 * temp;
							break;
						case 'x':
							result[j] += 10 * temp;
							break;
						case 'i':
							result[j] += temp;
							break;
						default:
							break;
					}
				}else{
					switch(input[j][i])
					{
						case 'm':
							result[j] += 1000 ;
							break;
						case 'c':
							result[j] += 100 ;
							break;
						case 'x':
							result[j] += 10 ;
							break;
						case 'i':
							result[j] += 1;
							break;
						default:
							break;
					}
				}//for if
			}//for i
		}// for j

		int sum = result[0] + result[1];
		char print_sum[MAXSIZE] = {0};
		// converse to print
		int index = 0;
		for(int div=1000; div!=0 ; div/=10)
		{
			if(sum / div)
			{
				if(sum / div != 1)
				{
					print_sum[index++] = sum/div + '0'; 
				}
				switch(div)
				{
					case 1000:
						print_sum[index] = 'm';
							break;
					case 100:
						print_sum[index] = 'c';
							break;
					case 10:
						print_sum[index] = 'x';
							break;
					case 1:
						print_sum[index] = 'i';
							break;
				}

				index ++;
				sum %= div;
			}
		}// for
		printf("%s\n",print_sum);
	}//while
	return 0;
}

