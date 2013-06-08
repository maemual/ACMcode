#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef struct color
{
	int R,B,G;
}color;
double getdis(color s,int xx,int yy,int zz )
{
	return pow(s.R-xx,2)+pow(s.B-yy,2)+pow(s.G-zz,2);
}
int main()
{
	vector<color> se(16);
	for (vector<color>::size_type i = 0; i < 16; ++i)
		cin >> se[i].R >> se[i].B >> se[i].G;
	while (1)
	{
		int x,y,z;
		cin >> x >> y >> z;
		if (x < 0)
		  return 0;
		double min = 200000;
		double distance;
		int mx,my,mz;
		mx = my = mz = 0;
		for (vector<color>::size_type ix = 0;ix < 16 ;++ix)
		{
			distance = getdis(se[ix],x,y,z);
			if (min > distance )
			{
				min = distance;
				mx = se[ix].R;
				my = se[ix].B;
				mz = se[ix].G;
			}
		}
		cout << '(' << x << ',' << y << ',' << z << ") " 
			<< "maps to (" << mx << ',' << my << ',' << mz << ')' << endl;
	}
}
