/*************************************************************************
	> File Name: hdu1166.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月01日 星期一 09时56分02秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 50000
typedef struct Node{
	int left,right;
	int value,add;
}Node;
Node tree[4*MAX_LEN+5];
int arr[MAX_LEN];
int ans;

//更新上层
void pushup(int v){
	tree[v].value = tree[v*2].value + tree[v*2+1].value;
}
void build(int v, int left, int right){
	tree[v].left = left;
	tree[v].right = right;
	if (left == right){
		//对结点进行初始化
		tree[v].value = arr[left];
		return ;
	}
	int mid = (left + right) / 2;
	build(v*2, left, mid);
	build(v*2+1, mid+1, right);
	//根据左右儿子更新当前结点
	pushup(v);
}
void update(int v, int left, int right, int m){
	if (tree[v].left == left && tree[v].right == right){
		tree[v].value += m*(right - left + 1);
		tree[v].add = m;
		return ;
	}
	if (tree[v].add){
		tree[v*2].add += tree[v].add;
		tree[v*2+1].add += tree[v].add;
		tree[v].add = 0;
	}
	int mid = (tree[v].left + tree[v].right) / 2;
	if (right <= mid){
		update(v*2, left, right, m);
	}else if (left > mid){
		update(v*2+1, left, right, m);
	}else{
		update(v*2, left, mid, m);
		update(v*2+1, mid+1, right, m);
	}
	pushup(v);
}
void query(int v, int left, int right){
	if (tree[v].left == left && tree[v].right == right){
		ans += tree[v].value;
		return ;
	}
	if (tree[v].add){
		tree[v*2].add += tree[v].add;
		tree[v*2+1].add += tree[v].add;
		tree[v].add = 0;//传递增量
	}
	int mid = (tree[v].left + tree[v].right) / 2;
	if (right <= mid){
		query(v*2, left, right);
	}else if (left > mid){
		query(v*2+1, left, right);
	}else{
		query(v*2, left, mid);
		query(v*2+1, mid+1, right);
	}
}
int main()
{
	int cas;
	scanf("%d",&cas);
	int n;
	int i,k;
	int x,y;
	char str[10];
	for (k = 1; k <= cas; k++)
	{
		printf("Case %d:\n",k);
		scanf("%d",&n);
		for (i = 1; i <= n; i++)
			scanf("%d",&arr[i]);

		build(1,1,n);
		while (1)
		{
			scanf("%s",str);
			if (str[0] == 'E')
				break;
			if (str[0] == 'Q'){
				scanf("%d %d",&x, &y);
				ans = 0;
				query(1, x, y);
				printf("%d\n",ans);
			}else if (str[0] == 'A'){
				scanf("%d %d", &x, &y);
				update(1, x, x, y);
			}else if (str[0] == 'S'){
				scanf("%d %d", &x, &y);
				update(1, x, x, -y);
			}
		}
	}
	return 0;
}
