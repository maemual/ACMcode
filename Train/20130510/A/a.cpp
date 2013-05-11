/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月10日 星期五 14时41分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string getString(const vector<int> &v, int x, int n){
	string str = "";
	for (int i = x; i < x + n; i++)
		str += (char)(v[i]);
	return str;
}
bool cmp(int x, int y){
	int xx = x % 10;
	int yy = y % 10;
	if (xx > yy)
		return false;
	else if (xx < yy)
		return true;
	else {
		if (x > y)
			return false;
		else
			return true;
	}
}
int main()
{
	int T;
	int n1,n2;
	int x;
	vector<int> vec1,vec2,vec3,vec4;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &n1, &n2);
		vec1.clear();
		vec2.clear();
		vec3.clear();
		vec4.clear();
		for (int i = 0; i < n1; i++){
			scanf("%d", &x);
			vec1.push_back(x);
		}
		for (int i = 0; i < n2; i++){
			scanf("%d", &x);
			vec2.push_back(x);
		}
		sort(vec1.begin(), vec1.end(), greater<int>());
		sort(vec2.begin(), vec2.end(), greater<int>());
		vec3.push_back(vec1[0]);
		for (int i = 1; i < vec1.size(); i++){
			if (vec1[i] != vec1[i-1])	{
				vec3.push_back(vec1[i]);
			}
		}
		/*
		for (int i = 0; i < vec3.size(); i++){
			cout << vec3[i] << "  ";
		}
		cout << endl;
		*/
		vec4.push_back(vec2[0]);
		for (int i = 1; i < vec2.size(); i++){
			if (vec2[i] != vec2[i-1])	{
				vec4.push_back(vec2[i]);
			}
		}
		/*
		for (int i = 0; i < vec4.size(); i++){
			cout << vec4[i] << "  ";
		}
		cout << endl;
		*/
		//cout << getString(vec3, 0, vec3.size()) << endl;	
		string ss = getString(vec4, 0, vec4.size());
		string str;
		vector<int> ans;
		bool flag = false;
		for (int i = vec3.size(); i >= 1; i--){
			for (int j = 0; j + i <= vec3.size(); j++){
				str = getString(vec3, j, i);
				if (ss.find(str) != string::npos){
					for (int k = 0; k < i; k++){
						ans.push_back(vec3[k+j]);
					}
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag){
			printf("NONE\n");
			continue;
		}
		for (int i = 0; i < ans.size()-1; i++){
			cout << ans[i] << " ";
		}
		cout << ans[ans.size()-1]<< endl;
		sort(ans.begin(), ans.end(), cmp);
		for (int i = 0; i < ans.size()-1; i++){
			cout << ans[i] << " ";
		}
		cout << ans[ans.size()-1]<< endl;
	}
	return 0;
}
