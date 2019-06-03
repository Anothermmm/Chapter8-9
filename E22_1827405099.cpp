#include <iostream>
#include <iomanip>
#include <math.h>
#define pi 3.14159

using namespace std;

class Circle
{
    double x;
    double y;
    double r;
public:
    void setcoordinate(double xx,double yy);
    void setr(double rr);
    double C();
    double S();
};

void Circle::setcoordinate(double xx,double yy)
{
    x=xx;
    y=yy;
}

void Circle::setr(double rr)
{
    r=rr;
}

double Circle::C()
{
    double c;
    c=2*pi*r;
    return c;
}

double Circle::S()
{
    double s;
    s=pi*pow(r,2.0);
    return s;
}

int main()
{
    Circle A;
    double xx,yy,rr,c,s;

	cout<<"输入坐标：（用空格分开）"<<endl;
	cin>>xx>>yy;
    A.setcoordinate(xx,yy);
	cout<<"输入半径："<<endl;
	cin>>rr;
    A.setr(rr);
    c=A.C();
    s=A.S();
    cout<<"周长为:"<<c<<endl;
    cout<<"面积为:"<<s<<endl;
    return 0;
}
