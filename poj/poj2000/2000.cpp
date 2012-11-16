#include <stdio.h>

int main()
{
  int day[10001];
  int i,j,t,n,sum;
  for (i=1;i<=10000;i++)
    day[i]=0;
  day[1]=1;
  i=2;
  j=2;
  while (i<=10000)
    {
      for (t=1;t<=j;t++)
	{
	  if (i<=10000)
	    day[i]=j;
	  i++;
	}
      j++;
    }
  while (1)
    {
      scanf("%d",&n);
      if (n==0)
	break;
      sum=0;
      for (i=1;i<=n;i++)
	sum+=day[i];
      printf("%d %d\n",n,sum);
    }
  return 0;
}
