/*
ID: maemual
PROB: milk
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LEN 5005
struct node{
	int price;
	int num;
}farmer[MAX_LEN];
bool cmp(const node &n1, const node &n2){
	if (n1.price < n2.price || (n1.price == n2.price && n1.num > n2.num))
		return true;
	return false;	
}
int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &farmer[i].price, &farmer[i].num);
	sort(farmer, farmer + m, cmp);
	int k = 0;
	int cost = 0;
	while (n){
		if (n >= farmer[k].num){
			n -= farmer[k].num;
			cost += farmer[k].num * farmer[k].price;
		}else{
			cost += farmer[k].price * n;
			n = 0;
		}
		k++;
	}
	printf("%d\n", cost);
	return 0;
}
