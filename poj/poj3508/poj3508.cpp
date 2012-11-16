#include <cstdio>
#include <cstring>

char str[1000005];
int n[1000005];
int ret[1000005];

int main()
{
    int c=0;
    while(scanf("%s",str))
    {
        int len;
        ++c;
        if(strcmp(str,"0")==0)
           break;
        len=strlen(str);
        //for(int i=len-1;i>=0;i--)
        //  n[len-1-i]=str[i]-'0';
        
		ret[0]=n[0];
        for(int i=1;i<len-1;i++)
        {   
            if(n[i]-ret[i-1]>=0)
               ret[i]=n[i]-ret[i-1];
            else
            {
               ret[i]=n[i]-ret[i-1]+10;
               n[i+1]-=1; 
            }
            n[i]=ret[i-1];
        }
        if(n[len-1]-ret[len-2]>=0)
           ret[len-1]=n[len-1]-ret[len-2];
        else
           ret[len-1]=n[len-1]-ret[len-2]+10;
        n[len-1]=ret[len-2];
        n[len]=ret[len-1];
        bool flag=true;
        for(int i=0;i<len;i++)
          if(n[i+1]!=ret[i])
             flag=false;
        if(flag&&ret[len-1])
        {
          printf("%d. ",c);
          for(int i=len-1;i>=0;i--)
             printf("%d",ret[i]);
          printf("\n");
        }
        else
          printf("%d. IMPOSSIBLE\n",c);
    }
}
