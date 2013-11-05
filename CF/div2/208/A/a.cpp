#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_LEN 1005
int arr[MAX_LEN];

struct interval{
    int s, e;
    interval() {}
    interval(int _s, int _e):s(_s), e(_e){}
};

vector<interval> vec;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    vec.clear();
    int flag = 0;
    for (int i = 1; i < n; i++){
        int s = min(arr[i], arr[i-1]);
        int e = max(arr[i], arr[i-1]);
        for (int j = 0; j < vec.size(); j++){
            if ((s > vec[j].s && s < vec[j].e && e > vec[j].e)
                || (s < vec[j].s && e > vec[j].s && e < vec[j].e)){
                flag = 1;
                break;
            }
        }
        if (flag) break;
        vec.push_back(interval(s, e));
    }
    if (flag)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
