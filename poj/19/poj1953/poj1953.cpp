#include<cstdio>

int fib(int n) {
	int i, f[45];
	if(n == 1) return 2;
	if(n == 2) return 3;
	f[1] = 2; f[2] = 3;
	for(i=3; i<=n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}

int main() {
	int i, t, n;
	scanf("%d", &t);
	for(i=1; i<=t; i++) {
		scanf("%d", &n);
		printf("Scenario #%d:\n", i);
		printf("%d\n\n", fib(n));
	}
	return 0;
}

