/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月10日 星期日 23时27分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	cout << str << endl;
	return 0;
}
