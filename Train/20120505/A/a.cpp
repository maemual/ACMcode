#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int length[2000];
vector<string> s;
void swap(string &p,string &q)  
{  
	string t=p; 
	p=q;  
	q=t;  
}
int partition(int ls,int lt)  
{  
	int i,j;
	string temp;
	i=ls;j=lt;  
	temp=s[i];  
	do  
	{	  
		while((s[j]<temp) && (i<j))  
			j--;  
		if(i<j)  {
			string tem = s[i];
			s[i] = s[j];
			s[j] = tem;
			
			int te = length[i];
			length[i] = length[j];
			length[j] = te;
			i++;
		}
		while((s[i]>=temp) && (i<j))  
			i++;  
		if (i<j)  {
			string tem = s[i];
			s[i] = s[j];
			s[j] = tem;
			
			int te = length[i];
			length[i] = length[j];
			length[j] = te;
			j--;
		}
		
	}while(i!=j);  
	s[i]=temp;  
	return i;  
}  

void quick_sort(int hs,int ht)  
{  
	int i;  
	if (hs<ht)  
	{  
		i=partition(hs,ht);  
		quick_sort(hs,i-1);  
		quick_sort(i+1,ht);  
	}  
}  


bool cmp(string s1,string s2)
{
	return s1 > s2;
}
int main()
{
	int m;
	while (cin >> m)
	{
		string stemp;
		s.clear();
		int max = -1;
		for (int i=0;i<2000;++i)
		  length[i] = 0;
		for (int i=0;i<m;++i)
		{
			cin >> stemp;
			s.push_back(stemp);
			length[i] = stemp.end() - stemp.begin();
			if (max < (stemp.end()-stemp.begin()))
			  max = (stemp.end()-stemp.begin());
		}
		for (int i = 0;i<s.size();++i)
		{
			while (s[i].size() < max)
			  s[i] += s[i][0];	
		}	
		quick_sort(0,m-1);
		for (int i =0;i< s.size();++i)
		{
			for (int j=0;j<length[i];++j)
			{
				  printf("%c",s[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
