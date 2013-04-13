/*************************************************************************
	> File Name: hdu1166.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月01日 星期一 09时56分02秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_LEN 100005
typedef struct Node{
	int left,right;
	long long value,add;
}Node;
struct xx{
	int left,right;
	int d;
}op[100005];
Node tree[4*MAX_LEN+5];
long long arr[MAX_LEN];
long long brr[MAX_LEN];
int ans;
int n,m,k;
//更新上层

 
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 100005;
int h , w , n;
int col[maxn<<2];
int sum[maxn<<2];
void PushUp(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt,int m) {
	if (col[rt]) {
		col[rt<<1] = col[rt<<1|1] = col[rt];
		sum[rt<<1] = (m - (m >> 1)) * col[rt];
		sum[rt<<1|1] = (m >> 1) * col[rt];
		col[rt] = 0;
	}
}
void build(int l,int r,int rt) {
	col[rt] = 0;
	sum[rt] = 1;
	if (l == r) return ;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
	if (L <= l && r <= R) {
		col[rt] = c;
		sum[rt] = c * (r - l + 1);
		return ;
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , c , lson);
	if (R > m) update(L , R , c , rson);
	PushUp(rt);
}
void Q(int x, int y){
	for (int i = x; i <= y; i++){
		update(1, op[i].left, op[i].right, op[i].d);
	}
}
int main()
{
	cin >> n >> m >> k;
	memset(arr,0,sizeof(brr));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	for (int i = 1; i <= m; i++){
		cin >> op[i].left >> op[i].right >> op[i].d;
	}
	int x,y;
	for (int i = 1; i <= k; i++){
		cin >> x >> y;
		Q(x,y);
	}
	for (int i = 1; i <= n-1; i++){
		ans = 0;
		query(1, i, i);
		cout << ans << " ";
	}
	ans = 0;
	query(1, n, n);
	cout << ans << endl;
	/*
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
	*/
	
	return 0;
}
