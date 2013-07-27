#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=310;
int mat[MAXN][MAXN];
int n,m;
bool ok(int len)
{
    for(int i=0;i<=n-len;i++){
        for(int j=0;j<=m-len;j++){
            bool flag = true;
            for(int k=0;k<len;k++){
                int l = j, r = j + len - 1;
                while(l<r)
                {
                    if(mat[i+k][l] == mat[i+k][r]){
                        l++;
						r--;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) continue;
            for(int k = 0; k < len; k++){
                int l = i, r = i + len - 1;
                while (l < r){
                    if(mat[l][j+k]==mat[r][j+k]){
                        l++;
						r--;
					}else{
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;

            }
            if(flag)
            return true;
        }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
				scanf("%d",&mat[i][j]);
        int ans=min(n,m);
        while(!ok(ans)) ans--;
        printf("%d\n",ans);
    }
	return 0;
}

