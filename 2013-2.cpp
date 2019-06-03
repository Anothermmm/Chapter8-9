//=============================================
// 串口类的测试程序
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
    friend CSerialPort& operator++(CSerialPort& p);//前自增
    friend CSerialPort operator++(CSerialPort& p,int);//后自增
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
    out<<"串口名称：("<<p.Name<<")"<<endl;
    out<<"串口通信速率：("<<p.Speed<<")"<<endl;
    return out;
}


int main()
{
	CSerialPort  portA;
	cout<<"串口portA为: \n"<<portA;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	CSerialPort portB("com5",4800, 1024);
	cout<<"串口portB为: \n"<<portB;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	++(++portB);    // 连续前自增操作
	cout<<"两次前自增后，串口portB为: \n"<<portB;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	cout<<"一次后自增后，串口portB为: \n"<<portB++;
	cout<<"一次后自增后，串口portB为: \n"<<portB;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	CSerialPort  *ptr_portC = new CSerialPort;
	cout<<"串口portC为:\n"<<*ptr_portC;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	delete ptr_portC;
	cout<<"删除串口portC后，当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	return 0;
}
