#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
  int t,i;
  float xx,yy;
  float dd;
  int year;
  scanf("%d",&t);
  for (i=1;i<=t;i++)
    {
      scanf("%f%f",&xx,&yy);
      dd=sqrt(pow(xx,2)+pow(yy,2));
      year=(int) (PI*pow(dd,2)/100+1);
      printf("Property %d: This property will begin eroding in year %d.\n",i,year);
    }
  printf("END OF OUTPUT.\n");
  return 0;
}
