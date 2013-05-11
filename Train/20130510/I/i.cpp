#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n;

struct DFA
{
	const static int MAXB=26;
	const static int MAXL=2500*1100+10;
	int next[MAXL][MAXB],size,root,fail[MAXL];
	int que[MAXL*MAXB],in,out,id[MAXL],pre[MAXL];
	bool visit[2510],danger[MAXL];
	void init()
	{
		size=0,root=newNode(-1);
	}
	int newNode(int pr)
	{
		pre[size]=pr;
		memset(next[size],-1,sizeof(next[size]));
		danger[size]=false;
		id[size]=-1;
		return size++;
	}
	int getVal(char ch)
	{
		return ch-'A';
	}
	void insert(char *str,int idx)
	{
		int p=root;
		for(int i=0; str[i]; ++i)
		{
			int now=getVal(str[i]);
			if(next[p][now]==-1) next[p][now]=newNode(p);
			p=next[p][now];
		}
		danger[p]=true;
		id[p]=idx;
	}
	void makeFail()
	{
		in=out=0;
		for(int i=0; i<MAXB; ++i)
			if(~next[root][i])
				fail[next[root][i]]=root,que[in++]=next[root][i];
			else 
				next[root][i]=root;
		while(in!=out)
		{
			int x=que[out++];
			for(int i=0; i<MAXB; ++i)
				if(~next[x][i])
				{
					fail[next[x][i]]=next[fail[x]][i];
					danger[next[x][i]]|=danger[next[fail[x]][i]];
					que[in++]=next[x][i];
				}
				else
					next[x][i]=next[fail[x]][i];
		}
	}
	int search(char *str)
	{
		int p=root;
		memset(visit,false,sizeof(visit));
		for(int i=0; str[i]; ++i)
		{
			int now=getVal(str[i]);
			p=next[p][now];
			if(~id[p]) visit[id[p]]=true;
		}
		for(int i=in-1;i>=0;--i)
		{
			int x=que[i];
			if(~id[x] && visit[id[x]])
			{
				int u=pre[x];
				while(u!=root)
				{
					int v=u;
					while(danger[v] && v!=root)
					{
						danger[v]=false;
						if(~id[v])visit[id[v]]=false;
						v=fail[v];
					}
					u=pre[u];
				}
			}
		}
		int ret=0;
		for(int i=0;i<n;++i)
			if(visit[i]) ret++;
		return ret;
	}
};

char str[5100000],artical[5100010],fp[2010];

DFA dfa;

int getNumber(char *str,int &i,char &tar)
{
	int ret=0;
	for(;; ++i)
	{
		if(str[i]>='A' && str[i]<='Z')
		{
			tar=str[i];
			return ret;
		}
		ret=ret*10+str[i]-'0';
	}
}
void makeFull(char *full, char *ori)
{
	int cnt=0;
	for(int i=0; ori[i]; ++i)
	{
		if(ori[i]==']')continue;
		if(ori[i]=='[')
		{
			char tar;
			int num=getNumber(ori,++i,tar);
			for(int i=0; i<num; ++i)
				full[cnt++]=tar;
		}
		else full[cnt++]=ori[i];
	}
	full[cnt]=0;
}
void solve()
{
	dfa.init();
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; ++i)
	{
		gets(str);
		makeFull(fp,str);
		dfa.insert(fp,i);
	}

	dfa.makeFail();

	gets(str);
	makeFull(artical,str);

	printf("%d\n",dfa.search(artical));
}
int main()
{
	int t;
	for(scanf("%d",&t); t--;)
		solve();
	return 0;
}
