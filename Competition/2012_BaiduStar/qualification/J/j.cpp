#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,m;
    int *a;
    int *b;
    int i=0;
    int reault=0;
    int j=0;
    int tmp;
    int low=1;
    int high=0;
    scanf("%d%d",&n,&m);
    high=n;
    int mid;
    a=(int *)malloc(sizeof(int)*m);
    b=(int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]); 
    }
    for(i=0;i<m;i++)
    {
        low=1;
        high=n;
        while((high-low)>2)
        {
           mid=(low+high)/2;
           tmp=a[i]*mid-b[i]*(n-mid);
           if(tmp>0)
            {
                 high=mid;      
            }
            else
            {
                 low=mid+1;
            }            
                        
        }
        for(j=low;j<=high;j++)
        {
                 tmp=a[i]*j-b[i]*(n-j);
                 if(tmp>0) 
                 {break;}       
        }     
        if(reault==0)
           reault=tmp;
        else if(reault>tmp)
           reault=tmp;
        else
           reault=reault;
            
    }
    printf("%d",reault);
   return 0;   
}

