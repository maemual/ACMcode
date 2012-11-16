#include <iostream>
#include <cstdio>
using namespace std;
#define Maxn 10000
struct Node{
	int a,b,left,right,cover;
};
Node Tree[Maxn];
int Number,Tot,c,d;
void build(int a,int b){
	int Now;
	Tot++;
	Now=Tot;
	Tree[Now].a=a;
	Tree[Now].b=b;
	Tree[Now].cover=0;
	if(b-a>1){
		int mid=(a+b)>>1;
		Tree[Now].left=Tot+1;
		build(a,mid);
		Tree[Now].right=Tot+1;
		build(mid,b);
	}
}
void insert(int Num){
	if(c<=Tree[Num].a&&Tree[Num].b<=d)
	  Tree[Num].cover++;
	else{
		int mid=(Tree[Num].a+Tree[Num].b)>>1;
		if(c<=mid)
		  insert(Tree[Num].left);
		if(d>=mid)
		  insert(Tree[Num].right);
	}
}
void del(int Num){
	if(c<=Tree[Num].a&&Tree[Num].b<=d)
	  Tree[Num].cover--;
	else{
		int mid=(Tree[Num].a+Tree[Num].b)>>1;
		if(c<=mid)
		  insert(Tree[Num].left);
		if(d>=mid)
		  insert(Tree[Num].right);
	}
}
void Count(int Num){
	if(Tree[Num].cover)
	  Number+=(Tree[Num].b-Tree[Num].a);
	else{
		if(Tree[Num].left)
		  Count(Tree[Num].left);
		if(Tree[Num].right)
		  Count(Tree[Num].left);
	}
}
int main()
{
	scanf("%d%d",&c,&d);
	build(c,d);
	while(scanf("%d%d",&c,&d)!=EOF)
	  insert(1);
	Number=0;
	Count(1);
	printf("%d\n",Number);
	return 0;
}
