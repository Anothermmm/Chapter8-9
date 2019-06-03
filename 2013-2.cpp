//=============================================
// ������Ĳ��Գ���
//=============================================
#include <iostream>
#include <string>

using namespace std;

class CSerialPort
{
private:
    string Name;
    int Speed;
    int BufferLength;
    static int ComCounts;

public:
    CSerialPort(const string& name="com1", int speed=9600, int buff=500)
    {
        Name=name;
        Speed=speed;
        BufferLength=buff;
        ComCounts++;
    }
    CSerialPort(const CSerialPort& p)
    {
        Name=p.Name;
        Speed=p.Speed;
        BufferLength=p.BufferLength;
        ComCounts++;
    }
    ~CSerialPort()
    {
        ComCounts--;
    }
    static int GetComCounts(){return ComCounts;}
    friend CSerialPort& operator++(CSerialPort& p);//ǰ����
    friend CSerialPort operator++(CSerialPort& p,int);//������
    friend ostream& operator<<(ostream& out, const CSerialPort& p);
};
int CSerialPort::ComCounts=0;

CSerialPort& operator++(CSerialPort& p)
{
    p.Speed++;
    return p;
}

CSerialPort operator++(CSerialPort& p,int)
{
    CSerialPort a(p);

    p.Speed++;

    return a;
}

ostream& operator<<(ostream& out, const CSerialPort& p)
{
    out<<"�������ƣ�("<<p.Name<<")"<<endl;
    out<<"����ͨ�����ʣ�("<<p.Speed<<")"<<endl;
    return out;
}


int main()
{
	CSerialPort  portA;
	cout<<"����portAΪ: \n"<<portA;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	CSerialPort portB("com5",4800, 1024);
	cout<<"����portBΪ: \n"<<portB;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	++(++portB);    // ����ǰ��������
	cout<<"����ǰ�����󣬴���portBΪ: \n"<<portB;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	cout<<"һ�κ������󣬴���portBΪ: \n"<<portB++;
	cout<<"һ�κ������󣬴���portBΪ: \n"<<portB;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	CSerialPort  *ptr_portC = new CSerialPort;
	cout<<"����portCΪ:\n"<<*ptr_portC;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	delete ptr_portC;
	cout<<"ɾ������portC�󣬵�ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	return 0;
}
