/*************************************************************************
	> File Name: i.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月25日 星期四 09时11分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 100005

char str[MAX_LEN];
int len;
int sum(char s[]){
	int tmp = 0;
	for (int i = 0; i < len - 1; i++){
		tmp += str[i] - '0';	
	}
	return tmp;
}
int main()
{
	int T;
	int s;
	int last;
	scanf("%d", &T);
	while (T--){
		scanf("%s", str+1);
		str[0] = '0';
		len = strlen(str);
		s = sum(str);
		last = str[len-1] - '0';
		bool flag = false;
		while (1){
			last++;
			if (last == 10){
				last = 0;
				flag = true;
			}
			if (flag){
				int jin = 1;
				for (int i = len - 2; i >= 0; i--){
					str[i] += jin;
					if (str[i] > '9'){
						str[i] = '0';
						jin = 1;
					}else
						jin = 0;
				}
				flag = false;
				s = sum(str);
			}
			if ((s + last) % 10 == 0){
				if (str[0] == '0'){
					for (int i = 1; i < len - 1; i++)
						printf("%c", str[i]);
					printf("%d\n", last);
				}else{
					for (int i = 0; i < len - 1; i++)
						printf("%c", str[i]);
					printf("%d\n", last);
				}
				break;
			}
		}
	}
	return 0;
}
