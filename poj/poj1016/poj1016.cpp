#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX = 80;
 
char str[MAX+5];
 
void work(char s1[],char s2[])
{
    int i,num,j;
    for(i='0';i<='9';++i)
    {
        s2[i]=0;
    }
    for(i=0;i<strlen(s1);++i)
    {
        ++s2[s1[i]];
    }
    j=-1;
    for(i='0';i<='9';++i)
    {
        if(s2[i]>0&&s2[i]<10)
        {
            str[++j]=s2[i]+'0';
            str[++j]=i;
        }
        else if(s2[i]>=10)
        {
            str[++j]=s2[i]/10+'0';
            str[++j]=s2[i]%10+'0';
            str[++j]=i;
        }
 
 
    }
    str[++j]='\0';
}
 
int main()
{
    char s[16][MAX+5];
    int i,j,sign;
    while(1)
    {
        scanf("%s",&s[0]);
        if(strcmp(s[0],"-1")==0)
        {
            break;
        }
        sign=0;
        for(i=1;i<16;++i)
        {
            work(s[i-1],s[i]);
            strcpy(s[i],str);
            for(j=0;j<i;++j)
            {
                if(strcmp(s[i],s[j])==0)
                {
                    sign=1;
                    break;
                }
            }
            if(sign)
            {
 
                if(j==0&&i==1)
                {
                    printf("%s is self-inventorying\n",s[0]);
                }
                else if(j==i-1)
                {
                    printf("%s is self-inventorying after %d steps\n",s[0],i-1);
                }
                else
                {
                    printf("%s enters an inventory loop of length %d\n",s[0],i-j);
                }
                break;
            }
        }
        if(sign==0)
        {
            printf("%s can not be classified after 15 iterations\n",s[0]);
        }
    }
    //system("pause");
    return 0;
}

