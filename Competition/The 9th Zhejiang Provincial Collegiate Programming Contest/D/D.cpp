#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    int t;
    int alp[26];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(alp,0,sizeof(alp));
        string s1;
        cin >> s1;
        for (int i=0;i<s1.size();++i)
        {
            alp[s1[i]-'A'] = 1;
        }
        for (int i=2;i<=n;++i)
        {
            cin >> s1;
            for (int j=0;j<s1.size();++j)
            {
                if (alp[s1[j]-'A'] == i-1)
                    alp[s1[j]-'A'] = i;
            }
        }

        for (int i=0;i<26;i++)
        {
            if (alp[i] == n)
            {
                for (int j=0;j < alp[i]/n;++j)
                    printf("%c",i+'A');
            }
        }
        printf("\n");
    }
    return 0;
}
