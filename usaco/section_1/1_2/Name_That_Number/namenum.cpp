/*
 ID: maemual
PROB: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char ch2num[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
map<long long, vector<string> > mmap;
map<long long, vector<string> >::iterator it;
int main()
{
	string tmp;
	long long num;
	ifstream dicin("dict.txt");
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	mmap.clear();
	while (dicin >> tmp){
		num = 0;
		for (int i = 0; i < tmp.length(); i++){
			num *= 10;
			num += ch2num[tmp[i] - 'A'];
		}
		it = mmap.find(num);
		if (it == mmap.end()){
			vector<string> vec;
			vec.push_back(tmp);	
			mmap.insert(pair<long long, vector<string> >(num, vec));
		}else{
			it->second.push_back(tmp);
		}
	}
	long long n;
	fin >> n;
	it = mmap.find(n);
	if (it != mmap.end()){
		sort(it->second.begin(), it->second.end());
		for (int i = 0; i < it->second.size(); i++)
			fout << it->second[i] << endl;;
	}else
		fout << "NONE" << endl;
	return 0;
}
