#include <cstdio>
const int MAX_LEN = 5842;
int humble[MAX_LEN+5];
int min(int a,int b,int c,int d)
{
	if (a>b)
	  a = b;
	if (a>c)
	  a = c;
	if (a>d)
	  a = d;
	return a;
}
int main()
{
	int p2=1,p3=1,p5=1,p7=1;
	humble[1] = 1;
	for (int i=2;i<=MAX_LEN;i++)
	{
		humble[i]=min(humble[p2]*2,humble[p3]*3,humble[p5]*5,humble[p7]*7);
		if (humble[i] == humble[p2]*2)
		  p2++;
		if (humble[i] == humble[p3]*3)
		  p3++;
		if (humble[i] == humble[p5]*5)
		  p5++;
		if (humble[i] == humble[p7]*7)
		  p7++;
	}
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n==0)
		  break;
		printf("The %d",n);
		if(n % 10 == 1){
			if(n % 100 == 11)
			  printf("th");
			else
			  printf("st");
		}
		else if(n % 10 == 2){
			if(n % 100 == 12)
			  printf("th");
			else
			  printf("nd");
		}
		else if(n % 10 == 3){
			if(n % 100 == 13)
			  printf("th");
			else
			  printf("rd");
		}
		else
		  printf("th");
		printf(" humble number is %d.\n",humble[n]);
	}
	return 0;
}
