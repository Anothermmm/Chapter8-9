#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#define pi 3.14159

using namespace std;

//������

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
    friend Circle operator+(const Circle& a, const Circle& b);
    friend Circle operator-(const Circle& a, const Circle& b);
    friend Circle& operator++(Circle& a);
    friend Circle& operator++(Circle& a,int);
    friend ostream& operator<<(ostream& o, Circle& t);
    friend bool operator>(Circle& a, Circle& b);
    friend bool operator<(Circle& a, Circle& b);
    friend bool operator==(Circle& a, Circle& b);
    friend bool operator!=(Circle& a, Circle& b);
    friend bool operator&(Circle& a, Circle& b);
    friend void operator|(Circle& a, Circle& b);
};

//���崴��Բ�Ĺ���

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

//�������������
Circle operator+(const Circle& a, const Circle& b)
{
    Circle s;

    s.setcoordinate(a.x,a.y);//��Ϊ����Ԫ���������Կ��Լ�ӷ���private������
    s.setr(a.r+b.r);
    return s;
}

Circle operator-(const Circle& a, const Circle& b)
{
    Circle s;

    s.setcoordinate(a.x,a.y);
    s.setr(fabs(a.r-b.r));
    return s;
}

Circle& operator++(Circle& a)//ǰ����
{
    ++a.r;
    return a;
}

Circle& operator++(Circle& a,int)//������
{
    Circle t(a);
    t.r++;
    return t;
}

ostream& operator<<(ostream& o, Circle& t)//���ﲻ������const Circle����Ȼ�ͱ���
{
    return o<<"Բ�����꣺("<<t.x<<","<<t.y<<")"<<"\n"<<"�뾶��"<<t.r<<"\n"<<"�ܳ���"<<t.C()<<"\n"<<"�����"<<t.S()<<endl;
}

bool operator>(Circle& a, Circle& b)
{
    if(a.S()>b.S())
        return true;
    else
        return false;
}

bool operator<(Circle& a, Circle& b)
{
    if(a.S()<b.S())
        return true;
    else
        return false;
}

bool operator==(Circle& a, Circle& b)
{
    if(a.x==b.x && a.y==b.y && a.r==b.r)
        return true;
    else
        return false;
}

bool operator!=(Circle& a, Circle& b)
{
    if(a.x==b.x && a.y==b.y && a.r==b.r)
        return false;
    else
        return true;
}

bool operator&(Circle& a, Circle& b)
{
    if(a.x==b.x && a.y==b.y)
        return true;
    else
        return false;
}

void operator|(Circle& a, Circle& b)
{
    double s;

    s=sqrt(pow((a.x-b.x),2.0)+pow((a.y-b.y),2.0));
    if(s>(a.r+b.r))
        cout<<"����"<<endl;
    else if(s==(a.r+b.r))
        cout<<"����"<<endl;
    else if(s>fabs(a.r-b.r) && s<(a.r+b.r))
        cout<<"�ཻ"<<endl;
    else if(s==fabs(a.r-b.r) && s!=0)
        cout<<"����"<<endl;
    else if(s>=0 && s<fabs(a.r-b.r) && a.r!=b.r)
        cout<<"�ں�"<<endl;
    else
        cout<<"�غ�"<<endl;
}
//���Ժ���

void func1(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"ѡ������Բ������С���ܸ�������������p,q��"<<endl;
    cin>>p>>q;
    M=D[p-1]+D[q-1];
    N=D[p-1]-D[q-1];
    cout<<"\n"<<"Բ"<<p<<"��Բ"<<q<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    cout<<"�����ӷ�������Բ�ǣ�"<<"\n"<<M<<"\n"<<endl;
    cout<<"��������������Բ�ǣ�"<<"\n"<<N<<"\n"<<endl;
}

void func2(vector<Circle> &D)
{
    int p;
    Circle M,N;

    cout<<"\n"<<"ѡ��һ��Բ������С���ܸ�����һ������p��"<<endl;
    cin>>p;
    cout<<"\n"<<"Բ"<<p<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    M=D[p-1];
    N=D[p-1];
    ++M;
    N++;
    cout<<"ǰ�����������ԲΪ��"<<M<<"\n"<<endl;
    cout<<"�������������ԲΪ��"<<N<<"\n"<<endl;
}

void func3(vector<Circle> &D)
{
    int p;

    cout<<"\n"<<"ѡ��һ��Բ������С���ܸ�����һ������p��"<<endl;
    cin>>p;
    cout<<"\n"<<"Բ"<<p<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
}

void func4(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"ѡ������Բ������С���ܸ�������������p,q��"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"Բ"<<p<<"��Բ"<<q<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    if(M>N)
        cout<<"Բ"<<p<<"��"<<"\n"<<endl;
    else if(M<N)
        cout<<"Բ"<<q<<"��"<<"\n"<<endl;
    else
        cout<<"һ����"<<"\n"<<endl;
}

void func5(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"ѡ������Բ������С���ܸ�������������p,q��"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"Բ"<<p<<"��Բ"<<q<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    if(M==N)
        cout<<"��==�жϣ���ȫ��ͬ"<<"\n"<<endl;
    if(M!=N)
        cout<<"��!=�жϣ�����ȫ��ͬ"<<"\n"<<endl;
}

void func6(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"ѡ������Բ������С���ܸ�������������p,q��"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"Բ"<<p<<"��Բ"<<q<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    if(M&N)
        cout<<"ͬ��Բ"<<"\n"<<endl;
    else
        cout<<"��ͬ��Բ"<<"\n"<<endl;
}

void func7(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"ѡ������Բ������С���ܸ�������������p,q��"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"Բ"<<p<<"��Բ"<<q<<"�Ĳ������£�"<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    M|N;
}

int main()
{
    vector<Circle> D;
    int n;
    Circle A,B,C;
    double xx,yy,rr,c,s;
    char judge='y';

    cout<<"����Բ�ĸ�����"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Բ"<<i<<":"<<endl;
        cout<<"�������꣺���ÿո�ֿ���"<<endl;
        cin>>xx>>yy;
        A.setcoordinate(xx,yy);
        cout<<"����뾶��"<<endl;
        cin>>rr;
        A.setr(rr);
        D.push_back(A);
    }
    cout<<"��ʼ�����!"<<endl;

    while(judge=='y')
    {
        int xuhao;
        cout<<"\n\n\n"<<"��ѡ�������Ҫִ�еĲ�����"<<endl;
        cout<<"�Ӽ������㣺����1\n�����Լ����㣺����2\n��������㣺����3\n��С�����㣺����4\nȫ�Ȳ�ȫ�����㣺����5\n�ж�ͬ�����㣺����6\nȷ��λ�����㣺����7\n";
        cin>>xuhao;
        switch(xuhao)
        {
            case(1): func1(D);break;
            case(2): func2(D);break;
            case(3): func3(D);break;
            case(4): func4(D);break;
            case(5): func5(D);break;
            case(6): func6(D);break;
            case(7): func7(D);break;
            default: cout<<"error!"<<endl;
        }
        cout<<"�Ƿ�������ԣ�y  or  n?"<<endl;
        cin>>judge;
    }
    return 0;
}
