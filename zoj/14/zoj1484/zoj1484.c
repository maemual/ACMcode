/*************************************************************************
	> File Name: zoj1484.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月05日 星期五 22时03分39秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 5000

struct node{
	int left, right;
	int num;
}tree[4*MAX_LEN];
void build(int rt, int left, int right){
	tree[rt].left = left;
	tree[rt].right = right;
	tree[rt].num = 0;
	if (left == right)
		return ;
	int mid = (left + right) >> 1;
	build(rt << 1, left, mid);
	build(rt << 1 | 1, mid+1, right);
}
int search(int rt, int left, int right){
	if (left > right)
		return 0;
	if (left == tree[rt].left && right == tree[rt].right)
		return tree[rt].num;
	int mid = (tree[rt].left + tree[rt].right) >> 1;
	if (right <= mid)
		return search(rt << 1, left, right);
	else if (left > mid)
		return search(rt << 1 | 1, left, right);
	else
		return search(rt << 1, left, mid) + search(rt << 1 | 1, mid + 1, right);
}
void update(int rt, int x){
	tree[rt].num++;
	if (tree[rt].left == tree[rt].right)
		return ;
	int mid = (tree[rt].left + tree[rt].right) >> 1;
	if (x <= mid)
		update(rt << 1, x);
	else
		update(rt << 1 | 1, x);
}
int main()
{
	int arr[MAX_LEN+5];
	int n;
	int i,ans;
	while (scanf("%d",&n) != EOF){
		build(1, 0, n-1);
		int sum = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (i = 0; i < n; i++){
			sum += search(1, arr[i] + 1, n-1);
			update(1, arr[i]);
		}
		ans = sum;
		for (i = 0; i < n -1; i++){
			sum += (n - arr[i] - 1) - arr[i];
			if (ans > sum)
				ans = sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}
