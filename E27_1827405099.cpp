//E27
#include <iostream>
#include <cmath>

using namespace std;

class CPoint
{
    int m_x; //点的 X 坐标
    int m_y; //点的 Y 坐标
public:
    CPoint()
    {
        m_x=0;
        m_y=0;
    }
    CPoint (int x,int y)
    {
        m_x=x;
        m_y=y;
    }
    int getx()
    {
        return m_x;
    }
    int gety()
    {
        return m_y;
    }
    void showPoint()
    {
        cout<<"("<<this->m_x<<","<<this->m_y<<")"<<endl;
    }
};
class CLine
{
    CPoint m_point1;
    CPoint m_point2;

public:
    CLine()
    {
        m_point1;
        m_point2;
    }
    CLine(int a, int b, int c, int d):m_point1(a,b),m_point2(c,d){}
    void ShowLine();
    double distance();
};

void CLine::ShowLine()
{
    cout<<"Point 1 is:";
    this->m_point1.showPoint();
    cout<<"Point 2 is:";
    this->m_point2.showPoint();
}

double CLine::distance()
{
    return sqrt(pow(double(this->m_point1.getx()-this->m_point2.getx()),2.0)+pow(double(this->m_point1.gety()-this->m_point2.gety()),2.0));
}

int main()
{
    CLine line1;
    line1.ShowLine();
    cout<<"Length="<<line1.distance()<<endl;
    CLine line2(1,1,5,5);
    line2.ShowLine();
    cout<<"Length="<<line2.distance()<<endl;
    return 0;
}
