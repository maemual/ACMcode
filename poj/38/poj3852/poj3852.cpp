#include <stdio.h>
#include <string.h>
int n;
char value[101][101];
int len[101];/*保存字符串的长度*/
char cache[101];

int main()
{
    int i,j,k,cnt;
    /*freopen("input","r",stdin);*/
    while(scanf("%d",&n)&&n!=0)
    {
    	cnt=0;
    	for(i=0;i<n;i++) len[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",cache);
            len[i]=strlen(cache);
            for(j=0;j<len[i];j++)/*实现字符串的逆序存储*/
			{
				value[i][j]=cache[len[i]-j-1];
			}
			value[i][len[i]]='\0';
        }
        while(1)
        {
        	cnt++;
			for(i=0;i<n;i++)/*每个字符串删除一个字符*/
			{

				len[i]--;
				value[i][len[i]]='\0';
			}
			for(i=0;i<n;i++)
			{
				if(len[i]==0) goto next;/*有字符串为空串了*/

				for(k=0;k<n;k++)
					for(j=k+1;j<n;j++)
						if(len[k]==len[j])/*减少不必要的字符串比较*/
						{
							/*printf("%s   %s\n",value[k],value[j]);*/
							if(strcmp(value[k],value[j])==0) goto next;
						}
			}
        }
next:

		printf("%d\n",--cnt);
    }
    return 0;
}

