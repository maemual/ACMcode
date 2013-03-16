/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月14日 星期四 00时08分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s,t;
	bool ps,pt;
	cin >> s >> t;
	if (s.length() != t.length()){
		cout << "NO\n";
		return 0;
	}
	ps = (s.find("1") != string::npos?true:false);
	pt = (t.find("1") != string::npos?true:false);
	if ((ps && pt) || (!ps && !pt)){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}
