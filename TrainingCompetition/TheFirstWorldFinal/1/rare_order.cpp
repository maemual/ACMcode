#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string ste;
	cin >> ste;
	vector<string> vec;
	while ( ste != "#")
	{
		vec.push_back(ste);
		cin >> ste;
	}
		
	return 0;
}
