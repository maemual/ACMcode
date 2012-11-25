#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
    string a1[]={"Gengshen",
                "Xinyou","Renxu","Guihai","Jiazi","Yichou","Bingyin","Dingmao","Wuchen","Jisi","Gengwu",
                "Xinwei","Renshen","Guiyou","Jiaxu","Yihai","Bingzi","Dingchou","Wuyin","Jimao","Gengchen",
                "Xinsi","Renwu","Guiwei","Jiashen","Yiyou","Bingxu","Dinghai","Wuzi","Jichou","Gengyin",
                "Xinmao","Renchen","Guisi","Jiawu","Yiwei","Bingshen","Dingyou","Wuxu","Jihai","Gengzi",
                "Xinchou","Renyin","Guimao","Jiachen","Yisi","Bingwu","Dingwei","Wushen","Jiyou","Gengxu",
                "Xinhai","Renzi","Guichou","Jiayin","Yimao","Bingchen","Dingsi","Wuwu","Jiwei","Gengshen"};

    string a2[]={"Xinyou","Renxu","Guihai","Jiazi","Yichou","Bingyin","Dingmao","Wuchen","Jisi","Gengwu",
                "Xinwei","Renshen","Guiyou","Jiaxu","Yihai","Bingzi","Dingchou","Wuyin","Jimao","Gengchen",
                "Xinsi","Renwu","Guiwei","Jiashen","Yiyou","Bingxu","Dinghai","Wuzi","Jichou","Gengyin",
                "Xinmao","Renchen","Guisi","Jiawu","Yiwei","Bingshen","Dingyou","Wuxu","Jihai","Gengzi",
                "Xinchou","Renyin","Guimao","Jiachen","Yisi","Bingwu","Dingwei","Wushen","Jiyou","Gengxu",
                "Xinhai","Renzi","Guichou","Jiayin","Yimao","Bingchen","Dingsi","Wuwu","Jiwei","Gengshen",
                "Xinyou"};
    int t;
    cin >> t;
    while (t--)
    {
        int year;
        cin >> year;
        if (year > 0)
            cout << a1[year % 60] << endl;
        else
            cout << a2[60 - abs(year) % 60] << endl;
    }
    return 0;
}
