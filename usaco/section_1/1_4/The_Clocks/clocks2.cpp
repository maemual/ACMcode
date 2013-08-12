/*
ID: maemual
PROG: clocks
LANG: C++
*/
#include <fstream>
#include <vector>
using namespace std;
 
typedef long Clocks;
const long MOVE[10] = {0, 18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};
const long CLEAR = 57521883;
 
void init(ifstream &fin, Clocks & clocks);
bool can_match(Clocks clocks, vector<int> trans);
int length(vector<int> ivec);
vector<int> get_result(Clocks clocks);
 
int main()
{
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");
 
    Clocks clocks = 0;
    init(fin, clocks);
 
    vector<int> result = get_result(clocks);
    for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
        fout << *iter;
        if (iter + 1 != result.end())
            fout << ' ';
    }
    fout << endl;
 
    return 0;
}
 
 
// 读入时钟并将所有时钟的数据转化成一个long,每个时钟占3位
void init(ifstream &fin, Clocks & clocks)
{
    int time, t;
    long bit = 16777216;
    while (fin >> time) {
        switch (time) {
            case 12:
                t = 0;
                break;
            case 3:
                t = 1;
                break;
            case 6:
                t = 2;
                break;
            case 9:
                t = 3;
                break;
        }
        clocks = clocks | (t * bit);
        bit /= 8;
    }
}
vector<int> get_result(Clocks clocks)
{
    int min_length = 28;
    vector<int> trans(10, 0), answer;  // trans保存了9种变换每一种变换的次数
    for (int t9 = 0; t9 <= 3; ++t9)
        for (int t8 = 0; t8 <= 3; ++t8)
            for (int t7 = 0; t7 <= 3; ++t7)
                for (int t6 = 0; t6 <= 3; ++t6)
                    for (int t5 = 0; t5 <= 3; ++t5)
                        for (int t4 = 0; t4 <= 3; ++t4)
                            for (int t3 = 0; t3 <= 3; ++t3)
                                for (int t2 = 0; t2 <= 3; ++t2)
                                    for (int t1 = 0; t1 <= 3; ++t1) {  // 用这种顺序枚举,能保证同样长度的解,最小的一定在最前面
                                        trans[1] = t1;
                                        trans[2] = t2;
                                        trans[3] = t3;
                                        trans[4] = t4;
                                        trans[5] = t5;
                                        trans[6] = t6;
                                        trans[7] = t7;
                                        trans[8] = t8;
                                        trans[9] = t9;
 
                                        if (can_match(clocks, trans))
                                            if (length(trans) < min_length) {
                                                answer = trans;
                                                min_length = length(trans);
                                            }
                                    }
 
    vector<int> result;
    for (int i = 1, counter; i <= 9; ++i) {  // 把trans类型的解转成题目要求要求的形式
        counter = answer[i];
        while (counter) {
            result.push_back(i);
            --counter;
        }
    }
    return result;
}
 
bool can_match(Clocks clocks, vector<int> trans)
{
    // 按位转化每个时钟,全部12点是clocks恰好为0
    for (int i = 1, counter; i <= 9; ++i) {
        counter = trans[i];
        while (counter) {
            clocks = (clocks + MOVE[i]) & CLEAR;
            --counter;
        }
    }
    return clocks == 0;
}
 
int length(vector<int> ivec)
{
    // 计算trans形式的解转化成题目要求的形式之后的,解的长度
    int length = 0;
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        length += *iter;
    return length;
}
