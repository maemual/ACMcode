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
	char ch;
	string s1,s2;
	while (1){
		s1 = "";
		s2 = "";
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		s1 += ch;
		while ((ch = getchar()) != ' ') s1 += ch;
		while ((ch = getchar()) == ' ') ;
		s2 += ch;
		while ((ch = getchar()) != ' ' && ch != '\n') s2 += ch;
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
