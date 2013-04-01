/*************************************************************************
	> File Name: hdu1754.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月01日 星期一 16时49分14秒
 ************************************************************************/

#include<stdio.h>
#include<algorithm>
using namespace std;

const int MAX_LEN = 222222;

int tree[MAX_LEN << 2];
void pushup(int v){
	tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
}
void build(int v, int left, int right){
	if (left == right){
		scanf("%d", &tree[v]);
		return ;
	}
	int mid = (left + right) >> 1;
	build(v << 1, left, mid);
	build(v << 1 | 1, mid+1, right);
	pushup(v);
}
void update(int v, int p, int m, int left, int right){
	if (left == right){
		tree[v] = m;
		return ;
	}
	int mid = (left + right) >> 1;
	if (p <= mid) 
		update(v << 1, p, m, left, mid);
	else
		update(v << 1 | 1, p, m, mid+1, right);
	pushup(v);
}
int query(int v, int left, int right, int L, int R){
	if (L <= left && right <= R){
		return tree[v];
	}
	int mid = (left + right) / 2;
	int res = 0;
	if (L <= mid)
		res = max(res, query(v << 1, left, mid, L, R));
	if (mid < R)
		res = max(res, query(v << 1 | 1, mid+1, right, L, R));
	return res;
}
int main()
{
	int n,m;
	int i;
	char op[10];
	int x,y;
	while (scanf("%d %d", &n, &m) != EOF){
		build(1,1,n);
		while (m--){
			scanf("%s%d%d", op, &x, &y);
			if (op[0] == 'Q'){
				printf("%d\n", query(1, 1, n, x, y));
			}else if (op[0] == 'U'){
				update(1, x, y, 1, n);
			}
		}
	}
	return 0;
}
