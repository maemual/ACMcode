/*
ID: maemual
PROB: beads
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 355

char str[2 * MAX_LEN];
inline bool same(char c1, char c2){
	if (c1 == c2 || c1 == 'w')
		return true;
	return false;
}
int main()
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		str[i + n] = str[i];
	str[2 * n] = '\0';
	int len = strlen(str);
	int mmax = -1;
	bool flag = false;
	for (int i = 0; i < len - 1; i++){
			int p = i;
			int q = i + 1;
			int cnt = 0;
			char cmp = str[i];
			if (str[i] == 'w'){
				flag = true;
			}
			while (p > 0 && q - p <= n && same(str[p], cmp)) {
				if (flag && str[p] != 'w'){
					cmp = str[p];
					flag = false;
				}
				p--;
				cnt++;
			}
			cmp = str[i+1];
			if (str[i] == 'w')
				flag = true;
			while (q < len && q - p <= n && same(str[q], cmp)) {
				q++;
				if (flag && str[q] != 'w'){
					cmp = str[q];
					flag = false;
				}
				cnt++;
			}
			if (mmax < cnt){
				mmax = cnt;
			}
	}
	printf("%d\n", mmax);
	return 0;
}
