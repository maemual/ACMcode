#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int MOD = 55566677;

int n,m,x[55],y[55];
int day[60],chp[60],s[60]={1};

int dfs(int i, int t){
	if(i==m){
		if(t%2) 
			return (MOD-s[n-t])%MOD; 
		else
			return s[n-t];
	}
	int ret=dfs(i+1,t);
	if(!day[x[i]] && !chp[y[i]]){
		day[x[i]]=chp[y[i]]=1;
		ret=(ret+dfs(i+1,t+1))%MOD;
		day[x[i]]=chp[y[i]]=0;
	}
	return ret;
}

int main()
{
	int t;
	for(int i=1;i<60;i++) 
		s[i]=s[i-1]*1ll*i%MOD;
	while(scanf("%d%d%d",&n,&m,&t)==3)
	{
		for(int i=0;i<m;i++) 
			scanf("%d%d",x+i,y+i);
		for(int i=0;i<m;i++) 
			for(int j=i+1;j<m;j++){
			if(x[i]==x[j] && y[i]==y[j])
			{
				swap(x[j],x[m-1]);
				swap(y[j],y[--m]);
			}
		}
		memset(day,0,sizeof(day));
		memset(chp,0,sizeof(chp));
		bool flag = false;
		for(int i=0;i<t;i++)
		{
			int t1,t2;
			scanf("%d %d",&t1,&t2);
			if (flag)
				continue;
			if (day[t1] != 0){
				flag = true;
			}
			day[t1]=1;
			chp[t2]=1;
			n--;
		}
		if (flag){
			printf("0\n");
			continue;
		}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}
