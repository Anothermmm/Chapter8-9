#include <iostream>
#include <math.h>
#define pi 3.14159

using namespace std;

class Column
{
    double x;
    double y;
    double r;
    double h;
public:
    void set(double xx,double yy,double rr,double hh);
    double unders();
    double underc();
    double sides();
    double V();
};

void Column::set(double xx,double yy,double rr,double hh)
{
    x=xx;y=yy;r=rr;h=hh;
}

double Column::unders()
{
    return pi*pow(r,2.0);
}

double Column::underc()
{
    return 2*pi*r;
}

double Column::sides()
{
    return h*Column::underc();
}

double Column::V()
{
    return h*Column::unders();
}

int main()
{
    Column A;
    double xx,yy,rr,hh;
    double us,uc,v,vs;

    cout<<"输入坐标：(空格分开）"<<endl;
    cin>>xx>>yy;
    cout<<"输入半径和高：(空格分开）"<<endl;
    cin>>rr>>hh;
    A.set(xx,yy,rr,hh);
    vs=A.sides();
    uc=A.underc();
    us=A.unders();
    v=A.V();
    cout<<"圆柱A的"<<endl;
    cout<<"底面积："<<uc<<endl;
    cout<<"底面周长："<<uc<<endl;
    cout<<"侧面积："<<vs<<endl;
    cout<<"体积："<<v<<endl;
    return 0;
}