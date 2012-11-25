#include <stdio.h>
#include <math.h>

#define MAX_BIG 2100000
#define MAX_MAX 9261000000000000000
unsigned long long cube[MAX_BIG];
unsigned long long result[100000][2];
unsigned long long cub(unsigned long long a)
{
	unsigned long long sum = 1;
	unsigned long long i;
	for (i = 0; i < 3; i++)
	  sum *= a;
	return sum;
}
int main()
{
	unsigned long long n;
	unsigned long long i,j;
	for (i = 1; i < MAX_BIG; i++)
	  cube[i] = cub(i);
	while (scanf("%llu",&n) != EOF)
	{
		unsigned long long num = 0;
		unsigned long long min = n>MAX_BIG?MAX_BIG:n;
		for (i = 1; i < min; i++)
		{
			if (cube[i] > n/2+1)
			  break;
			unsigned long long temp = n - cube[i];
			if (temp > MAX_MAX)
			  continue;
			unsigned long long t = (unsigned long long) pow(temp,1.0/3);
			if (t < MAX_BIG && cube[t] == temp && t > i) 
			{
				result[num][0] = i;
				result[num++][1] = t;
			}
			t++;
			if (t < MAX_BIG && cube[t] == temp && t > i)
			{
				result[num][0] = i;
				result[num++][1] = t;
			}
		}
		printf("%d",num);
		for (i = 0; i < num; i++)
		{
			printf(" (%llu,%llu)",result[i][0],result[i][1]);
		}
		printf("\n");
	}
	return 0;

}
