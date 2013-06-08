#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,s1,s2,len1,len2;
	char str[2101],str1[2101],str2[2101];
	cin>>n;
	while(n--)
	{
		cin>>str>>str1>>str2;
		s1=0;s2=0;len1=strlen(str);
		len2=strlen(str1);
		while(1)
		{
			if(str1[s2]=='*'||str2[s2]=='*') s1++;
			else
			  if(str[s1]==str1[s2]||str[s1]==str2[s2]) s1++;
			s2++;
			if(s1==len1) break;
			if(s2==len2) break;
		}
		if(s1==len1)  cout<<"win"<<endl;
		else cout<<"lose"<<endl;
	}
	return 0;
}


