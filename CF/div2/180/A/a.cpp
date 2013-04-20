/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月19日 星期五 23时33分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string str;
	int n;
	cin >> n;
	cin >> str;
	int i;
	int firstR = -1,firstL = -1;
	int lastR = -1,lastL = -1;
	for (i = 0; i < n; i++){
		if (str[i] == 'R'){
			firstR = i;
			break;
		}
	}
	for (i = n-1; i >= 0; i--){
		if (str[i] == 'R'){
			lastR = i;
			break;
		}
	}
	for (i = 0; i < n; i++){
		if (str[i] == 'L'){
			firstL = i;
			break;
		}
	}
	for (i = n-1; i >= 0; i--){
		if (str[i] == 'L'){
			lastL = i;
			break;
		}
	}
	if (firstR == -1){
		cout << lastL + 1 << " " << firstL << endl;
	}else if (firstL == -1){
		cout << firstR + 1 << " " << lastR + 2 << endl;
	}else {
		cout << firstR + 1 << " " << lastR + 1 << endl;
	}
	/*
	if (firstR == -1){
		cout << firstL + 1 << " " << lastL + 2 << endl;
	}else if (firstL == -1){
		cout << firstR + 1 << " " << lastR + 2 << endl;
	}else if (firstR < firstL){
		cout << firstR+1 << " " << firstL << endl;
	}else if (firstR > firstL){
		cout << firstL+1 << " " << lastR-1 << endl;
	}
	*/
	return 0;
}
