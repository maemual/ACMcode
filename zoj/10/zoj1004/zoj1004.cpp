#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s1,s2,st,end;
char ope[1000];
int len;
stack<char> s;
bool check()
{
	end = "";
	while (!s.empty())
	  s.pop();
	int k=0;
	for (int i=0;i<2*len;i++)
	{
		if (ope[i] == 'i')
			s.push(s1[k++]);
		else {
			if (!s.empty())
			{
				end+= s.top();
				s.pop();
			}
		}
	}
	if (end == s2)
	  return true;
	return false;
}
void print()
{
	for (int i =0;i<2*len;i++)
	  cout << ope[i] << " ";
	cout << endl;
}
void dfs(int k,int cntI,int cntO)
{
	if (k>=2*len)
	{
		//cout << "OK" << endl;
		if (check())
		  print();
	//	for (int i=0;i<2*len;i++)
	//	  cout << ope[i] << " ";
	//	cout << endl;
		return;
	}
	if (cntI < len)
	{
		ope[k] = 'i';
		dfs(k+1,cntI+1,cntO);
	}
	if (cntO < len)
	{
		ope[k] = 'o';
		dfs(k+1,cntI,cntO+1);
	}
	
}
int main()
{
	while (cin>> s1 >> s2)
	{
		cout << "[" << endl;
		len = s1.length();
		while (!s.empty())
		  s.pop();
		dfs(0,0,0);
		cout << "]" << endl;
	}
	return 0;
}
