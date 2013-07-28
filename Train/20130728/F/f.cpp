#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_LEN 1000005

int arr[MAX_LEN], n, k;
int main()
{
	while (scanf("%d %d", &n, &k) != EOF){
		for (int i = 0; i < 2 * n * k; i++)
			scanf("%d", &arr[i]);
		std::sort(arr, arr + 2 * n * k);
		int k = 0, ans = 0;
		for (int i = 0; i < 2 * n; i += 2)
			ans = std::max(ans, arr[i+1] - arr[i]);
		printf("%d\n", ans);
	}
	return 0;
}
