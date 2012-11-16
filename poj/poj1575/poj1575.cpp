#include <iostream>
#include <string>
using namespace std;
bool vowel(char s){
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
    return false;
}
int main(){
    string s;
    while(cin>>s, s != "end"){
        int l = s.length();
        bool rule1 = false, rule2 = true, rule3 = true;
        for (int i = 0; i < l; i++) if (vowel(s[i])){
            rule1 = true;
            break;
        }
        for (int i = 1; i < l - 1; i++)
        if ((vowel(s[i]) && vowel(s[i - 1]) && vowel(s[i + 1])) || (!vowel(s[i]) && !vowel(s[i - 1]) && !vowel(s[i + 1]))){
            rule2 = false;
            break;
        }
        for (int i = 1; i < l; i++)
        if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o'){
            rule3 = false;
            break;
        }
        cout<<"<"<<s<<"> is ";
        if (rule1 && rule2 && rule3) cout<<"acceptable."<<endl;
        else cout<<"not acceptable."<<endl;
    }
    return 0;
}

