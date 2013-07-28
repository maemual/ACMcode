/*
ID: maemual
PROB: crypt1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

set<int> mset;
set<int>::iterator it;
int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	int n;
	int tmp;
	scanf("%d", &n);
	mset.clear();
	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
		mset.insert(tmp);
	}
	int cnt = 0;
	for (int first = 100; first <= 999; first++){
		for (int sec = 10; sec <= 99; sec++){
			if (first * sec > 9999) break;
			int sa = sec / 10, sb = sec % 10;
			if (sa * first > 999 || sb * first > 999) continue;
			it = mset.find(sa);
			if (it == mset.end()) continue;
			it = mset.find(sb);
			if (it == mset.end()) continue;
			int fa = first / 100, fb = (first / 10) % 10, fc = first % 10;
			it = mset.find(fa);
			if (it == mset.end()) continue;
			it = mset.find(fb);
			if (it == mset.end()) continue;
			it = mset.find(fc);
			if (it == mset.end()) continue;
			int p1 = sb * first, p2 = sa * first;
			fa = p1 / 100, fb = (p1 / 10) % 10, fc = p1 % 10;
			it = mset.find(fa);
			if (it == mset.end()) continue;
			it = mset.find(fb);
			if (it == mset.end()) continue;
			it = mset.find(fc);
			if (it == mset.end()) continue;
			fa = p2 / 100, fb = (p2 / 10) % 10, fc = p2 % 10;
			it = mset.find(fa);
			if (it == mset.end()) continue;
			it = mset.find(fb);
			if (it == mset.end()) continue;
			it = mset.find(fc);
			if (it == mset.end()) continue;
			int ans = first * sec;
			int aa = ans / 1000, ab = (ans / 100) % 10, ac = (ans / 10) % 10, ad = ans % 10;
			it = mset.find(aa);
			if (it == mset.end()) continue;
			it = mset.find(ab);
			if (it == mset.end()) continue;
			it = mset.find(ac);
			if (it == mset.end()) continue;
			it = mset.find(ad);
			if (it == mset.end()) continue;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
