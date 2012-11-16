#include <iostream>
#include <string>
using namespace std;
 
int main(){
    //char num[35];
    string num;
	while(cin >> num && num[0] != '0'){
        int pow = 1, sum = 0;
        for(int i = num.size() - 1; i >= 0; i --){
            pow *= 2;
            sum += (num[i] - '0') * (pow - 1);
        }
        cout << sum << endl;
    }
 return 0;
}

