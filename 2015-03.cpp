#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Motor
{
private:
    int m_Type;			//������� 0-ֱ�� 1-����
    int m_Power;			//������ʣ�����Ϊ������

public:
    Motor(int Type, int Power);
    int GetPower()const;		//��ȡ�������
    int SetPower(int Power);		//�޸ĵ�����ʣ�����ֵ��ʾ�޸��Ƿ�ɹ���0-ʧ�� 1-�ɹ�
    friend ostream& operator<<(ostream &Out, const Motor &Obj);//��1��	������ͣ�ռ4�У��Ҷ��룬0��ʾΪDC��1��ʾΪAC��2��	������ʣ�ռ6�У��Ҷ���
};

Motor::Motor(int Type, int Power)
{
    if(Power<=0 || !(Type==1 || Type==0))
    {
        cout<<"Motor��ʼ������"<<endl;
        exit(0);//������߼�Ҫע����
    }
    else
    {
        m_Type=Type;
        m_Power=Power;
    }
}

int Motor::GetPower()const
{
    return m_Power;
}

int Motor::SetPower(int Power)
{
    if(Power>0)
    {
        m_Power=Power;
        return 1;
    }
    else
        return 0;
}

ostream& operator<<(ostream &Out, const Motor &Obj)
{
    string type;
    if(Obj.m_Type==1) type="AC";
    else type="DC";
    Out<<setw(4)<<right<<type<<setw(6)<<right<<Obj.m_Power;
    return Out;
}

class Appliance
{
private:
    string m_Name;
    double m_Weight;		//����������Ϊ������

public:
    Appliance(const string &Name, double Weight);
    double GetWeight()const;		//��ȡ����
    int SetWeight(double Weight);		//�޸�����������ֵ��ʾ�޸��Ƿ�ɹ���0-ʧ�� 1-�ɹ�
    friend ostream& operator<<(ostream &Out, const Appliance &Obj);
};

Appliance::Appliance(const string &Name, double Weight)
{
    if(Weight<=0)
    {
        cout<<"Appliance��ʼ������"<<endl;
        exit(0);
    }
    else
    {
        m_Name=Name;
        m_Weight=Weight;
    }
}

double Appliance::GetWeight()const
{
    return m_Weight;
}

int Appliance::SetWeight(double Weight)
{
    if(Weight>0)
    {
        m_Weight=Weight;
        return 1;
    }
    else
        return 0;
}

ostream& operator<<(ostream &Out, const Appliance &Obj)
{
    Out<<setw(6)<<right<<Obj.m_Name<<setw(6)<<fixed<<setprecision(1)<<Obj.m_Weight;
    return Out;
}

class WashMachine:public Appliance//�̳�
{
private:
    Motor m_Motor;
    int m_Volume;
public:
    WashMachine(const string& Name="M9", int Type=0, int Power=20, double Weight=20.0, int Volume=20):Appliance(Name,Weight),m_Motor(Type,Power)//˳�����Ȼ����ʼ���������������
    {
        if(Volume<=0) exit(0);
        else
            m_Volume=Volume;
    }
    int GetVolumn()const;
    WashMachine& operator++();//ǰ++
    WashMachine operator++(int);//��++
    friend ostream& operator<<(ostream& Out, const WashMachine& Obj);
};

int WashMachine::GetVolumn()const
{
    return m_Volume;
}

WashMachine& WashMachine::operator++()
{
    this->m_Volume+=10;//����this->����Ҳ�У��ͻ�Ĭ�����Լ�
    this->m_Motor.SetPower(this->m_Motor.GetPower()+10);
    this->Appliance::SetWeight(this->GetWeight()+10.0);
    return *this;
}

WashMachine WashMachine::operator++(int)
{
    WashMachine p(*this);

    this->m_Volume+=10;
    this->m_Motor.SetPower(m_Motor.GetPower()+10);
    this->Appliance::SetWeight(GetWeight()+10.0);

    return p;
}

ostream& operator<<(ostream& Out, const WashMachine& Obj)
{
    Out<<(Appliance)Obj;//��һ��ǿ������ת��������ת���࣬һ������
    Out<<Obj.m_Motor;
    Out<<setw(5)<<right<<Obj.m_Volume;
    return Out;
}

int ReadFileData(const string& path, vector<WashMachine>& data)
{
    ifstream fin(path.c_str());
    string name;
    int type,power,volumn;
    double weight;

    data.clear();
    if(fin.good())
    {
        while(fin>>name>>weight>>type>>power>>volumn)
        {
            if(weight>0 && (type==0 || type==1) && power>0 && volumn>0)
            {
                WashMachine temp(name,type,power,weight,volumn);
                data.push_back(temp);
            }
        }
        fin.close();
        if(data.size()==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        cout<<"Error!"<<endl;
        return 0;
    }
}

void DisplayData(const vector<WashMachine>& data)
{
    for(int i=0;i<data.size();i++)
    {
        cout<<data[i]<<endl;
    }
}

vector<WashMachine> FindData(const vector<WashMachine>& data, int M_volumn)
{
    vector<WashMachine> temp;

    temp.clear();
    for(int i=0;i<data.size();i++)
    {
        if(data[i].GetVolumn()>M_volumn)
        {
            temp.push_back(data[i]);
        }
    }
    return temp;
}

int main()
{
    vector<WashMachine> data,res;

    if(ReadFileData("D:\\info.txt", data)==0) return 0;

    cout<<"�ļ���ȡ��ɺ��ϴ�»���Ϣ����:"<<endl;
    DisplayData(data);

    res = FindData(data, 30);
    cout<<endl<<"ϴ���ݻ�����30��ϴ�»���Ϣ������ʾ:"<<endl;
    DisplayData(res);

    res = FindData(data, 20.0);
    cout<<endl<<"��������20.0��ϴ�»���Ϣ������ʾ:"<<endl;
    DisplayData(res);

    WashMachine d;
    cout<<endl<<"������ϴ�»�����������������������ʾ:"<<endl;
    cout<<d<<endl;
    cout<<d++<<endl;
    cout<<d<<endl;
    cout<<++d<<endl;
    cout<<d<<endl;

    return 0;
}
