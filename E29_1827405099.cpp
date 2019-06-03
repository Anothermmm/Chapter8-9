#include <iostream>

using namespace std;

class CPerson
{
private:
    string m_name; // 姓名
    int m_age; // 年龄
    char m_sex; // 性别
public:
    CPerson(char *name, int age, char sex)
    {
        m_name = name;
        m_age = age;
        m_sex = sex;
    }
    CPerson()
    {
        m_name = "无名";
        m_age = 18;
        m_sex = 'M';
    }
    void print()
    {
        cout<<"\n 姓名："<<m_name<<"\n 年龄："<<m_age<<"\n";
        if (m_sex == 'M')
            cout<<" 性别： 男"<<endl;
        else
            cout<<" 性别： 女"<<endl;
    }
};

class CStudent : public CPerson
{
private:
    string Name;
    int Grade;
public:
    CStudent():CPerson(),Name("苏州大学"),Grade(1){}
    CStudent(string name, int age, char sex, string collageName, int grade):CPerson((char*)name.c_str(),age,sex),Name(collageName),Grade(grade){}
    //注意此处将string转化成char*的时候，在name.c_str()前面加(char*)，不然会报错"invalid conversion from const char*  to char *"
    void print()
    {
        CPerson::print();
        cout<<" 学校： "<<Name<<"\n 年级： "<<Grade<<endl;
    }
};

int main()
{
    CStudent student1;
    CStudent student2("Liming",21,'M',"苏州大学",1);

    cout<<"student1测试："<<endl;
    student1.print();
    cout<<"student2测试："<<endl;
    student2.print();
    return 0;
}
