/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月18日 星期四 10时40分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
using namespace std;

struct competition{
	string team;
	int price;
};
struct people{
	string name;
	double score;
};
set<int> maomao;
set<int> old;
set<int>::iterator sit;
map<string, int> mtp;
map<string, int>::iterator mit;
vector<people> vp;
bool isPrime(int x){
	for (int i = 2; i <= x/2; i++){
		if (x % i == 0)
			return false;
	}
	return true;
}
bool cmp(const people &p1, const people &p2){
	if (p1.score > p2.score)
		return true;
	else if (p1.score < p2.score)
		return false;
	else if (p1.name < p2.name)
		return true;
	else
		return false;
}
int main()
{
	int T;
	int n, m;
	int R, S, Q, P, C;
	int tmp;
	string st;
	people ptmp;
	cin >> T;
	while (T--){
		cin >> n >> m;
		maomao.clear();
		old.clear();
		cin >> R;
		for (int i = 0; i < R; i++){
			cin >> tmp;
			maomao.insert(tmp);
		}
		cin >> S;
		for (int i = 0; i < S; i++){
			cin >> tmp;
			old.insert(tmp);
		}
		cin >> Q;
		for (int i = 0; i < Q; i++){
			cin >> st >> tmp;
			mtp.insert(pair<string, int>(st, tmp));
		}
		vp.clear();
		char sch;
		for (int i = 0; i < n; i++){
			cin >> ptmp.name >> st >> sch >> P >> C;	
			ptmp.score = 0;
			mit = mtp.find(st);
			if (mit != mtp.end()){
				if (mit->second == 1){
					ptmp.score += 36;
				}else if (mit->second == 2){
					ptmp.score += 27;
				}else if (mit->second == 3){
					ptmp.score += 18;
				}
			}
			if (sch == 'F'){
				ptmp.score += 33;
			}
			for (int j = 0; j < P; j++){
				cin >> tmp;
				sit = maomao.find(tmp);
				if (sit != maomao.end()){
					ptmp.score += 2.5;
					continue;
				}
				sit = old.find(tmp);
				if (sit != old.end()){
					ptmp.score += 1.5;
					continue;
				}
				if (isPrime(tmp)){
					ptmp.score += 1;
					continue;
				}
				ptmp.score += 0.3;
			}
			vector<int> vec;
			for (int j = 0; j < C; j++){
				cin >> tmp;
				vec.push_back(tmp);
			}
			if (vec.size() >= 3){
				sort(vec.begin(), vec.end(), greater<int>());
				ptmp.score += max(0.0, (vec[2] - 1200) / 100.0) * 1.5;	
			}
			vp.push_back(ptmp);
		}
		sort(vp.begin(), vp.end(), cmp);
		cout<<fixed<<showpoint;
		for (int i = 0; i < m; i++){
			cout << vp[i].name << " " << setprecision(3) << vp[i].score << endl;
		}
	}
	return 0;
}
