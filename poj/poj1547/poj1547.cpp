#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
int main()
{
    /* ����map���� */
    map<int, string> child;
    int i, a, b, c, n;
    string name;
    while(1)
    {
        cin >> n;
        if (n == -1) break;
 
        /* ������� */
        child.clear();
 
        for (i = 0; i < n; i++)
        {
            cin >> a >> b >> c >> name;
 
            /* ʹ��insert�������Ӽ�ֵ��,���Զ�������ʵ�λ��*/
            child.insert(map<int, string>::value_type(a * b * c, name));
        }
 
        /* �����Ѿ��ź���,ֱ�������һ�������һ����ֵ�Լ��� */
        cout << child.rbegin()->second + " took clay from " + child.begin()->second + "." << endl;
    }
    //system("pause");
    return 0;
}

