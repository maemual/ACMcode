//KMP应用之求最小循环节
//注意KMP中next函数的定义：是k后面一小节与0~next[k]一小节相等
//所以有:若有循环节len和next[len]之间就是一小段最小的循环节
//若len和next[len]间的长度可以被len整除 则可以"一节一节的得到循环"
//所以原问题等价于len-next[len]是否整除len
//注意只有当s[next[len]]==s[len]时才是循环的，否则不是的

#include<stdio.h>
#include<string.h>
char s1[10002],s2[10002];
int next1[10002],next2[10002];
void get_next(const char s[],int next[]);
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		get_next(s1,next1);
		get_next(s2,next2);
		int l1=strlen(s1),l2=strlen(s2);
		for (int i=0;i<l1;i++)
		  printf("%d ",next1[i]);
		printf("\n");

		for (int i=0;i<l2;i++)
		  printf("%d ",next2[i]);
		printf("\n");
		bool f=true;
		int ans1,ans2;
		if((l1%(l1-1-next1[l1-1])==0)&&(s1[l1-1]==s1[next1[l1-1]])) 
		  ans1=l1-1-next1[l1-1];
		else 
		  ans1=l1;
		if((l2%(l2-1-next2[l2-1])==0)&&(s2[l2-1]==s2[next2[l2-1]])) 
		  ans2=l2-1-next2[l2-1];
		else 
		  ans2=l2;
		char ss1[10002],ss2[100002];
		for(int j=0;j<ans1;j++) 
		  ss1[j]=s1[j];
		for(int j=0;j<ans2;j++) 
		  ss2[j]=s2[j];
		ss1[ans1]=0;
		ss2[ans2]=0;
		if(strcmp(ss1,ss2)==0) 
		  printf("%s\n",ss1);
		else 
		  printf("I am just kidding!\n");
	}
	return 0;
}
void get_next(const char s[],int next[])
{
	int i=1,j=-1,l=strlen(s);
	next[0]=-1;
	while(i<l)
	{
		if(j==-1||s[i-1]==s[j])
		{
			j++;
			next[i]=j;
			i++;
		}
		else j=next[j];
	}
}
