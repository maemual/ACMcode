/*************************************************************************
	> File Name: g2.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月04日 星期六 12时03分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;

#define MAX_LEN 100005
typedef struct Node{
	int left,right;
	int value;
}Node;
Node tree[4*MAX_LEN];
int arr[MAX_LEN];
int ans;
int n,k;
void pushup(int v){
	tree[v].value = tree[v<<1].value + tree[v<<1|1].value;
}
void build(int v, int left, int right){
	tree[v].left = left;
	tree[v].right = right;
	if (left == right){
		tree[v].value = arr[left];
		return ;
	}
	int mid = (left + right) >> 1;
	build(v<<1, left, mid);
	build(v<<1|1, mid+1, right);
	pushup(v);
}
void query(int v, int left, int right){
	if (tree[v].left == left && tree[v].right == right){
		ans += tree[v].value;
		return ;
	}
	int mid = (tree[v].left + tree[v].right) >> 1;
	if (right <= mid)
		query(v<<1, left, right);
	else if (left > mid)
		query(v<<1 | 1, left, right);
	else{
		query(v<<1, left, mid);
		query(v<<1|1, mid+1, right);
	}
}
int main()
{
	//multiset<int> mset;
	//multiset<int>::iterator it;
	vector<int> mset;
//	vector<int>::iterator it;
	while (scanf("%d %d", &n, &k) != EOF){
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		build(1, 1, n);
		mset.clear();
		for (int i = n; i >= 1; i--){
		//	int xx = mset.size();
		//	mset.clear();
		//	k -= xx;

			ans = 0;
			query(1,1,i);
			//mset.insert(ans);
			mset.push_back(ans);
			for (int j = 2; j + i - 1 <= n; j++){
				ans -= arr[j - 1];
				ans += arr[j + i - 1];
				//mset.insert(ans);
				mset.push_back(ans);
			}
			if (mset.size() >= k){
				break;
			}
		}
		sort(mset.begin(),mset.end(),greater<int>());
		cout << mset[k-1] << endl;
	}
	return 0;
}
