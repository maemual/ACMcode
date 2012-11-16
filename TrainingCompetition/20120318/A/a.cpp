#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s1;
    string s2;
    while (cin >> s1)
    {
        cin >> s2;
        bool pan = false;
        while (!s2.empty())
        {
            string::size_type ix = s2.find('*');
            if (ix == 0)
            {
                string sh(s2,1,s2.size()-1);
                s2 = sh;
            }else if (ix <= s2.size())
            {
                string sf(s2,0,ix);
                string sh(s2,ix+1,s2.size()-ix);
                s2 = sh;
                string::size_type iy = s1.find(sf);
                if (iy > s1.size())
                {
                    printf("NO\n");
                    pan = false;
                    break;
                }else pan = true;
            }else {
                string::size_type iy = s1.find(s2);
                if (iy > s1.size())
                {
                    printf("NO\n");
                    pan = false;
                    break;
                }else pan = true;
                s2 = "";
            }
        }
        if (pan)
            printf("YES\n");
    }
    return 0;
}
