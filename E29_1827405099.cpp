#include <iostream>

using namespace std;

class CPerson
{
private:
    string m_name; // ����
    int m_age; // ����
    char m_sex; // �Ա�
public:
    CPerson(char *name, int age, char sex)
    {
        m_name = name;
        m_age = age;
        m_sex = sex;
    }
    CPerson()
    {
        m_name = "����";
        m_age = 18;
        m_sex = 'M';
    }
    void print()
    {
        cout<<"\n ������"<<m_name<<"\n ���䣺"<<m_age<<"\n";
        if (m_sex == 'M')
            cout<<" �Ա� ��"<<endl;
        else
            cout<<" �Ա� Ů"<<endl;
    }
};

class CStudent : public CPerson
{
private:
    string Name;
    int Grade;
public:
    CStudent():CPerson(),Name("���ݴ�ѧ"),Grade(1){}
    CStudent(string name, int age, char sex, string collageName, int grade):CPerson((char*)name.c_str(),age,sex),Name(collageName),Grade(grade){}
    //ע��˴���stringת����char*��ʱ����name.c_str()ǰ���(char*)����Ȼ�ᱨ��"invalid conversion from const char*  to char *"
    void print()
    {
        CPerson::print();
        cout<<" ѧУ�� "<<Name<<"\n �꼶�� "<<Grade<<endl;
    }
};

int main()
{
    CStudent student1;
    CStudent student2("Liming",21,'M',"���ݴ�ѧ",1);

    cout<<"student1���ԣ�"<<endl;
    student1.print();
    cout<<"student2���ԣ�"<<endl;
    student2.print();
    return 0;
}
