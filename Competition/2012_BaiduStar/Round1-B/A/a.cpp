#include <stdio.h>
#include <iostream>
using namespace std;

int d[10001];
int n;
int base = 0;

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void gauss(int m = 62)
{
    base =0;
    int i, j;
    for (i=m;i>=0; i--) {
        int flag = 0;
        for (j = base; j < n; ++j) {
            if ((d[j] >> i) & 1) {
                swap(d[base],d[j]);
                flag = 1;
                break;
            }
        }
        if (flag) {
            for (j = 0; j < n; ++j) {
                if (j != base && (d[j] & (1 << i)))
                    d[j] ^= d[base];
            }
            ++base;
        }
    }
}
int todo(int ask){
    if (base < n) {
		if (ask == 1) {
			 return 0;
        }
        else ask -= 1;
    }
    if (ask >= (1 << base)) {
		return -1;
    }
    int ans = 0;
    for (int j = 0; j < 63; ++j) {
		if ((ask >> j) & 1)
			ans ^= d[base-j-1];
    }
	return ans;
}
int main()
{
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &d[i]);
        }
        gauss();
        for (int i=1;;i++)
		{
			if (todo(i) == -1)
			{
				printf("%d %d\n",todo(i-1),todo(i-2));
				break;
			}
		}
    }
    return 0;
}
