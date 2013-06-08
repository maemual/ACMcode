/*************************************************************************
	> File Name: poj2503.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月05日 星期日 19时34分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string,string> mmap;
	string s1,s2;
	char str[205];
	char str1[100],str2[100];
	while (gets(str) && str[0] != '\0'){
		sscanf(str, "%s %s", str1, str2);
		s1.assign(str1);
		s2.assign(str2);
		mmap.insert(pair<string,string>(s2,s1));
	}
	map<string,string>::iterator it;
	while (cin >> s1){
		it = mmap.find(s1);
		if (it != mmap.end()){
			cout << it->second << endl;
		}else{
			printf("eh\n");
		}
	}
	return 0;
}
