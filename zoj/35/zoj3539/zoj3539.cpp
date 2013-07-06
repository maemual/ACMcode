/*************************************************************************
	> File Name: zoj3539.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月06日 星期六 11时21分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 4
#define MAX_LEN 500
#define MAX_L 4
int n;
int length;
int limit[MAX_L];//limit表示压缩后限制的长度
int len[MAX_L];//len表示解压缩后的长度
int l[MAX_L];//l表示搜索过程中，串的压缩后长度
bool c[N];
int st[N];
int s[N][MAX_L];//s[i][j]表示第i个串在第j个位置扩展的是几号串，-1表示不扩展
string str;

bool check(){
	memset(c, 0, sizeof(c));//c用来记录，这个序号的串，之前是否出现过
	memset(st, 0, sizeof(st));//st中记录这个序号的串在原串中第一次出现的偏移量
	c[n-1] = true;
	for (int k = n-1; k >= 1; k--){
		if (c[k]){
			int p = st[k];
			for (int i = 0; i < l[k]; i++){
				if (s[k][i] == -1){
					p++;
				}else{
					if (c[s[k][i]]){//如果出现过这个序号的串，和前面的这个串逐字符比较
						for (int j = 0; j < len[s[k][i]]; j++){
							if (str[p+j] != str[st[s[k][i]]+j])//比较相同序号的串，在原串中是否完全相同
								return false;
						}
					}else{
						c[s[k][i]] = true;
						st[s[k][i]] = p;
					}
					p += len[s[k][i]];
				}
			}
		}
	}
	return true;
}
inline bool dfs1(int, int);
inline bool dfs2(int, int);
bool dfs2(int i, int k, int mmax_len){//mmax_len是当前最长的分解串长度，用于下面的优化
	if (i == l[k]){
		len[k] = 0;
		for (int j = 0; j < l[k]; j++){
			len[k] += s[k][j] == -1 ? 1 : len[s[k][j]];//计算第K个串的总长度
		}
		return dfs1(k + 1, max(mmax_len, len[k]));
	}else{
		for (s[k][i] = k - 1; s[k][i] >= -1; s[k][i]--){//搜索扩展点,-1表示不扩展
			if (dfs2(i + 1, k, mmax_len))
				return true;
		} 
	}
	return false;
}
bool dfs1(int k, int mmax_len){
	int t = mmax_len;
	for (int i = k; i < n; i++)
		t *= limit[i];
	if (t < length) return false;//当可生成的最大字符串还没有原字符串长，直接返回。

	if (k == n){
		return len[k-1] == length && check();
	}else{
		for (l[k] = limit[k]; l[k] >= 0; l[k]--){//确定第K个串的长度
			if (dfs2(0, k, mmax_len))
				return true;
		}
	}
	return false;
}
int main()
{
	while (cin >> n){
		for (int i = n-1; i >= 0; i--)
			cin >> limit[i];
		cin >> str;
		length = str.length();
		reverse(str.begin(), str.end());
		if (length > 256){
			cout << "No" << endl;
			continue;
		}
		if (dfs1(0, 1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
