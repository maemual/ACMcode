/*************************************************************************
	> File Name: zoj1858.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月03日 星期日 09时37分12秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int p[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	string str;
	while (cin >> str)
	{
		int last=-1;
		for (int i=0;i<str.size();i++)
		{
			if (p[str[i]-'A'] != last && p[str[i]-'A'] != 0)
			{
				cout << p[str[i]-'A'];	
			}
			last = p[str[i]-'A'];
		}
		cout << endl;
	}
	return 0;
}
