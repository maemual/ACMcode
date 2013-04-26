/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月25日 星期四 22时54分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
	bool flag1,flag2;
	int pos1,pos2;
	int n;
	int arr[105];
	bool flag[105];
	memset(flag,true,sizeof(flag));
	flag1 = flag2 = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
		if (arr[i] < 0){
			flag1 = true;
			pos1 = i;
		}
		if (arr[i] > 0){
			flag2 = true;
			pos2 = i;
		}
	}
	if (flag1){
		printf("1 %d\n",arr[pos1]);
		flag[pos1] = false;
	}
	if (flag2){
		printf("1 %d\n",arr[pos2]);
		flag[pos2] = false;
		printf("%d",n-2);
		for (int i = 0; i < n; i++){
			if (flag[i]){
				printf(" %d",arr[i]);
			}
		}
		printf("\n");
	}else{
		printf("2");
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (flag[i]){
				if (arr[i] < 0){
					printf(" %d",arr[i]);
					flag[i] = false;
					cnt++;
					if (cnt == 2)
						break;
				}
			}
		}
		printf("\n");
		printf("%d",n-3);
		for (int i = 0; i < n; i++){
			if (flag[i]){
				printf(" %d",arr[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
