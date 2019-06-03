#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

//定义类

class CComplex
{
    double m_real;
    double m_image;
public:
    void setValue(double real,double image)
    {
        m_real=real;
        m_image=image;
    }
    friend ostream& operator<<(ostream& o,const CComplex& a);
    friend CComplex operator+(const CComplex& a, const CComplex& b);
    friend CComplex operator+(const CComplex& a, double x);
    friend CComplex operator+(double x, const CComplex& a);
    friend CComplex& operator++(CComplex& a);
    friend CComplex operator++(CComplex& a, int);
};

ostream& operator<<(ostream& o, const CComplex& a)
{
    return o<<a.m_real<<"+"<<a.m_image<<"i"<<endl;
}

CComplex operator+(const CComplex& a, const CComplex& b)
{
    CComplex t;

    t.m_real=a.m_real+b.m_real;
    t.m_image=a.m_image+b.m_image;
    return t;
}

CComplex operator+(const CComplex& a, double x)
{
    CComplex t;

    t.m_real=a.m_real+x;
    t.m_image=a.m_image;
    return t;
}

CComplex operator+(double x, const CComplex& a)
{
    CComplex t;

    t.m_real=a.m_real+x;
    t.m_image=a.m_image;
    return t;
}

CComplex& operator++(CComplex& a)
{
    ++a.m_real;
    ++a.m_image;
    return a;
}

CComplex operator++(CComplex& a, int)
{
    CComplex t(a);

    t.m_real=a.m_real+1;
    t.m_image=a.m_image+1;
    return t;
}

//测试函数

void func1(const vector<CComplex>& D)
{
    int p;
    CComplex temp;

    cout<<"请选择一个复数（序号小于总个数）："<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"第"<<p<<"个复数的值为："<<"\n"<<temp<<endl;
}

void func2(const vector<CComplex>& D)
{
    int p,q;
    CComplex temp,temp1,temp2;

    cout<<"请选择两个复数（序号小于总个数）："<<endl;
    cin>>p>>q;
    temp1=D[p-1];
    temp2=D[q-1];
    cout<<"第"<<p<<"个复数的值为："<<"\n"<<temp1<<endl;
    cout<<"第"<<q<<"个复数的值为："<<"\n"<<temp2<<endl;
    temp=temp1+temp2;
    cout<<"两复数求和之后的结果为："<<"\n"<<temp<<endl;
}

void func3(const vector<CComplex>& D)
{
    int p;
    double num;
    CComplex temp;

    cout<<"请选择一个复数（序号小于总个数）："<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"第"<<p<<"个复数的值为："<<"\n"<<temp<<endl;
    cout<<"输入一个实数："<<endl;
    cin>>num;
    temp=temp+num;
    cout<<"复数和实数相加的结果为："<<temp<<endl;
}

void func4(const vector<CComplex>& D)
{
    int p;
    CComplex temp;

    cout<<"请选择一个复数（序号小于总个数）："<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"第"<<p<<"个复数的值为："<<"\n"<<temp<<endl;
    ++temp;
    cout<<"进行前增量运算后的复数为："<<"\n"<<temp<<endl;
}

void func5(const vector<CComplex>& D)
{
    int p;
    CComplex temp;

    cout<<"请选择一个复数（序号小于总个数）："<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"第"<<p<<"个复数的值为："<<"\n"<<temp<<endl;
    temp=temp++;
    cout<<"进行后增量运算后的复数为："<<"\n"<<temp<<endl;
}

//主调函数

int main()
{
    int n;
    char judge='y';
    CComplex A;
    vector<CComplex> D;

    cout<<"请输入复数的个数："<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double a,b;
        cout<<"第"<<i<<"个复数："<<endl;
        cout<<"分别输入实部和虚部："<<endl;
        cin>>a>>b;
        A.setValue(a,b);
        D.push_back(A);
    }
    cout<<"初始化完成！"<<endl;

    while(judge=='y')
    {
        cout<<"\n\n"<<"请选择测试项目：\n重载<<运算符：输入1\n重载+（两个复数）：输入2\n重载+（复数和实数）：输入3\n重载前置++：输入4\n重载后置++：输入5\n";
        int xuhao;
        cin>>xuhao;
        switch(xuhao)
        {
            case(1): func1(D);break;
            case(2): func2(D);break;
            case(3): func3(D);break;
            case(4): func4(D);break;
            case(5): func5(D);break;
            default: cout<<"Error!"<<endl;
        }
        cout<<"是否继续测试？y or n"<<endl;
        cin>>judge;
    }
    return 0;
}
