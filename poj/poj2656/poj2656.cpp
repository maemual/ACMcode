#include <cstdio>
int main(){
	while(1) {
		int i, n;
		int maxday, maxvalue = -1;
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 1; i <= n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a + b > maxvalue) {
				maxvalue = a + b;
				maxday = i;
			}
		}
		if (maxvalue <= 8) 
		  printf("0\n");
		else 
		  printf("%d\n", maxday);
	}
	return 0;
}
