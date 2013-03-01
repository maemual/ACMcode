/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年02月28日 星期四 23时49分41秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

string next(string st)
{
	if (st.length() == 1)
	{
		st[0]++;
		if (st[0] > 'z')
			st = "aa";
	}else{
		st[1]++;
		if (st[1] > 'z')
		{	
			st[1] = 'a';
			st[0]++;
		}
	}
	return st;
}

int main()
{
	int n;
	cin >> n;
	vector<string> vec;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	string ans = "a";
	string::size_type pos;
	while (1)
	{
		bool flag = true;
		for (int i = 0; i < vec.size(); i++)
		{
			pos = vec[i].find(ans);
			if (pos != vec[i].npos)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << ans << endl;
			break;
		}else
			ans = next(ans);
	}
	return 0;
}
