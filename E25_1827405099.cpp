#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

//������

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

//���Ժ���

void func1(const vector<CComplex>& D)
{
    int p;
    CComplex temp;

    cout<<"��ѡ��һ�����������С���ܸ�������"<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"��"<<p<<"��������ֵΪ��"<<"\n"<<temp<<endl;
}

void func2(const vector<CComplex>& D)
{
    int p,q;
    CComplex temp,temp1,temp2;

    cout<<"��ѡ���������������С���ܸ�������"<<endl;
    cin>>p>>q;
    temp1=D[p-1];
    temp2=D[q-1];
    cout<<"��"<<p<<"��������ֵΪ��"<<"\n"<<temp1<<endl;
    cout<<"��"<<q<<"��������ֵΪ��"<<"\n"<<temp2<<endl;
    temp=temp1+temp2;
    cout<<"���������֮��Ľ��Ϊ��"<<"\n"<<temp<<endl;
}

void func3(const vector<CComplex>& D)
{
    int p;
    double num;
    CComplex temp;

    cout<<"��ѡ��һ�����������С���ܸ�������"<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"��"<<p<<"��������ֵΪ��"<<"\n"<<temp<<endl;
    cout<<"����һ��ʵ����"<<endl;
    cin>>num;
    temp=temp+num;
    cout<<"������ʵ����ӵĽ��Ϊ��"<<temp<<endl;
}

void func4(const vector<CComplex>& D)
{
    int p;
    CComplex temp;

    cout<<"��ѡ��һ�����������С���ܸ�������"<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"��"<<p<<"��������ֵΪ��"<<"\n"<<temp<<endl;
    ++temp;
    cout<<"����ǰ���������ĸ���Ϊ��"<<"\n"<<temp<<endl;
}

void func5(const vector<CComplex>& D)
{
    int p;
    CComplex temp;

    cout<<"��ѡ��һ�����������С���ܸ�������"<<endl;
    cin>>p;
    temp=D[p-1];
    cout<<"��"<<p<<"��������ֵΪ��"<<"\n"<<temp<<endl;
    temp=temp++;
    cout<<"���к����������ĸ���Ϊ��"<<"\n"<<temp<<endl;
}

//��������

int main()
{
    int n;
    char judge='y';
    CComplex A;
    vector<CComplex> D;

    cout<<"�����븴���ĸ�����"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double a,b;
        cout<<"��"<<i<<"��������"<<endl;
        cout<<"�ֱ�����ʵ�����鲿��"<<endl;
        cin>>a>>b;
        A.setValue(a,b);
        D.push_back(A);
    }
    cout<<"��ʼ����ɣ�"<<endl;

    while(judge=='y')
    {
        cout<<"\n\n"<<"��ѡ�������Ŀ��\n����<<�����������1\n����+������������������2\n����+��������ʵ����������3\n����ǰ��++������4\n���غ���++������5\n";
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
        cout<<"�Ƿ�������ԣ�y or n"<<endl;
        cin>>judge;
    }
    return 0;
}
