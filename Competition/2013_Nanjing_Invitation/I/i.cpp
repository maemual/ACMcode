/*************************************************************************
	> File Name: i.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月12日 星期日 20时00分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
#include<cctype>
#include<map>
using namespace std;

#define MAX_LEN 300
bool done;
bool error;
map<string, string> vmap;
map<string, string> cmap;
map<string, string>::iterator it;

string trim(const string &s){
	int pos1 = 0;
	int pos2 = s.length() - 1;
	while (s[pos1] == ' ' || s[pos1] == '\t') pos1++;
	while (s[pos2] == ' ' || s[pos2] == '\t') pos2--;
	return s.substr(pos1, pos2 - pos1 + 1);
}
void split(const string &s, string &s1, string &s2){
	int pos1 = 0, pos2 = 0;
	while (s[pos1] != ' ' && s[pos1] != '\t') pos1++;
	pos2 = pos1;
	while (s[pos2] == ' ' || s[pos2] == '\t') pos2++;
	s1 = trim(s.substr(0, pos1));
	s2 = trim(s.substr(pos2, s.length() - pos2 + 1));
}
void doAssignment(string &s){
	string st1,st2;
	string::size_type pos = s.find("=");
	st1 = trim(s.substr(0, pos));
	st2 = trim(s.substr(pos+1, s.length() - pos));
	//cout << st1 << "++++" << st2 << "+++" <<endl;
	if (st1[0] == '$'){
		it = vmap.find(st1);
		if (it != vmap.end()){
			it->second = st2;
		}else{
			vmap.insert(pair<string, string>(st1, st2));
		}
	}else{
		it = cmap.find(st1);
		if (it != cmap.end()){
			if (error){
				cout << "WARNING: Constant " << st1 << " Already Defined!" << endl;
			}
		}else{
			cmap.insert(pair<string, string>(st1, st2));
		}
	}
}
void doPrint(string &s){
	if (s[0] == '$'){
		it = vmap.find(s);
		if (it != vmap.end()){
			if ((it->second)[0] == '\"'){
				cout << (it->second).substr(1,(it->second).length()-2) << endl;
			}else{
				cout << it->second << endl;
			}
		}else{
			cout << "NULL" << endl;
			if (error){
				cout << "NOTICE: Undefined Variable " << s << "." << endl;
			}
		}
	}else{
		it = cmap.find(s);
		if (it != cmap.end()){
			if ((it->second)[0] == '\"'){
				cout << (it->second).substr(1,(it->second).length()-2) << endl;
			}else{
				cout << it->second << endl;
			}
		}else{
			cout << s << endl;
			if (error){
				cout << "NOTICE: Undefined Constant " << s << "." << endl;
			}
		}
	}
}
void doDump(string &s){
	if (s[0] == '$'){
		it = vmap.find(s);
		if (it != vmap.end()){
			if ((it->second)[0] != '\"'){
				cout << "integer: " << it->second << endl;
			}else{
				cout << "string: " << it->second << endl;
			}
		}else{
			cout << "NULL" << endl;
			if (error){
				cout << "NOTICE: Undefined Variable " << s << "." << endl;
			}
		}
	}else{
		it = cmap.find(s);
		if (it != cmap.end()){
			if ((it->second)[0] != '\"'){
				cout << "integer: " << it->second << endl;
			}else{
				cout << "string: " << it->second << endl;
			}
		}else{
			cout << "string: \"" << s << "\"" << endl;
			if (error){
				cout << "NOTICE: Undefined Constant " << s << "." << endl;
			}
		}
	}
}
void doError(string &s){
	if (s == "ON")
		error = true;
	else
		error = false;
}
void doTerminate(){
	cout << "Script was KILLED." << endl;
	done = true;
}
int main()
{
	int T;
	int n;
	string str;
	string str1,str2;
	cin >> T;
	while (T--){
		vmap.clear();
		cmap.clear();
		cin >> n;
		getchar();
		done = false;
		error = true;
		while (n--){
			getline(cin, str);
			if (done) continue;

			str1 = str2 = "";
			str = trim(str);
			if (str == "") continue;

			if (str.find("=") != string::npos){
				doAssignment(str);
				continue;
			}else if (str == "Panic"){
				doTerminate();
				continue;
			}
			split(str, str1, str2);
			//cout << str1 << "++++" << str2 << "+++" <<endl;
			if (str1 == "Errmsg")
				doError(str2);
			else if (str1 == "Print")
				doPrint(str2);
			else if (str1 == "Dump")
				doDump(str2);
		}
		if (T > 0) cout << endl;
	}
	return 0;
}
