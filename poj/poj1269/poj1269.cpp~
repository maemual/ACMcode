#include<iostream>
#include <cstdio>
using namespace std;
#define eps 1e-8

struct point
{
       double x;
       double y;
};


double det(double x1,double y1,double x2,double y2)  //叉乘
{
       return x1*y2-x2*y1;
}
double cross(point a,point b,point c)              //叉乘
{
       return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

bool  interset(point a,point b,point c,point d)    //判断两条直线是否相交
{
       double temp;
       temp=(a.y-b.y)*(c.x-d.x)-(a.x-b.x)*(c.y-d.y);
       temp=temp>0? temp:-temp;
       if(temp<eps) return false;    //两条直线不相交

       else return true;                  //两条直线相交
}


int main()
{
      int N,i;
      point a,b,c,d;
      double k1,k2,temp,x,y;
    
     cin>>N;
     printf("INTERSECTING LINES OUTPUT\n");
     for(i=0;i<N;i++)
     {
          cin>>a.x>>a.y;
          cin>>b.x>>b.y;
          cin>>c.x>>c.y;
          cin>>d.x>>d.y;
          if(!interset(a,b,c,d))   //不相交

          {  
                   temp=cross(a,b,c)>0? cross(a,b,c):-cross(a,b,c);  //可能重合，也可能平行
                   if(temp<eps)   //只要判断任意三点是否一线即可，如果一线，temp=0
                        cout<<"LINE"<<endl;
                   else           
                        cout<<"NONE"<<endl;
          }
          else                          //相交
          {
                   printf("POINT ");
                   if(a.x==b.x)          
                   {
                          k1=(c.y-d.y)/(c.x-d.x);
                          x=a.x;
                          y=k1*(x-d.x)+d.y;
                          printf("%.2lf %.2lf\n",x,y);
                   }
                  else if(c.x==d.x)
                  {
                         k1=(a.y-b.y)/(a.x-b.x);
                         x=c.x;
                         y=k1*(x-b.x)+b.y;
                         printf("%.2lf %.2lf\n",x,y);
                  }
                  else 
                  {
                        k1=(a.y-b.y)/(a.x-b.x);
                        k2=(c.y-d.y)/(c.x-d.x);
                        x=(d.y-b.y+k1*b.x-k2*d.x)/(k1-k2);
                        y=(k1*k2*(b.x-d.x)-k2*b.y+k1*d.y)/(k1-k2);//这里只要是依公式化简
                        printf("%.2lf %.2lf\n",x,y);            

                  }
          }   
     }
    printf("END OF OUTPUT\n");
    return 0;
}
