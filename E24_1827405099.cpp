#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#define pi 3.14159

using namespace std;

//定义类

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

//定义创建圆的功能

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

//定义重载运算符
Circle operator+(const Circle& a, const Circle& b)
{
    Circle s;

    s.setcoordinate(a.x,a.y);//因为是友元函数，所以可以间接访问private的内容
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

Circle& operator++(Circle& a)//前增量
{
    ++a.r;
    return a;
}

Circle& operator++(Circle& a,int)//后增量
{
    Circle t(a);
    t.r++;
    return t;
}

ostream& operator<<(ostream& o, Circle& t)//这里不让我用const Circle，不然就报错
{
    return o<<"圆心坐标：("<<t.x<<","<<t.y<<")"<<"\n"<<"半径："<<t.r<<"\n"<<"周长："<<t.C()<<"\n"<<"面积："<<t.S()<<endl;
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
        cout<<"相离"<<endl;
    else if(s==(a.r+b.r))
        cout<<"外切"<<endl;
    else if(s>fabs(a.r-b.r) && s<(a.r+b.r))
        cout<<"相交"<<endl;
    else if(s==fabs(a.r-b.r) && s!=0)
        cout<<"内切"<<endl;
    else if(s>=0 && s<fabs(a.r-b.r) && a.r!=b.r)
        cout<<"内含"<<endl;
    else
        cout<<"重合"<<endl;
}
//测试函数

void func1(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"选择两个圆（输入小于总个数的两个整数p,q）"<<endl;
    cin>>p>>q;
    M=D[p-1]+D[q-1];
    N=D[p-1]-D[q-1];
    cout<<"\n"<<"圆"<<p<<"和圆"<<q<<"的参数如下："<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    cout<<"经过加法运算后的圆是："<<"\n"<<M<<"\n"<<endl;
    cout<<"经过减法运算后的圆是："<<"\n"<<N<<"\n"<<endl;
}

void func2(vector<Circle> &D)
{
    int p;
    Circle M,N;

    cout<<"\n"<<"选择一个圆（输入小于总个数的一个整数p）"<<endl;
    cin>>p;
    cout<<"\n"<<"圆"<<p<<"的参数如下："<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    M=D[p-1];
    N=D[p-1];
    ++M;
    N++;
    cout<<"前增量操作后的圆为："<<M<<"\n"<<endl;
    cout<<"后增量操作后的圆为："<<N<<"\n"<<endl;
}

void func3(vector<Circle> &D)
{
    int p;

    cout<<"\n"<<"选择一个圆（输入小于总个数的一个整数p）"<<endl;
    cin>>p;
    cout<<"\n"<<"圆"<<p<<"的参数如下："<<"\n"<<endl;
    cout<<D[p-1]<<endl;
}

void func4(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"选择两个圆（输入小于总个数的两个整数p,q）"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"圆"<<p<<"和圆"<<q<<"的参数如下："<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    if(M>N)
        cout<<"圆"<<p<<"大"<<"\n"<<endl;
    else if(M<N)
        cout<<"圆"<<q<<"大"<<"\n"<<endl;
    else
        cout<<"一样大"<<"\n"<<endl;
}

void func5(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"选择两个圆（输入小于总个数的两个整数p,q）"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"圆"<<p<<"和圆"<<q<<"的参数如下："<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    if(M==N)
        cout<<"（==判断）完全相同"<<"\n"<<endl;
    if(M!=N)
        cout<<"（!=判断）不完全相同"<<"\n"<<endl;
}

void func6(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"选择两个圆（输入小于总个数的两个整数p,q）"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"圆"<<p<<"和圆"<<q<<"的参数如下："<<"\n"<<endl;
    cout<<D[p-1]<<endl;
    cout<<D[q-1]<<endl;
    if(M&N)
        cout<<"同心圆"<<"\n"<<endl;
    else
        cout<<"非同心圆"<<"\n"<<endl;
}

void func7(vector<Circle> &D)
{
    int p,q;
    Circle M,N;

    cout<<"\n"<<"选择两个圆（输入小于总个数的两个整数p,q）"<<endl;
    cin>>p>>q;
    M=D[p-1];
    N=D[q-1];
    cout<<"\n"<<"圆"<<p<<"和圆"<<q<<"的参数如下："<<"\n"<<endl;
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

    cout<<"输入圆的个数："<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"圆"<<i<<":"<<endl;
        cout<<"输入坐标：（用空格分开）"<<endl;
        cin>>xx>>yy;
        A.setcoordinate(xx,yy);
        cout<<"输入半径："<<endl;
        cin>>rr;
        A.setr(rr);
        D.push_back(A);
    }
    cout<<"初始化完成!"<<endl;

    while(judge=='y')
    {
        int xuhao;
        cout<<"\n\n\n"<<"请选择接下来要执行的操作："<<endl;
        cout<<"加减法运算：输入1\n自增自减运算：输入2\n输出流运算：输入3\n大小于运算：输入4\n全等不全等运算：输入5\n判断同心运算：输入6\n确定位置运算：输入7\n";
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
        cout<<"是否继续测试？y  or  n?"<<endl;
        cin>>judge;
    }
    return 0;
}
