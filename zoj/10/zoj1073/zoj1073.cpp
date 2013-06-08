#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string strmul(const string& source)
{
	int i,j;
	string add;
	int len = source.length();
	for(i=0;i<len;i++)//反转字符串便于计算
	{
		add.append(source,len-i-1,1);
	}
	string result(add);
	//将每个字符串当作一个整数相加len次，即乘以len+1
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			int temp = (result[j]-'0')+(add[j]-'0');
			if(temp<10)
			  result[j] = temp+'0';
			else
			{
				temp -= 10;
				result[j] = temp+'0';
				result[j+1] += 1; 
			}
		}
	}
	return result;
}
int main()
{
	string digital,result;
	int i;
	while(cin>>digital)
	{
		result = strmul(digital);
		string strnine("");
		strnine.reserve(digital.length());
		for(i=0;i<digital.length();i++)
		{
			strnine.append("9");
		}
		if(result==strnine)
		  printf("%s is cyclic\n",digital.c_str());
		else
		  printf("%s is not cyclic\n",digital.c_str());
	}
	return 0;
}
