#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	string name;
	vector<string> tips;
};
int main()
{
	string str;
	int n,m;
	while (cin >> n)
	{
		node words[105];
		for (int i = 0; i < n; i++)
		{
			cin >> words[i].name;
			while (1)
			{
				string s;
				cin >> s;
				words[i].tips.push_back(s);
				if (getchar() == '\n')
				  break;
			}
		}
		cin >> m;
		for (int x = 0; x < m; x++)
		{
			string s;
			node query[105];
			int num = 0;
			while (1)
			{
				cin >> s;
				for (int i = 0; i < n; i++)
				{
					if (words[i].name == s)
					  query[num++] = words[i];
				}
				char ch = getchar();
				if (ch == '\n')
				  break;
			}
			vector<string> result;
			string stemp;
			for (int i = 0; i < 1; i++)
			{
				for (int j = 0; j < query[i].tips.size(); j++)
				{
					stemp = query[i].tips[j];
					bool ff = false;
					for (int k = i + 1; k < num; k++)
					{
						bool flag = true;
						for (int p = 0; p < query[k].tips.size(); p++)
						{
							if (stemp == query[k].tips[p])
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							ff = true;
							break;
						}
					}
					if (ff)
					  continue;
					else
					  result.push_back(stemp);
				}
			}
			if (result.size() == 0)
			{
				cout << "NO" << endl;
			}
			else {
				sort(result.begin(),result.end());
				for (int i = 0; i < result.size()-1; i++)
				  cout << result[i] << ' ';
				cout << result[result.size()-1]<< endl;
			}
		}
	}
	return 0;
}
