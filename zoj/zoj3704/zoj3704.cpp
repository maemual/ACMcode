/*************************************************************************
	> File Name: i.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月20日 星期六 13时25分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int cas;
	string title;
	int week;
	double dowload,upload;
	double ratio;
	cin >> cas;
	while (cas--){
		cin >> title;
		cin >> week >> dowload >> upload;
		ratio = upload / dowload;
		bool flag;
		flag = true;
		if (dowload >= 50 && ratio < 0.4
				|| dowload >= 100 && ratio < 0.5
				|| dowload >= 200 && ratio < 0.6
				|| dowload >= 400 && ratio < 0.7
				|| dowload >= 800 && ratio < 0.8)
		{
			title = "Peasant";
			cout << title << endl;
			continue;
		}
		if (title == "Peasant") title = "User";
		if (week >= 100 && dowload >= 3 * 1024 && ratio >= 4.55){
			title = "Nexus_Master";
			cout << title << endl;
			continue;
		}
		if (title == "Nexus_Master" && week >= 100 && dowload >= 3*1024 && ratio >= 4.45){
			cout << title << endl;
			continue;
		}
		if (title == "Nexus_Master" && week >= 100 && dowload >= 3*1024 && ratio < 4.45){
			title = "Ultimate_User";
		}
		if (week >= 80 && dowload >= 1.5 * 1024 && ratio >= 4.05){
			title = "Ultimate_User";
			cout << title << endl;
			continue;
		}
		if (title == "Ultimate_User" && week >= 80 && dowload >= 1.5*1024 && ratio >= 3.95){
			cout << title << endl;
			continue;
		}
		if (title == "Ultimate_User" && week >= 80 && dowload >= 1.5*1024 && ratio < 3.95){
			title = "Extreme_User";
		}
		if (week >= 60 && dowload >= 1024 && ratio >= 3.55){
			title = "Extreme_User";
			cout << title << endl;
			continue;
		}
		if (title == "Extreme_User" && week >= 60 && dowload >= 1024 && ratio >= 3.45){
			cout << title << endl;
			continue;
		}
		if (title == "Extreme_User" && week >= 60 && dowload >= 1024 && ratio < 3.45){
			title = "Veteran_User";
		}
		if (week >= 40 && dowload >= 750 && ratio >= 3.05){
			title = "Veteran_User";
			cout << title << endl;
			continue;
		}
		if (title == "Veteran_User" && week >= 40 && dowload >= 750 && ratio >= 2.95){
			cout << title << endl;
			continue;
		}
		if (title == "Veteran_User" && week >= 40 && dowload >= 750 && ratio < 2.95){
			title = "Insane_User";
		}
		if (week >= 25 && dowload >= 500 && ratio >= 2.55){
			title = "Insane_User";
			cout << title << endl;
			continue;
		}
		if (title == "Insane_User" && week >= 25 && dowload >= 500 && ratio >= 2.45){
			cout << title << endl;
			continue;
		}
		if (title == "Insane_User" && week >= 25 && dowload >= 500 && ratio < 2.45){
			title = "Crazy_User";
		}
		if (week >= 15 && dowload >= 300 && ratio >= 2.05){
			title = "Crazy_User";
			cout << title << endl;
			continue;
		}
		if (title == "Crazy_User" && week >= 15 && dowload >= 300 && ratio >= 1.95){
			cout << title << endl;
			continue;
		}
		if (title == "Crazy_User" && week >= 15 && dowload >= 300 && ratio < 1.95){
			title = "Elite_User";
		}
		if (week >= 8 && dowload >= 120 && ratio >= 1.55){
			title = "Elite_User";
			cout << title << endl;
			continue;
		}
		if (title == "Elite_User" && week >= 8 && dowload >= 120 && ratio >= 1.45){
			cout << title << endl;
			continue;
		}
		if (title == "Elite_User" && week >= 8 && dowload >= 120 && ratio < 1.45){
			title = "Power_User";
		}
		if (week >= 4 && dowload >= 50 && ratio >= 1.05){
			title = "Power_User";
			cout << title << endl;
			continue;
		}
		if (title == "Power_User" && week >= 4 && dowload >= 50 && ratio >= 0.95){
			cout << title << endl;
			continue;
		}
		if (title == "Power_User" && week >= 4 && dowload >= 50 && ratio < 0.95){
			title = "User";
			cout << title << endl;
			continue;
		}
		if (dowload < 50){
			title = "User";
			cout << title << endl;
			continue;
		}
		cout << title << endl;
	}
	return 0;
}
