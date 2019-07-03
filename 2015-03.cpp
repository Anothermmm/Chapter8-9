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
    int m_Type;			//电机类型 0-直流 1-交流
    int m_Power;			//电机功率（必须为正数）

public:
    Motor(int Type, int Power);
    int GetPower()const;		//读取电机功率
    int SetPower(int Power);		//修改电机功率，返回值表示修改是否成功，0-失败 1-成功
    friend ostream& operator<<(ostream &Out, const Motor &Obj);//（1）	电机类型：占4列，右对齐，0显示为DC，1显示为AC（2）	电机功率：占6列，右对齐
};

Motor::Motor(int Type, int Power)
{
    if(Power<=0 || !(Type==1 || Type==0))
    {
        cout<<"Motor初始化错误！"<<endl;
        exit(0);//这里的逻辑要注意了
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
    double m_Weight;		//重量（必须为正数）

public:
    Appliance(const string &Name, double Weight);
    double GetWeight()const;		//读取重量
    int SetWeight(double Weight);		//修改重量，返回值表示修改是否成功，0-失败 1-成功
    friend ostream& operator<<(ostream &Out, const Appliance &Obj);
};

Appliance::Appliance(const string &Name, double Weight)
{
    if(Weight<=0)
    {
        cout<<"Appliance初始化错误！"<<endl;
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

class WashMachine:public Appliance//继承
{
private:
    Motor m_Motor;
    int m_Volume;
public:
    WashMachine(const string& Name="M9", int Type=0, int Power=20, double Weight=20.0, int Volume=20):Appliance(Name,Weight),m_Motor(Type,Power)//顺序是先基类初始化后子类中组合类
    {
        if(Volume<=0) exit(0);
        else
            m_Volume=Volume;
    }
    int GetVolumn()const;
    WashMachine& operator++();//前++
    WashMachine operator++(int);//后++
    friend ostream& operator<<(ostream& Out, const WashMachine& Obj);
};

int WashMachine::GetVolumn()const
{
    return m_Volume;
}

WashMachine& WashMachine::operator++()
{
    this->m_Volume+=10;//所有this->不用也行，就会默认是自己
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
    Out<<(Appliance)Obj;//做一个强制类型转化，子类转父类，一定能行
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

    cout<<"文件读取完成后的洗衣机信息如下:"<<endl;
    DisplayData(data);

    res = FindData(data, 30);
    cout<<endl<<"洗衣容积大于30的洗衣机信息如下所示:"<<endl;
    DisplayData(res);

    res = FindData(data, 20.0);
    cout<<endl<<"重量大于20.0的洗衣机信息如下所示:"<<endl;
    DisplayData(res);

    WashMachine d;
    cout<<endl<<"新增加洗衣机对象及其自增运算结果如下所示:"<<endl;
    cout<<d<<endl;
    cout<<d++<<endl;
    cout<<d<<endl;
    cout<<++d<<endl;
    cout<<d<<endl;

    return 0;
}
