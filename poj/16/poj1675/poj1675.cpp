/*************************************************************************
  > File Name: poj1675.cpp
  > Author: maemual
  > Mail: maemual@gmail.com 
  > Created Time: 2013年07月10日 星期三 15时56分11秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define PI acos(-1.0)
double Ang(int x1,int y1,int x2,int y2) //求向量（0,x1), (0, y1)与（0, x2), (0, y2)之间的夹角
{
	double a = x1 * x2 + y1 * y2;
	double b = sqrt((double)(x1 * x1 + y1 * y1));
	double c = sqrt((double)(x2 * x2 + y2 * y2));
	return acos((double)(a / (b * c))) / PI * 180;
}
double mod(double x)    //将角规范到0-180度之间,向量之间的夹角范围为[0, 180）
{
	if(x < 0) x += 360;
	if(x >= 360) x -= 360;
	if(x > 180) x=360 - x;
	return x;
}
int main()
{
	int r, x1, y1, x2, y2, x3, y3, cases;
	cin >> cases;
	while(cases --) {
		cin >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0)){
			cout << "No" << endl; //如果原点有berry
			continue;
		}
		double max = mod(Ang(x1, y1, x2, y2));
		if(max < mod(Ang(x1,y1,x3,y3))) 
			max = mod(Ang(x1,y1,x3,y3));
		if(max < mod(Ang(x2, y2, x3, y3))) 
			max = mod(Ang(x2, y2, x3, y3));
		if(max >= 120) 
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	return(0);
}
