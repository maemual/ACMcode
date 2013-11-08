//fuck the "Judgement failed"
#include<iostream>

using namespace std;

typedef long long llg;

llg m;

llg fib(llg x, llg y){
    llg cnt = 0;
    llg tmp = 0;
    while (y < m){
        tmp = y;
        y += x;
        x = tmp;
        cnt++;
    }
    return cnt;
}
int main()
{
    llg x, y;
    cin >> x >> y >> m;

    llg mmax = max(x, y);
    llg mmin = min(x, y);
    x = mmin;
    y = mmax;

    if (x >= m || y >= m){
        cout << 0 << endl;
    }else if (x <= 0 && y <= 0){
        cout << -1 << endl;
    }else if (x >= 0 && y >= 0){
        cout << fib(x, y) << endl;
    }else if (x <= 0 && y > 0){
        llg cnt = (-x) / y - 1;
        while (x + y * cnt < 0) cnt++;
        x = x + y * cnt;
        cout << cnt + fib(x, y) << endl;
    }
    return 0;
}
