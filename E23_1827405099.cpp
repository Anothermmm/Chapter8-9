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

    cout<<"�������꣺(�ո�ֿ���"<<endl;
    cin>>xx>>yy;
    cout<<"����뾶�͸ߣ�(�ո�ֿ���"<<endl;
    cin>>rr>>hh;
    A.set(xx,yy,rr,hh);
    vs=A.sides();
    uc=A.underc();
    us=A.unders();
    v=A.V();
    cout<<"Բ��A��"<<endl;
    cout<<"�������"<<uc<<endl;
    cout<<"�����ܳ���"<<uc<<endl;
    cout<<"�������"<<vs<<endl;
    cout<<"�����"<<v<<endl;
    return 0;
}