#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int hh[100500],mm[100500],ss[100500];
char s[1000];
double speed[100500],lu[100500];
int main()
{
    int i = 1,j;
    memset(s,'\0',sizeof(s));
    while (gets(s))
    {
        hh[i]=(s[0]-'0')*10 + (s[1]-'0');
        mm[i]=(s[3]-'0')*10 + (s[4]-'0');
        ss[i]=(s[6]-'0')*10 + (s[7]-'0');
        lu[1] = 0;
        int sumt;
        if(s[8]==' ')
        {
            int l = strlen(s);
            int k;
            speed[i]=0;
            for(k=9;k<l;k++)
            {
                speed[i]*=10;
                speed[i]+=(s[k]-'0');
            }
            if(i > 1)
            {
                sumt = (hh[i]-hh[i-1])*3600 + (mm[i]-mm[i-1])*60 + (ss[i]-ss[i-1]);
                lu[i] = sumt * speed[j]/3.6 + lu[i-1];
            }
            j=i;
            i++;
            memset(s,'\0',sizeof(s));
            continue;
        }
        else
        {
            if(i > 1)
            {
                sumt = (hh[i]-hh[i-1])*3600 + (mm[i]-mm[i-1])*60 + (ss[i]-ss[i-1]);
                lu[i] = sumt * speed[j]/3.6 + lu[i-1];
                printf("%02d:%02d:%02d %.2f km\n",hh[i],mm[i],ss[i],lu[i]/1000);
            }
            else
            printf("%02d:%02d:%02d %.2f km\n",hh[i],mm[i],ss[i],lu[i]/1000);
            memset(s,'\0',sizeof(s));
            i++;
        }
    }
    return 0;
}
