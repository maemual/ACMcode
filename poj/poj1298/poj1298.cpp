#include <iostream>
#include <string>
using namespace std;
int main()
{
    string sStart,sEnd;
    string cipher;
    string plain("VWXYZABCDEFGHIJKLMNOPQRSTU");
    while (1)
    {
        getline(cin,sStart);

        if (sStart == "ENDOFINPUT")
            break;

        getline(cin,cipher);
        getline(cin,sEnd);
        for (int i = 0;i < cipher.size();++i)
        {
            if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            {
                cout << plain[cipher[i]-'A'];
            }
            else cout << cipher[i];
        }
        cout << endl;
    }
    return 0;
}
