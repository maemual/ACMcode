/*
ID: maemual
PROB: checker
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int n;
int upperlim,sum=0;
int list[3][13];
const int any[]={0x55555555,0x33333333,0x0F0F0F0F,0x00FF00FF,0x0000FFFF};
inline int number(int row)
{
     row=(row&any[0])+((row>>1)&any[0]);
     row=(row&any[1])+((row>>2)&any[1]);
     row=(row&any[2])+((row>>4)&any[2]);
     row=(row&any[3])+((row>>8)&any[3]);
     row=(row&any[4])+((row>>16)&any[4]);
     return row;
}
void test(int row,int ld,int rd)
{
     int pos,p;
     if(row!=upperlim)
     {
          pos=upperlim & ~(row|ld|rd);
          while(pos)
          {
                 p=pos & -pos;
                 pos-=p;
                 if(sum<3)
                 {
                          int num=number(row),pnt=log2(p)+1;
                          for(int i=sum;i<3;i++)
                          list[i][num]=pnt;
                 }
                 test(row+p,(ld+p)<<1,(rd+p)>>1);
          }
     }
     else
     {
         sum++;
     }
}
int main()
{
    ifstream fin("checker.in");
    ofstream fout("checker.out");
    fin>>n;
    upperlim=(1<<n)-1;
    test(0,0,0);
    for(int i=0;i<3;i++){
    fout<<list[i][0];
    for(int j=1;j<n;j++)
    fout<<' '<<list[i][j];
    fout<<endl;}
    fout<<sum<<endl;
    return 0;
}
