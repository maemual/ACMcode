/*
ID: maemual
PROB: calfflac
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int MAX_LEN = 20005;
int main()
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	string str1, str2, tmp;
	int pos[MAX_LEN];
	str1 = "";
	while (getline(fin, tmp)){
		str1 += tmp + '\n';
	}
	int len = str1.length();
	int k = 0;
	for (int i = 0; i < len; i++){
		if (isalpha(str1[i])){
			str2 += tolower(str1[i]);
			pos[k++] = i;
		}
	}
	int maxleft, maxright, maxlen = 1;
	int left, right;
	int len2 = str2.length();
	for (int i = 1; i < len2 - 1; i++){
		if (str2[i] == str2[i+1]){
			left = i - 1;
			right = i + 2;
			while (left >= 0 && right < len2 && str2[left] == str2[right]){
				left--;
				right++;
			}
			if (right - left - 2 + 1 > maxlen){
				maxlen = right - left - 2 + 1;
				maxleft = pos[left + 1];
				maxright = pos[right - 1];
			}
		}
		left = i - 1;
		right = i + 1;
		while (left >= 0 && right < len2 && str2[left] == str2[right]){
			left--;
			right++;
		}
		if (right - left - 2 + 1 > maxlen){
			maxlen = right - left - 2 + 1;
			maxleft = pos[left + 1];
			maxright = pos[right - 1];
		}
	}
	fout << maxlen << endl;
	for (int i = maxleft; i <= maxright; i++){
		fout << str1[i];
	}
	fout << endl;
	//fout << str2 << endl;
	return 0;
}
