#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
int main()
{
    /* 创建map容器 */
    map<int, string> child;
    int i, a, b, c, n;
    string name;
    while(1)
    {
        cin >> n;
        if (n == -1) break;
 
        /* 清空容器 */
        child.clear();
 
        for (i = 0; i < n; i++)
        {
            cin >> a >> b >> c >> name;
 
            /* 使用insert方法增加键值对,会自动插入合适的位置*/
            child.insert(map<int, string>::value_type(a * b * c, name));
        }
 
        /* 由于已经排好序,直接输出第一个和最后一个键值对即可 */
        cout << child.rbegin()->second + " took clay from " + child.begin()->second + "." << endl;
    }
    //system("pause");
    return 0;
}

