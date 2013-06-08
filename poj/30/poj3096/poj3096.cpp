#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vec;
	string s;
	string st;
	while (1)
	{
		cin >> s;
		if (s[0] == '*')
		  break;
		int len = s.length();
		bool flag = true;
		vec.clear();
		for (int i=1;i<len-1;i++)
		{
			//cout << "OK" << endl;
			vec.clear();
			for (int j=0;j<len-i;j++)
			{
				st="";
				st+=s[j];
				st+=s[j+i];
				for (int k=0;k<vec.size();k++)
				{
					if (vec[k] == st)
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				  break;
				else 
				  vec.push_back(st);
			}
			if (flag == false)
			  break;
		}
		//for (int i=0;i<vec.size();i++)
		// cout << vec[i]<<endl;
		if (flag)
		  cout << s << " is surprising." << endl;
		else
		  cout << s << " is NOT surprising." << endl;
	}
	return 0;
}
