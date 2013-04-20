/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月20日 星期六 00时39分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int suma,sumb;
	suma = sumb = 0;
	string sa,sb;
	cin >> sa >> sb;
	int len1 = sa.length();
	int len2 = sb.length();
	for (int i = 0; i < len1; i++){
		if (sa[i] == '1')
			suma++;
	}
	for (int i = 0; i < len2; i++){
		if (sb[i] == '1')
			sumb++;
	}
	if (suma < sumb){
		if (sumb - suma > 1){
			printf("NO\n");
			return 0;
		}else{
			if ((suma % 2 != 0) && (sumb % 2 == 0)){
				printf("YES\n");
				return 0;
			}else {
				printf("NO\n");
				return 0;
			}
		}
	}else if (suma > sumb){
		printf("YES\n");
		return 0;
	}else{
		printf("YES\n");
		return 0;
	}
	return 0;
}
