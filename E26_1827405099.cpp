#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

//定义类

class CAount
{
private:
    double m_Money;
    int year;
    int month;
    int day;
    static double m_InterestRate;

public:
    static void SetInterestRate();
    static double GetInterestRate();
    void SaveMoney(double money, int y,int m,int d);
    void LendMoney(double money,int y,int m,int d);
    void CalcInterest(int y,int m,int d);
    void SaveInterset(int y,int m,int d);
    void print();
};

double CAount::m_InterestRate=0;//静态数据成员在类外分配空间和初始化

void CAount::SetInterestRate()
{
    double rate;

    cout<<"Rate?"<<endl;
    cin>>rate;
    m_InterestRate=rate;
}

double CAount::GetInterestRate()
{
    cout<<"Interest Rate:"<<m_InterestRate<<endl;
    return m_InterestRate;
}

void CAount::SaveMoney(double money,int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    m_Money=money;
}

void CAount::LendMoney(double money,int y,int m,int d)
{
    int days;
    double interest;

     if(d<day)
    {
        d+=30;
        m-=1;
        if(m<month)
        {
            m+=12;
            y-=1;
        }
    }
    days=(y-year)*360+(m-month)*30+d-day+1;
    interest=money*(m_InterestRate/360)*days;
    if(m_Money-money>=0)
    {
        m_Money-=money;
        cout<<"Pop out:"<<money+interest<<endl;
    }
    else
        cout<<"Insufficient account balance.Request denied."<<endl;
}

void CAount::CalcInterest(int y,int m,int d)
{
    int days;
    double interest;

    if(d<day)
    {
        d+=30;
        m-=1;
        if(m<month)
        {
            m+=12;
            y-=1;
        }
    }
    days=(y-year)*360+(m-month)*30+d-day+1;
    interest=m_Money*(m_InterestRate/360.0)*days;
    cout<<"Interest:"<<interest<<endl;
}

void CAount::SaveInterset(int y,int m,int d)
{
    int days;
    double interest;

     if(d<day)
    {
        d+=30;
        m-=1;
        if(m<month)
        {
            m+=12;
            y-=1;
        }
    }
    days=(y-year)*360+(m-month)*30+d-day+1;
    interest=m_Money*(m_InterestRate/360.0)*days;
    m_Money+=interest;
    year=y;
    month=m;
    day=d;
}

void CAount::print()
{
    cout<<year<<"-"<<month<<"-"<<day<<endl;
    cout<<"Account balance:"<<m_Money<<endl;
}

//主调函数

int main()
{
    CAount MMM;
    double rate;

    CAount::SetInterestRate();
    rate=CAount::GetInterestRate();
    MMM.SaveMoney(100000,2014,1,1);
    MMM.print();
    MMM.CalcInterest(2014,3,10);
    MMM.print();
    MMM.SaveInterset(2014,3,10);
    MMM.print();
    MMM.LendMoney(200000,2014,3,30);
    MMM.print();
    MMM.LendMoney(50000,2014,4,4);
    MMM.print();
    return 0;
}
