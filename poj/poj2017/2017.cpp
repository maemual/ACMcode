#include <stdio.h>

int main()
{
  int i,n;
  int speed,time,hour,mile;
  while (1)
    {
      scanf("%d",&n);
      if (n == -1)
	break;
      speed=time=hour=mile=0;
      for (i=0;i<n;i++)
	{
	  scanf("%d%d",&speed,&hour);
	  mile+=speed*(hour-time);
	  time=hour;
	}
      printf("%d miles\n",mile);
    }
  return 0;
}
