#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

string num2str(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int str2num(string s)
 {
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

int nu[2000000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int k=1;k<=t;++k)
    {
        int a,b;
        int count = 0;
        scanf("%d%d",&a,&b);
        memset(nu,0,sizeof(nu));
        for (int i=a;i<=b;i++)
        {
            string s1 = num2str(i);
            for (int j=0;j < s1.size();++j)
            {
                string s2;
                string sfront(s1,0,j+1),sback;
                sback = s1.substr(j+1);
                s2 = sback + sfront;
                int num2 = str2num(s2);
                if (num2 < b && num2>i)
                {
                    if (nu[i] == 0 && nu[num2] == 0)
                    {
                        nu[i] = 1;
                        nu[num2] = 1;
                        count++;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
