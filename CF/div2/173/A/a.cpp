/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月13日 星期三 23时31分44秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int x = 0;
	int n;
	cin >> n;
	string str;
	while (n--){
		cin >> str;
		if (str[1] == '+')
			x++;
		else
			x--;
	}
	cout << x << endl;
	return 0;
}
