/*************************************************************************
	> File Name: d.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月10日 星期五 13时55分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200005
using namespace std;
struct node
{
	int l,r;
	int maxx;
	int add;
	int flag;
	int mid(){return (l+r)/2;}
}tree[N<<2];
int a[N];
int sum[N];
int n,m;
void build(int l,int r,int p)
{
	tree[p].l=l;
	tree[p].r=r;
	tree[p].flag=0;
	tree[p].add=0;
	if(l==r){
		tree[p].maxx=sum[l];
		return;
	}
	int m=tree[p].mid();
	build(l,m,p*2);
	build(m+1,r,p*2+1);
	tree[p].maxx=max(tree[p*2].maxx,tree[p*2+1].maxx);
}
void update(int val,int L,int R,int p)
{
	if(L<=tree[p].l && tree[p].r<=R)
	{
		tree[p].maxx+=val;
		tree[p].add+=val;
		tree[p].flag=1;
		return;
	}
	if(tree[p].flag==1)
	{
		tree[p*2].maxx+=tree[p].add;
		tree[p*2+1].maxx+=tree[p].add;
		tree[p*2].add=tree[p*2+1].add=tree[p].add;
		tree[p*2].flag=tree[p*2+1].flag=1;
		tree[p].flag=0;
	}
	int m=tree[p].mid();
	if(L<=m)
		update(val,L,R,p*2);
	if(R>m)
		update(val,L,R,p*2+1);
	tree[p].maxx=max(tree[p*2].maxx,tree[p*2+1].maxx);
}
int query(int L,int R,int p)
{
	if(L<=tree[p].l && tree[p].r<=R)
	{
		return tree[p].maxx;
	}
	if(tree[p].flag==1)
	{
		tree[p*2].maxx+=tree[p].add;
		tree[p*2+1].maxx+=tree[p].add;
		tree[p*2].add=tree[p*2+1].add=tree[p].add;
		tree[p*2].flag=tree[p*2+1].flag=1;
		tree[p].flag=0;
	}
	int m=tree[p].mid();
	int m1=-99999999,m2=-99999999;
	if(L<=m)
		m1=query(L,R,p*2);
	if(R>m)
		m2=query(L,R,p*2+1);
	return max(m1,m2);

}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=k;i++)
			sum[1]+=a[i];
		int cnt=1;
		for(int i=2;i<=n-k+1;i++)
			sum[++cnt]=sum[cnt-1]-a[i-1]+a[i+k-1];
		build(1,cnt,1);
		while(m--){
			int p,x,y;
			scanf("%d%d%d",&p,&x,&y);
			if(p==0)
			{
				update(y-a[x],max(1,x-k+1),min(cnt,x),1);
				a[x]=y;
			}else if(p==1)
			{
				update(a[y]-a[x],max(1,x-k+1),min(cnt,x),1);
				update(a[x]-a[y],max(1,y-k+1),min(cnt,y),1);
				int tt=a[x];
				a[x]=a[y];
				a[y]=tt;
			}else if(p==2)
			{
				int ans=0;
				ans=query(max(1,x-k+1),min(cnt,y-k+1),1);
				printf("%d\n",ans);
			}
		}
	}

	return 0;
}
