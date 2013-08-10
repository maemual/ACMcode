/*************************************************************************
	> File Name: 1011.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年08月03日 星期六 14时55分01秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int MAX_LEN = 5 * 100000;
struct point{
	int x, y;
	bool operator<(const point &p) const {
		return x < p.x;
	}
}p[MAX_LEN + 5];
int n;
int Ax, Bx, Cx, Ay, By, Cy;
int main()
{
	int T;
	cin >> T;
	while (T--){
		cin >> n;	
		cin >> Ax >> Bx >> Cx >> Ay >> By >> Cy;
		p[0].x = p[0].y = 0;
		for (int i = 1; i <= n; i++){
			p[i].x = ((long long)p[i-1].x * Ax + Bx) % Cx;
			p[i].y = ((long long)p[i-1].y * Ay + By) % Cy;
		}
		multiset<point> mset;
		multiset<point>::iterator it, itx;
		mset.clear();
		mset.insert(p[1]);
		long long mmin = (1LL<<60);
		long long ans = 0;
		for (int i = 2; i <= n; i++){
			it = mset.lower_bound(p[i]);
			for (itx = it; itx != mset.end(); itx++){
				long long dx = itx->x - p[i].x;
				dx *= dx;
				if (dx >= mmin) break;
				long long dy = itx->y - p[i].y;
				dy *= dy;
				mmin = min(mmin, dx + dy);
			}
			for (itx = it; itx != mset.begin();){
				itx--;
				long long dx = itx->x - p[i].x;
				dx *= dx;
				if (dx >= mmin) break;
				long long dy = itx->y - p[i].y;
				dy *= dy;
				mmin = min(mmin, dx + dy);
			}
			ans += mmin;
			mset.insert(p[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
