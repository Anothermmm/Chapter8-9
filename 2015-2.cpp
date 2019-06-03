#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

class Timer
{
private:
    int minute;
    int second;

public:
    Timer(int Min=0,int Sec=0)
    {
        if(Min>59 || Min<0 || Sec>59 || Sec<0) exit(0);
        else
        {
            minute=Min;
            second=Sec;
        }
    }
    Timer(const Timer& p)
    {
        minute=p.minute;
        second=p.second;
    }
    get_minute()const{return minute;}
    get_second()const{return second;}
    friend Timer& operator++(Timer& a);//前置，可修改返回
    friend Timer operator++(const Timer& p,int);//后置，不用引用
    friend Timer operator-(const Timer& a, const Timer& b);
    friend write(Timer &t, ofstream &os);
    friend ostream& operator<<(ostream& out, const Timer& p);
};



ostream& operator<<(ostream& out, const Timer& p)
{
    return out<<setfill('0')<<setw(2)<<p.minute<<":"<<setw(2)<<p.second<<endl;
}

Timer& operator++(Timer& a)
{
    if(a.second+1>59)
    {
        a.second=0;
        a.minute+=1;
    }
    if(a.minute>59)
    {
        a.minute=0;
    }
    return a;
}

Timer operator++(const Timer& p,int)
{
    Timer a(p);

     if(a.second+1>59)
    {
        a.second=0;
        a.minute+=1;
    }
    if(a.minute>59)
    {
        a.minute=0;
    }

    return p;
}

Timer operator-(const Timer& a,const Timer& b)
{
    Timer c;

    if(a.minute>b.minute)
    {
        if(a.second>=b.second)
        {
            c.minute=a.minute-b.minute;
            c.second=a.second-b.second;
        }
        else
        {
            c.minute=a.minute-b.minute-1;
            c.second=a.second-b.second+60;
        }
    }
    else if(a.minute<b.minute)
    {
        if(a.second>=b.second)
        {
            c.minute=b.minute-a.minute-1;
            c.second=b.second-a.second+60;
        }
        else
        {
            c.minute=b.minute-a.minute;
            c.second=b.second-a.second;
        }
    }
    else
    {
        c.minute=0;
        c.second=abs(a.second-b.second);
    }

    return c;
}

write(Timer &t, ofstream &os)
{
    if(os.good())
    {
        os<<t;
    }
    else
    {
        cout<<"Error!"<<endl;
    }
    return 0;
}

int main()
{
    ofstream os("Timer.txt");
    Timer t1, t2(20, 59), t3( t2 );

    cout << t1 << t2 << t3;

    Timer* t4 = new Timer(2,49);
    cout << t4->get_minute() << t4->get_second() << endl;
    delete t4;

    ++t1;
    cout << t1;
    t3++;
    cout << t3;

    Timer t5 = t3 - t1;
    cout << t5;


    write(t1, os);
    write(t2, os);
    write(t3, os);
    write(t5, os);

    os.close();

    return 0;
}
