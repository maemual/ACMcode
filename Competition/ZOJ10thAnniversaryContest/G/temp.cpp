#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	string t;
	cin >> s;
	cin >> t;
	cout << count(s.begin(),s.end(),'a')<< endl;
}
