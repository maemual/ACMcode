/*************************************************************************
	> File Name: i.cpp
	> Author: maemual
	> Mail: maemual@gmail.com
	> Created Time: 2013年07月18日 星期四 09时59分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string str;
int main()
{
    int T;
	int len, len2;
    scanf("%d",&T);
	getchar();
    while(T--)
    {
		getline(cin, str);
        len = len2 = str.length();
        while(1)
        {
            printf("%02X", (len & 127) + (len>127?128:0));
            len >>= 7;
            if (len == 0)
				break;
        }
        for(int i = 0; i < len2; i++)
            printf("%02X",(int)str[i]);
        printf("\n");
    }
    return 0;
}


