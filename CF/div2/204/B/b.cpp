#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_LEN 100005
vector<int> arr[MAX_LEN];
struct node{
    int idx, diff;
}ans[MAX_LEN];
bool check(int k){
    if (arr[k].size() == 1)
        return true;
    int x = arr[k][1] - arr[k][0];
    int len = arr[k].size();
    for (int i = 1; i < len; i++){
        if (arr[k][i] - arr[k][i-1] != x)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < MAX_LEN; i++)
        arr[i].clear();
    for (int i = 0; i < n; i++){
        cin >> x;
        arr[x].push_back(i);
    }
    for (int i = 0; i < MAX_LEN; i++){
        if (arr[i].size() > 0){
            sort(arr[i].begin(), arr[i].end());
        }
    }
    int tot = 0;
    for (int i = 0; i < MAX_LEN; i++){
        if (arr[i].size() > 0){
            if (check(i)){
                if (arr[i].size() == 1){
                    ans[tot].idx = i;
                    ans[tot++].diff = 0;
                }else{
                    ans[tot].idx = i;
                    ans[tot++].diff = arr[i][1] - arr[i][0];
                }
            }
        }
    }
    cout << tot << endl;
    for (int i = 0; i < tot; i++){
        cout << ans[i].idx << " " << ans[i].diff << endl;
    }
    return 0;
}
