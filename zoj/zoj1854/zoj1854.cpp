#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

struct node{
	string party;
	int vote;
}temp;
int main()
{
	int n,m;
	while (cin >> n)
	{
		while (getchar() != '\n') continue;
		string name,party;
		map<string,node> amap;
		for (int i = 0; i < n; i++)
		{
			getline(cin,name);
			getline(cin,party);
			temp.party = party;
			temp.vote = 0;
			amap.insert(pair<string,node>(name,temp));
		}
		cin >> m;
		while (getchar() != '\n') continue;
		string votefor;
		for (int i = 0; i < m; i++)
		{
			getline(cin,votefor);
			map<string,node>::iterator it = amap.find(votefor);
			if (it != amap.end())
			{
				(it->second).vote++;
			}
		}
		int max = -1;
		int cnt = 0;
		string ans;
		map<string,node>::iterator it;
		for (it = amap.begin(); it != amap.end(); it++)
		{
			if ((it->second).vote == max){
				cnt++;
			}else if ((it->second).vote > max){
				max = (it->second).vote;
				ans = (it->second).party;
				cnt = 0;
			}
		}
		if (cnt == 0)
		  cout << ans << endl;
		else
		  cout << "tie" << endl;
	}
	return 0;
}
