#include<iostream>  
#include<string>  
#include<sstream>  
using namespace std;  
int main(){  
	string a;  
	string c;  
	while(cin>>c){  
		getline(cin,a);  
		cout<<c<<a<<endl;  
	}  
	return 0;  
}

