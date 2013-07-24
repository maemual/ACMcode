/*
ID: maemual
TASK: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	int n;
	fin >> n;
	vector<string> people;
	string tmp;
	for (int i = 0; i < n; i++){
		fin >> tmp;
		people.push_back(tmp);
	}
	map<string, int> mmap;
	int money, m;
	for (int i = 0; i < n; i++){
		fin >> tmp >> money >> m;
		mmap.insert(pair<string, int>(tmp, 0));
		string name;
		for (int j = 0; j < m; j++){
			fin >> name;
			mmap[name] += money / m;
		}
		if (m){
			mmap[tmp] -= (money / m) * m;
		}
	}
	for (int i = 0; i < n; i++){
		fout << people[i] << " " << mmap[people[i]] << endl;
	}
	return 0;
}
