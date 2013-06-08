/*************************************************************************
	> File Name: zoj2104.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月02日 星期六 17时05分50秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

map<string,int> mmap;
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		string tmp;
		mmap.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (mmap.count(tmp) == 0)
				mmap.insert(pair<string,int>(tmp,1));
			else
				mmap[tmp]++;
		}
		map<string,int>::iterator it;
		int max = -1;
		string ans;
		for (it = mmap.begin(); it != mmap.end(); it++)
		{
			if (it->second > max)
			{
				max = it->second;
				ans = it->first;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
