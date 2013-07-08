/*************************************************************************
  > File Name: test.cpp
  > Author: maemual
  > Mail: maemual@gmail.com 
  > Created Time: 2013年05月28日 星期二 20时00分00秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<math.h>
#include<vector>
using namespace std;

typedef struct node{
	string str;
	double tfidf;
}node;
node n1;
map<string, double> mmap,mmap1,mmap2;
set<string> mset;
vector<node> vec1,vec2;
vector<double> v1,v2;

map<string, double>::iterator it;
set<string>::iterator its;
int num = 0;
bool cmp(const node &n1, const node &n2){
	return n1.tfidf > n2.tfidf;
}
void corpus(){
	string str;
	mmap.clear();
	while (1){
		cin >> str;
		if (str == "TEXT_END")	break;
		if (str == "CHAPTER_BEGIN"){
			num++;
			mset.clear();
			while (1){
				cin >> str;
				if (str == "CHAPTER_END") break;
				mset.insert(str);
			}
			for (its = mset.begin(); its != mset.end(); its++){
				it = mmap.find(*its);
				if (it != mmap.end()){
					it->second += 1;
				}else{
					mmap.insert(pair<string, double>(*its, 1.0));
				}
			}
		}
	}
	for (it = mmap.begin(); it != mmap.end(); it++){
		it->second = log10(num / it->second);
	}
}
void input(){
	string str;
	mmap1.clear();
	mmap2.clear();
	int x = 0;
	while (1){
		cin >> str;
		if (str == "TEXT_END") break;
		if (str == "TEXT_BEGIN") continue;
		x++;
		it = mmap.find(str);
		if (it == mmap.end()){
			mmap.insert(pair<string, double>(str, 1.0));
		}


		it = mmap1.find(str);
		if (it != mmap1.end()){
			it->second++;
		}else{
			mmap1.insert(pair<string, double>(str, 1.0));
		}
	}
	for (it = mmap1.begin(); it != mmap1.end(); it++){
		it->second /= x;
	}
	x = 0;
	while (1){
		cin >> str;
		if (str == "TEXT_END") break;
		if (str == "TEXT_BEGIN") continue;
		it = mmap.find(str);
		if (it == mmap.end()){
			mmap.insert(pair<string, double>(str, 1.0));
		}
		x++;
		it = mmap2.find(str);
		if (it != mmap2.end()){
			it->second++;
		}else{
			mmap2.insert(pair<string, double>(str, 1.0));
		}
	}
	for (it = mmap2.begin(); it != mmap2.end(); it++){
		it->second /= x;
	}
}
void tfidf(){
	vec1.clear();
	vec2.clear();
	for (it = mmap1.begin(); it != mmap1.end(); it++){
		n1.str = it->first;
		n1.tfidf = it->second * mmap[it->first];
		vec1.push_back(n1);
	}
	for (it = mmap2.begin(); it != mmap2.end(); it++){
		n1.str = it->first;
		n1.tfidf = it->second * mmap[it->first];
		vec2.push_back(n1);
	}
	sort(vec1.begin(), vec1.end(), cmp);
	sort(vec2.begin(), vec2.end(), cmp);
}
void vectorization(){
	mset.clear();
	for (int x = 0; x < 20; x++){
		mset.insert(vec1[x].str);
	}
	for (int x = 0; x < 20; x++){
		mset.insert(vec2[x].str);
	}
	v1.clear();
	v2.clear();
	for (its = mset.begin(); its != mset.end(); its++){
		//cout << *its << endl;
		it = mmap1.find(*its);
		if (it == mmap1.end()){
			v1.push_back(0);
		}else{
			v1.push_back(it->second);
		}
	}
	for (its = mset.begin(); its != mset.end(); its++){
		it = mmap2.find(*its);
		if (it == mmap2.end()){
			v2.push_back(0);
		}else{
			v2.push_back(it->second);
		}
	}
}
int main()
{
	//stdin = freopen("in.in", "r", stdin);
	string str;
	int T;
	corpus();
	cin >> T;
	while (T--){
		input();

		tfidf();

		vectorization();

		double tmp1, tmp2, tmp3;
		for (int i = 0; i < v1.size(); i++){
			tmp1 += v1[i] * v2[i];
		}
		for (int i = 0; i < v1.size(); i++){
			tmp2 += v1[i] * v1[i];
		}
		for (int i = 0; i < v2.size(); i++){
			tmp3 += v2[i] * v2[i];
		}
		double simi = tmp1 / (sqrt(tmp2)*sqrt(tmp3));
		//cout << simi << endl;
		if (simi > 0.8)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
