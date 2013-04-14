#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

#define MAX_INT 0x3f3f3f3f
#define MAX_V 100005
#define MAX_EDGE 200005

struct net{
	int e,vs,vt;
	struct edge
	{
		int x,y,c;
		edge *next,*op;
	}*ls[MAX_V],*fa[MAX_V],*cur[MAX_V],g[MAX_EDGE];
	
	int d[MAX_V],num[MAX_V];

	void init()
	{
		e=0; 
		memset(ls,0,sizeof(ls));
	}
	void clear()
	{
		for (int i=0;i<e;i++) 
			ls[g[i].x]=NULL; 
		e=0;
	}
	void addedge(int x,int y,int c){
		g[e].x=x; g[e].y=y; g[e].c=c; g[e].next=ls[x]; ls[x]=&g[e]; g[e].op=&g[e+1];
		e++;
		g[e].x=y; g[e].y=x; g[e].c=0; g[e].next=ls[y]; ls[y]=&g[e]; g[e].op=&g[e-1];
		e++;
		
		swap(x,y);
		g[e].x=x; g[e].y=y; g[e].c=c; g[e].next=ls[x]; ls[x]=&g[e]; g[e].op=&g[e+1];
		e++;
		g[e].x=y; g[e].y=x; g[e].c=0; g[e].next=ls[y]; ls[y]=&g[e]; g[e].op=&g[e-1];
		e++;
	}

	int solve(int n)
	{
		int ret=0,i,nf;
		for (i=1;i<=n;i++) d[i]=0,num[i]=0,cur[i]=ls[i];
		for (i=vs,num[0]=n;d[vs]<n;){
			edge *&t=cur[i];
			while (t && !(t->c && d[t->y]+1==d[i])) t=t->next;
			if (t){
				fa[t->y]=t;
				i=t->y;
				if (i==vt){
					for (nf=MAX_INT;i!=vs;i=fa[i]->x) if (fa[i]->c<nf) nf=fa[i]->c;
					for (i=vt  ;i!=vs;i=fa[i]->x) {fa[i]->c-=nf; fa[i]->op->c+=nf;}
					ret+=nf;
				}
			}
			else{
				if (--num[d[i]]==0) return ret;   // gap
				d[i]=n;
				for (t=ls[i];t;t=t->next)
					if (t->c && d[t->y]+1<d[i]) d[i]=d[t->y]+1;
				num[d[i]]++;
				t=ls[i];
				if (i!=vs) i=fa[i]->x;
			}
		}
		return ret;
	}
}aaa;

int main()
{
	aaa.init();
	int cas;
	int n,m;
	scanf("%d", &cas);
	for (int k = 1; k <= cas; k++)
	{	
		aaa.clear();
		scanf("%d %d", &n, &m);
		aaa.vs = 1;
		aaa.vt = n;
		int x, y, z, flow = 0;
		printf("Case #%d:\n", k);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			aaa.addedge(x, y, z);
			int ans = aaa.solve(aaa.vt);
			if(ans)
			{
				printf("%d %d\n", i, ans);
			}
		}
	}
	return 0;
}
