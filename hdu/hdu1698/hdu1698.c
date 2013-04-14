/*************************************************************************
	> File Name: hdu1698.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月14日 星期日 17时30分24秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 100000
struct node{
	int left,right;
	int val,add;
}tree[MAX_LEN << 2];
int n;
void push_down(int v){
	if (tree[v].add == 0) return ;
	tree[v << 1].add = tree[v << 1 | 1].add = tree[v].add;
	tree[v << 1].val = (tree[v << 1].right - tree[v << 1].left + 1)*tree[v].add;
	tree[v << 1 | 1].val = (tree[v << 1 | 1].right - tree[v << 1 | 1].left + 1)*tree[v].add;
	tree[v].add = 0;
}
void push_up(int v){
	tree[v].val = tree[v << 1].val + tree[v << 1 | 1].val;
}
void build(int v, int left, int right){
	tree[v].left = left;
	tree[v].right = right;
	tree[v].val = right - left + 1;
	tree[v].add = 0;
	if (left == right)
		return ;
	int mid = (left + right) >> 1;
	build(v << 1, left, mid);
	build(v << 1 | 1, mid + 1, right);
}
void update(int v, int left, int right, int val){
	if (left <= tree[v].left && tree[v].right <= right){
		tree[v].val = val * (tree[v].right - tree[v].left + 1);
		tree[v].add = val;
		return ;
	}
	push_down(v);
	int mid = (tree[v].left + tree[v].right) >> 1;
	if (right <= mid)
		update(v << 1, left, right, val);
	else if (left > mid)
		update(v << 1 | 1, left, right, val);
	else{
		update(v << 1, left, mid, val);
		update(v << 1 | 1, mid + 1, right, val);
	}
	push_up(v);
}
int main()
{
	int cas;
	scanf("%d", &cas);
	int k;
	int p;
	int x, y, z;
	for (k = 1; k <= cas; k++){
		scanf("%d %d", &n, &p);
		build(1, 1, n);
		while (p--){
			scanf("%d %d %d", &x, &y, &z);
			update(1, x, y, z);
		}
		printf("Case %d: The total value of the hook is %d.\n", k, tree[1].val);
	}
	return 0;
}
