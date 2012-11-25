#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    while (scanf("%d",&n) != EOF)
    {
        vector<string> vec;
        string ss;
        for (int i = 0;i != n;++i)
        {
            cin >> ss;
            vec.push_back(ss);
        }
        sort(vec.begin(),vec.end());
        int a[26];

        for (int i = 0;i < 26;++i)
            a[i] = -1;

        int p = 0;
        for (int i = 0;i < 26;++i)
        {
            for (int j = p;j != vec.size();++j)
            {
                if ((vec[j][0] - 'a') == i)
                {
                    a[i] = j;
                    p = j;
                    break;
                }
            }
        }
        cin >> m;
        for (int i = 0;i < m;++i)
        {
            string s;
            cin >> s;
            int count = 0;
            if (a[s[0]-'a'] != -1)
            {
                for (int ix = a[s[0]-'a'];ix != vec.size();++ix)
                {
                    if (vec[ix][0] <= s[0] && vec[ix][s.size()-1] <= s[s.size()-1])
                    {
                        if (vec[ix].size() >= s.size())
                        {
                            string stemp(vec[ix],0,s.size());
                            if (stemp == s)
                            {
                                ++count;
                                cout << vec[ix] << ' ';
                            }
                            if (count >= 8)
                            {
                                break;
                            }
                        }
                    }else break;
                }
            }
            if (count == 0)
                cout << s << endl;
            else printf("\n");
        }
    }
    return 0;
}
