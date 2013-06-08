/*************************************************************************
	> File Name: zoj3700.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月20日 星期六 20时17分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<map>
#include<cstdio>
#include<vector>
using namespace std;
typedef struct node{
	string last,second;
}node;
int main()
{
	int cas;
	char ch;
	string str;
	int lines;
	cin >> cas;
	map<string, int> mmap;
	map<string, int>::iterator it;
	node arr[2000];
	while (cas--){
		mmap.clear();
		for (int i = 0; i < 2000; i++)
			arr[i].last = arr[i].second = "";
		cin >> lines;
		getchar();
		str = "";
		while (1){
			if (lines == 0)
				break;
			ch = getchar();
			if (ch == '\n')
				lines--;
			ch = tolower(ch);
			if (ch >= 'a' && ch <= 'z')
				str += ch;
			else{
				if (str.length() == 0)
					continue;
				it = mmap.find(str);
				if (it != mmap.end()){
					mmap[str]++;
				}else{
					mmap.insert(pair<string, int>(str, 1));
				}
				str = "";
				continue;
			}
		}
		for (it = mmap.begin(); it != mmap.end(); it++){
			//cout << it->first << "  " << it->second << endl;
			int index = it->second;

			if (arr[index].last=="" && arr[index].second==""){
				arr[index].last = it->first;
			}else if (arr[index].last != "" && arr[index].second == ""){
				if ((it->first).length() == arr[index].last.length()){
					if (it->first < arr[index].last)
						arr[index].second = it->first;
					else{
						arr[index].second = arr[index].last;
						arr[index].last = it->first;
					}
				}else if ((it->first).length() > arr[index].last.length()){
					arr[index].last = it->first;
					arr[index].second = "";
				}
			}else if (arr[index].last != "" && arr[index].second != ""){
				if ((it->first).length() > arr[index].last.length()){
					arr[index].last = it->first;
					arr[index].second = "";
				}else if ((it->first).length() == arr[index].last.length()){
					if (it->first > arr[index].last){
						arr[index].second = arr[index].last;
						arr[index].last = it->first;
					}else if (it->first < arr[index].last 
							&& it->first > arr[index].second){
						arr[index].second = it->first;
					}
				}
			}
		}
		vector<string> vec;	
		for (int i = 1999; i >= 2; i--){
			if (arr[i].second.length() != 0)
				vec.push_back(arr[i].second);
			else if (arr[i].last.length() != 0)
				vec.push_back(arr[i].last);
		}
		if (vec.size() >= 1){
			for (int i = 0; i < vec.size()-1; i++)
				cout << vec[i] << " ";
			cout << vec[vec.size()-1] << endl;
		}else{
			cout << endl;
		}
	}
	return 0;
}
