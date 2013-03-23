/*************************************************************************
	> File Name: poj3274.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月23日 星期六 20时43分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_LEN 1000007
int sum[100005][35];
int hash[MAX_LEN],next[MAX_LEN];
int ELFhash(char *key){
	unsigned long h = 0;
	unsigned long x = 0;
	while (*key){
		h = (h << 4) + (*key++);
		if ((x = h & 0xF0000000L) != 0){
			h ^= (x >> 24);
			h &= ~x;
		}
	}
	return h % MAX_LEN;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int x;
	memset(sum,0,sizeof(sum));
	for (int i = 1; i <= n; i++){
		scanf("%d",&x);
		for (int j = 0; j < 30; j++){
			sum[i][j] = x & 1;
			x >>= 1;
			if (x == 0)
				break;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			sum[i][j] += sum[i-1][j];

	for (int i = 1; i <= n; i++)
		for (int j = k-1; j >= 0; j--)
			sum[i][j] -= sum[i][0];

	memset(hash,-1,sizeof(hash));

	int hashnum;
	int ans = 0;
	char str[35];
	for (int i = 0; i <= n; i++){
		for (int j = 0; j < k; j++)
			str[j] = sum[i][j] + '0';
		
		str[k] = '\0';

		hashnum = ELFhash(str);
		for (;;hashnum++){
			if (hash[hashnum] == -1)
				break;
			bool flag = true;
			for (int j = 0; j < k; j++){
				if (sum[i][j] != sum[hash[hashnum]][j]){
					flag = false;
					break;
				}
			}
			if (flag)
				break;
		}
		if (hash[hashnum] == -1)
			hash[hashnum] = i;
		else{
			if (i - hash[hashnum] > ans)
				ans = i - hash[hashnum];
		}
	}
	printf("%d\n",ans);
	return 0;
}
