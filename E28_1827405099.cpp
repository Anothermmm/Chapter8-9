#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CTime
{
    int m_hour,m_minute,m_second;
public:
    CTime(int hour=0,int minute=0,int second=0);//���ʱ��Ϸ�����ֵ������ֵ 0 ʱ 0 �� 0 ��
    int SetTime(int hour=0,int minute=0,int second=0);//���ʱ��Ϸ�����ֵ������ 1�����򲻸�ֵ�������� 0
    int getHour(){return m_hour;}
    int getMinute(){return m_minute;}
    int getSecond(){return m_second;}
    void ShowTime(bool flag);//flag Ϊ True ���� 24 Сʱ����ʾʱ�䣬������ AM PM �ķ�ʽ��ʾ
    //�Լ������Ƿ���Ҫ���������Ա����
};

CTime::CTime(int hour,int minute,int second)
{
    if(hour>23 || hour<0 || minute>59 || minute<0 || second>59 || second<0)
    {
        m_hour=0;
        m_minute=0;
        m_second=0;
    }
    else
    {
        m_hour=hour;
        m_minute=minute;
        m_second=second;
    }
}

int CTime::SetTime(int hour,int minute,int second)
{
    if(hour>23 || hour<0 || minute>59 || minute<0 || second>59 || second<0)
    {
        return 0;
    }
    else
    {
        m_hour=hour;
        m_minute=minute;
        m_second=second;
        return 1;
    }
}

void CTime::ShowTime(bool flag)
{
    if(flag==true)
    {
        cout<<setw(2)<<setfill('0')<<m_hour<<":"<<setw(2)<<m_minute<<":"<<setw(2)<<m_second<<endl;
    }
    else
    {
        if(m_hour>12)
        {
            cout<<"PM:"<<setw(2)<<setfill('0')<<m_hour-12<<":"<<setw(2)<<m_minute<<":"<<setw(2)<<m_second<<endl;
        }
        else
        {
            cout<<"AM:"<<setw(2)<<setfill('0')<<m_hour-12<<":"<<setw(2)<<m_minute<<":"<<setw(2)<<m_second<<endl;
        }
    }
}

class CDate
{
    int m_year,m_month,m_day;
public:
    CDate(int year=2000,int month=1,int day=1);//������ںϷ�����ֵ������ֵ 2000 �� 1 �� 1 ��
    int SetDate(int year=2000,int month=1,int day=1);//������ںϷ�����ֵ������ 1�����򲻸�ֵ�������� 0
    int GetYear(){return m_year;}
    int GetMonth(){return m_month;}
    int GetDay(){return m_day;}
    void ShowDate(bool flag);
//flag Ϊ TRUE���������ĵķ�ʽ��ʾ���ڣ������� MM/DD/YYYY �ķ�ʽ��ʾ����
//�Լ������Ƿ���Ҫ���������Ա����
};

bool is_legal_date(int year, int mon, int day)
{
    if(year<0 || mon<0 || mon>12 || day<0 || day>31) return false;
    if(mon==1 || mon==3 || mon==5 || mon==7 || mon==8 || mon==10 || mon==12)
    {
        if(day<32) return true;
        else return false;
    }
    if(mon==2)
    {
        if((year%4==0 && year%100!=0) || (year%400==0))
        {
            if(day<30) return true;
            else return false;
        }
        else
        {
            if(day<29) return true;
            else return false;
        }
    }
    else
    {
        if(day<31) return true;
        else return false;
    }
}


CDate::CDate(int year,int month,int day)
{
    if(is_legal_date(year,month,day)==false);
    else
    {
        m_year=year;
        m_month=month;
        m_day=day;
    }
}

int CDate::SetDate(int year,int month,int day)
{
    if(is_legal_date(year,month,day)==false) return 0;
    else
    {
        m_year=year;
        m_month=month;
        m_day=day;
        return 1;
    }
}

void CDate::ShowDate(bool flag)
{
    if(flag==true)
    {
        cout<<m_year<<"��"<<m_month<<"��"<<m_day<<"��"<<endl;
    }
    else
    {
        cout<<setw(2)<<setfill('0')<<m_month<<"/"<<m_day<<"/"<<m_year<<endl;
    }
}

class CDateTime
{
    CTime m_time;
    CDate m_date;
public:
    CDateTime():m_time(),m_date(){}
    CDateTime(int a, int b, int c, int d, int e, int f):m_time(d,e,f),m_date(a,b,c){}
    int GetMonth();
    int GetMinute();
    int SetDateTime(int year, int month, int day, int hour, int minute, int second);
    void ShowDateTime(bool flag1, bool flag2);
//��ӱ�Ҫ�Ĺ��캯��
//int SetDateTime(...); �Լ���Ʋ��������Ǹú����ķ���ֵ���Ա�ʾȫ����ȷ�����ڲ��ԡ�ʱ�䲻�Ե����
//void ShowDateTime(...); �Լ���Ʋ��������ǿ����������ں��������ڸ�ʽ���Լ� 24Сʱ�� AM PM �����Կ���
//����Լ���Ϊ��Ҫ��������Ա����
};

int CDateTime::SetDateTime(int year, int month, int day, int hour, int minute, int second)
{
    if(is_legal_date(year,month,day)==false) return -1;
    else if(hour>23 || hour<0 || minute>59 || minute<0 || second>59 || second<0)
    {
        return -2;
    }
    else
    {
        m_date.SetDate(year,month,day);
        m_time.SetTime(hour,minute,second);
        return 1;
    }
}

void CDateTime::ShowDateTime(bool flag1, bool flag2)
{
    if(flag1==true) m_date.ShowDate(true);
    else m_date.ShowDate(false);
    if(flag2=true) m_time.ShowTime(true);
    else m_time.ShowTime(false);
}

int CDateTime::GetMonth()
{
    return m_date.GetMonth();
}

int CDateTime::GetMinute()
{
    return m_time.getMinute();
}


int main()
{
    CDateTime d1(2014, 5, 2, 27, 12, 5);
    d1.ShowDateTime(false, true); //�� 1 ��������ʾ��Ӣ�ķ�ʽ��ʾ����, �� 2 ��������ʾ�� 24 Сʱ�Ʒ�ʽ��ʾʱ��
    CDateTime d2;
    d2.ShowDateTime(true, false); //�� 1 ��������ʾ�����ķ�ʽ��ʾ����, �� 2 ��������ʾ�� AM PM �ķ�ʽ��ʾʱ��
    int iStatus;
    iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
    switch(iStatus)
    {
    case 1:
        cout<<"���ں�ʱ������������ȷ!"<<endl;
        break;
    case -1:
        cout<<"�����������ò���ȷ!"<<endl;
        break;
    case -2:
        cout<<"ʱ���������ò���ȷ!"<<endl;
        break;
    }
    d2.ShowDateTime(false, false); //�� 1 ��������ʾ��Ӣ�ķ�ʽ��ʾ����, �� 2 ��������ʾ�� AM PM �ķ�ʽ��ʾʱ��
    cout<<"��="<<d2.GetMonth()<<endl; //���濼��һ�����ʵ�ִ˲�����
    cout<<"����="<<d2.GetMinute()<<endl; //���濼��һ�����ʵ�ִ˲�����
    return 0;
}
