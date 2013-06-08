#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string,string> dict;
	string s;
	while (1)
	{
		getline(cin,s);
		if (s == "")
		  break;
		string s1,s2;
		int i;
		for (i=0;s[i] != ' ';i++)
		  s1 += s[i];
		for (i = i+1;i < s.size();i++)
		  s2 += s[i];
		dict[s2] = s1;
	}

	while (cin >> s)
	{
		if (dict.count(s))
		  cout << dict[s] << endl;
		else
		  cout << "eh" << endl;
	}
	return 0;
}
