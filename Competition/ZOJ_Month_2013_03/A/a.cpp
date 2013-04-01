/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月31日 星期日 12时04分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int l,r;
	int sum,lab;
	int mid(){return (l+r)/2;}
}tree[400000];
int n,m;
void build(int l,int r,int p)
{
	if(l<=r){
	tree[p].l=l;
	tree[p].r=r;
	if(p!=1){
		int t;
		scanf("%d",&t);
		tree[p/2].sum=1;
	}
	build(l,tree[p].mid(),p*2);
	build(tree[p].mid()+1,r,p*2+1);
	tree[p].sum+=tree[p*2].sum+tree[p*2+1].sum;
	}else
		return;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		build(1,n,1);
	}

	return 0;
}
