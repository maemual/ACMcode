#include<stdio.h>
int main()
{    
    double diameter,s;   
    int n,i=0;
    while(scanf("%lf%d%lf",&diameter,&n,&s),n!=0)
    {
         i++; 
         diameter=3.1415927*diameter/12/5280*n;
         s=diameter/s*60*60;   
         printf("Trip #%d: %.2f %.2f\n",i,diameter,s);
    }
}

