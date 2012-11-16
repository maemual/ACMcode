#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAX_LEN = 2000;
int account[MAX_LEN+5];

int main()
{
	int c, f1, f2, d;
	int day1, day2;
	int i, j, result, tmp;

	while (scanf("%d%d%d%d", &c, &f1, &f2, &d) != EOF)
	{
		memset(account, 0, sizeof(account));
		for (i = 0; i < c; i++){
			scanf("%d%d", &day1, &day2);
			for (j = day1; j <= day2; j++){
				account[j]++;
			}
		}
		tmp = f1 - f2;
		for (i = d; i >= 1 && tmp > 0; i--){
			tmp -= account[i];
		}
		printf("%d\n", i + 1);
	}
	return 0;
}
