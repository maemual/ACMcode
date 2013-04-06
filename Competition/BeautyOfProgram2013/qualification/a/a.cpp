/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月06日 星期六 15时18分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
	int cas;
	int n,m;
	cin >> cas;
	string s1,s2;
	string str;
	map<string, string> mmap;
	string arr[105];
	for (int t = 1; t <= cas; t++){
		mmap.clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++){
			cin >> s1 >> s2;
			mmap.insert(pair<string, string>(s1,s2));
		}
		getchar();
		getline(cin, str);
		int k = 0;
		int j = 0;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == ' '){
				arr[k] = "";
				for (int p = j; p < i; p++)
					arr[k] += str[p];
				k++;
				j = i+1;
			}
		}
		arr[k] = "";
		for (int p = j; p < str.size(); p++)
			arr[k] += str[p];
		k++;
		
		map<string, string>::iterator it;
		for (int i = 0; i < n-1; i++){
			for (int j = 0; j < k; j++){
				it = mmap.find(arr[j]);
				if (it != mmap.end())
					arr[j] = it->second;
			}
		}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < k-1; i++)
			cout << arr[i] << " ";
		cout << arr[k-1] << endl;
	}
	return 0;
}
