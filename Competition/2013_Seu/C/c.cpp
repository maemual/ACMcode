/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月04日 星期六 10时18分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LEN 100005
typedef struct Node{
	int left,right;
	int max,min;
}Node;
Node tree[MAX_LEN*4 + 5];
int arr[MAX_LEN];
int ans;
void pushup(int v){
	tree[v].max = max(tree[v << 1].max, tree[v << 1 | 1].max);
	tree[v].min = min(tree[v << 1].min, tree[v << 1 | 1].min);
}
void build(int v, int left, int right){
	tree[v].left = left;
	tree[v].right = right;
	if (left == right){
		tree[v].max = arr[left];
		tree[v].min = arr[left];
		return ;
	}
	int mid = (left + right) >> 1;
	build(v << 1, left, mid);
	build(v << 1 | 1, mid+1, right);
	pushup(v);
}
void query(int v, int left, int right, int x, int y){
	if (tree[v].left == left && tree[v].right == right){
		if (x <= tree[v].min && tree[v].max <= y){
			ans += tree[v].right - tree[v].left + 1;
		}else if (y < tree[v].min || x > tree[v].max)
			return ;
		else {
			int mid = (tree[v].left + tree[v].right) >> 1;
			//if (right <= mid){
			//	query(v<<1, left, right, x, y);
			//}else if (left > mid){
			//	query(v<<1|1, left, right, x, y);
			//}else{
				query(v<<1, left, mid, x, y);
				query(v<<1|1, mid+1, right, x, y);
			//}
		}
		return ;
	}
	int mid = (tree[v].left + tree[v].right) >> 1;
	if (right <= mid){
		query(v<<1, left, right, x, y);
	}else if (left > mid){
		query(v<<1|1, left, right, x, y);
	}else{
		query(v<<1, left, mid, x, y);
		query(v<<1|1, mid+1, right, x, y);
	}
}
int main()
{
	int n,q;
	int l,r,x,y;
	while (scanf("%d %d", &n, &q) != EOF){
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		build(1,1,n);
		for (int i = 0; i < q; i++){
			scanf("%d %d %d %d", &l, &r, &x, &y);
			ans = 0;
			query(1,l,r,x,y);
			printf("%d\n",ans);
		}
	}
	return 0;
}
