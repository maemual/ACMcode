#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
double converFromString(string &s)
{
	istringstream i(s);
	double x;
	if (i >> x)
	  return x;
	return 0.0;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string time;
		cin >> time;
		int pos;
		for (int i=0;i<time.size();i++)
		{
			if (time[i] == ':')
			{
				pos=i;
				break;
			}
		}
		bool pan = true;
		for (int i=pos+1;i<time.size();i++)
		{
			if (time[i] != '0')
			{
				pan = false;
				break;
			}
		}
		if (pan){
			string s;
			for (int i=0;i<pos;i++)
			  s+=time[i];
			int k=(int)converFromString(s);
			if (k<=12)
			  cout << k+12<<endl;
			else cout << k-12<<endl;
		}else cout << 0 << endl;
	}
	return 0;
}
