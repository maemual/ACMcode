/*
ID: maemual
PROB: palsquare
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 20
int arr[MAX_LEN];
int base;
char mmap[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
void print(int k){
	if ((k / base) != 0)
		print(k / base);
	printf("%c", mmap[k % base]);
}
int to(int x){
	int num = 0;
	while (1){
		arr[num++] = x % base;
		if ((x / base) == 0)
			break;
		x /= base;
	}
	return num;
}
bool isOk(int n){
	for (int i = 0; i < n; i++){
		if (arr[i] != arr[n - i - 1])
			return false;
	}
	return true;
}
int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	scanf("%d", &base);	
	int n;
	for (int i = 1; i <= 300; i++){
		n = to(i*i);
		if (isOk(n)){
			print(i);
			printf(" ");
			print(i*i);
			printf("\n");
		}
	}
	return 0;
}
