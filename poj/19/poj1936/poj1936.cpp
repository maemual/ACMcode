#include <iostream>
#include <string>
using namespace std;
bool compare(string s1,string s2)
{
	int i=0,j=0;
	while (i != s1.size() && j != s2.size())
	{
		if (s1[i] == s2[j])
		{
			i++;
		}
		j++;
	}
	if (i == s1.size())
		return true;
	else 
		return false;
}
int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{		
		if (compare(s1,s2))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return 0;
}
