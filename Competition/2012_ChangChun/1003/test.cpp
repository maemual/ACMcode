#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ss1;
	cin >> ss1;
	string ss2;
	getline(cin,ss2);
	cout << ss1 << endl << ss2.size() << endl;
	return 0;
}
