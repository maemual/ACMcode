#include <stdio.h>

int main()
{
  float i,n,aver;
  aver=0;
  for (i=0;i<12;i++)
    {
      scanf("%f",&n);
      aver+=n / 12;
    }
  printf("$%.2f\n",(int) (aver*100+0.5)/ 100.0);
  return 0;
}
