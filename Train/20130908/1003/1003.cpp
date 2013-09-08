#include<cstdio>
#include<limits.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;
ll mat[15][15];

int main()
{
    int n;
    while (1){
        scanf("%d", &n);
        if (n == 0) break;
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
                cin >> mat[i][j];
        ll level = (n - 1) / 2;
        ll cx = level, cy = level;
        ll p1, p2, p3, p4, q1, q2, q3, q4;
        ll cnt = 0;
        ll mmax = 0;
        for (int i = 1; i <= level; i++){
            p1 = cx - i, q1 = cy - i;
            p2 = cx - i, q2 = cy + i;
            p3 = cx + i, q3 = cy + i;
            p4 = cx + i, q4 = cy - i;
            ll mm = INT_MIN;
            ll mc1 = 0;
            if (mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4] > mm)
                mm = mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4];
            for (int j = 1; j <= 2 * i - 1; j++){
                q1++;
                p2++;
                q3--;
                p4--;
                if (mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4] > mm){
                    mm = mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4];
                    mc1 = j;
                }
            }
            p1 = cx - i, q1 = cy - i;
            p2 = cx - i, q2 = cy + i;
            p3 = cx + i, q3 = cy + i;
            p4 = cx + i, q4 = cy - i;
            mm = INT_MIN;
            ll mc2 = 0;
            if (mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4] > mm)
                mm = mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4];
            for (int j = 1; j <= 2 * i - 1; j++){
                p1++;
                q2--;
                p3--;
                q4++;
                if (mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4] > mm){
                    mm = mat[p1][q1]+mat[p2][q2]+mat[p3][q3]+mat[p4][q4];
                    mc2 = j;
                }
            }
            mc1 = min(mc1, 2 * i - mc1);
            mc2 = min(mc2, 2 * i - mc2);
            mmax += mm;
            cnt += min(mc1, mc2);
        }
        cout << mmax+ mat[cx][cy] << " " << cnt << endl;
    }
    return 0;
}
