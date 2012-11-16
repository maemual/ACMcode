#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<string> forward;
	stack<string> back;
	string cmd;
	string current="http://www.acm.org/";
				
	while (1)
	{
		cin >> cmd;
		if (cmd == "QUIT")
		  break;
		if (cmd == "VISIT")
		{
			back.push(current);
			cin >> current;
			cout << current << endl;
			while (!forward.empty())
			  forward.pop();
		}else if (cmd == "BACK")
		{
			if (back.empty())
			  cout << "Ignored" << endl;
			else{
				forward.push(current);
				current = back.top();
				back.pop();
				cout << current << endl;
			}
		}else if (cmd == "FORWARD")
		{
			if (forward.empty())
			  cout << "Ignored" << endl;
			else {
				back.push(current);
				current = forward.top();
				forward.pop();
				cout << current << endl;
			}
		}
	}
	return 0;
}
