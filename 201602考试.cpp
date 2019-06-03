//题目
//1、	为CLyric类添加一个携带四个参数的构造函数，前三个参数分别用于初始化分钟、秒和毫秒，第四个参数用于初始化歌词。
//注意：
//	如果前三个参数有一个取值不合法，那么时间相关的三个数据成员全部初始化为0。分钟、秒的取值范围为[0,59]，毫秒的取值范围[0,999]。
//	流水序号的初始化和构造函数参数无关，在构造函数中需要保证对象的流水序号是自动增长的，每次新产生的对象的流水序号比之前用过的最大流水序号大1。可以添加静态数据成员m_MaxId协助完成该需求。
//2、	为CLyric类添加一个拷贝构造函数实现对象复制，注意：流水序号不能直接复制。
//3、	为CLyric类添加五个成员函数getMinute、getSecond、getMillisecond、getSentence和，getSequenceId分别用于获取(返回)分钟、秒、毫秒、歌词和流水序号值。
//4、	为CLyric类重载流输出运算符，用于显示一条歌词信息，格式如下
//[MM:SS.PPP] 歌词文本
//时间用一对英文方括号括起来，中间的分割冒号和点都是英文字符，其中前两个成员占两位，毫秒占三位，不足前面用0填充，时间和歌词文本之间用一个空格分割。
//5、	为CLyric类重载后自增运算符用于将秒值加1。注意：先增加秒值，如果超过59，秒值清零，分钟加1；如果分钟值超过59，分钟值清零；毫秒保持不变。
//6、	为CLyric类重载加上int数据的加号运算符，所加的整数是毫秒数。注意：该整数为非负数，可能大于1000，同样需要处理进位的问题。
//
//7、	编写函数readSong，用于实现把D盘的in.txt中的数据读取到向量song中保存，读取时需要舍弃异常的数据（分钟、秒或者毫秒取值不合法），并返回异常数据的行数。
//8、	编写函数showTopN用于把向量song中的前n条歌词数据显示在屏幕上，每条歌词显示格式和第4步格式相同。注意：当向量中数据不足n条时显示向量的全部数据。
//9、	编写函数offsetSong，用于实现把向量song中所有的歌词的时间后移1秒。 
//10、	编写CLyric类的友元函数writeSong用于将向量song中的全部数据存储到D盘的文本文件out.lrc中，存储格式和第4步格式相同，每条歌词单独一行。

//txt文件
//0 41 0 生怕这一路是好梦一场。
//0 48 0 而你是一张无边无际的网，
//0 56 0 轻易就把我困在网中央，
//1 04 0 我越陷越深越迷惘，
//1 08 0 路越走越远越漫长，
//1 12 0 如何我才能锁住你眼光。
//1 20 0 情愿就这样守在你身旁，
//1 27 0 情愿就这样一辈子不忘，
//1 35 0 我打开爱情这扇窗，
//1 39 0 却看见长夜日凄凉，
//1 43 0 问你是否会舍得我心伤。
//2 06 0 而你是一张无边无际的网，
//2 14 0 轻易就把我困在网中央，
//2 22 0 我越陷越深越迷惘，
//2 26 0 路越走越远越漫长，
//2 30 0 如何我才能锁住你眼光。
//2 37 0 情愿就这样守在你身旁，
//2 45 0 情愿就这样一辈子不忘，
//2 53 0 我打开爱情这扇窗，
//2 57 0 却看见长夜日凄凉，
//3 01 0 问你是否会舍得我心伤。
//3 09 0 今夜就这样守在你身旁，
//3 17 0 今夜就这样一辈子不忘，
//3 25 0 我打开爱情这扇窗，
//3 29 0 却看见长夜的凄凉，
//3 33 0 问你是否会舍得我心伤。
//60 1 2 错误时间歌词


#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>//exit(0)要包含的头文件

using namespace std;

class CLyric
{
private://先写普通成员变量，再写静态成员变量
	int m_Minute;			//分钟
	int m_Second;			//秒
	int m_Millisecond; 	//毫秒
	string m_Sentence;		//一句歌词
    int	m_SequenceId;		//从1开始的流水序号，每个对象不重复
    static int m_MaxId;    //流水序号

public:
    CLyric(int minute, int second, int millisecond, const string& sentence)//构造函数
    {
        if(minute<0 || minute>59 || second<0 || second>59 || millisecond<0 || millisecond>999)
        {
            m_Minute=0;
            m_Second=0;
            m_Millisecond=0;
        }
        else
        {
            m_Minute=minute;
            m_Second=second;
            m_Millisecond=millisecond;
        }
        m_Sentence=sentence;
        m_MaxId++;
        m_SequenceId=m_MaxId;
    }
    CLyric(const CLyric& s)//拷贝构造函数
    {
        m_Minute=s.m_Minute;
        m_Second=s.m_Second;
        m_Millisecond=s.m_Millisecond;
        m_Sentence=s.m_Sentence;

        m_MaxId++;
        m_SequenceId=m_MaxId;
    }
    int getMinute()const//比较短不超过三行的成员函数在类内定义
    {
        return m_Minute;
    }
    int getSecond()const//只对对象进行读操作，可以选择定义常成员函数
    {
        return m_Second;
    }
    int getMillisecond()const
    {
        return m_Millisecond;
    }
    string getSentence()const
    {
        return m_Sentence;
    }
    int getSequenceId()const
    {
        return m_SequenceId;
    }

    friend ostream& operator<<(ostream& out,const CLyric& s);//<<流输出符必须定义为友元函数，原因：<<左侧是运算量而不是对象,因此后面参数第一个不能被修改
    friend CLyric operator++(CLyric& s, int);//此处用友元函数，可以传多个参数，第二个int是标记后置++，s会被修改故不用const
    //如果不采用友元函数形式：CLyric operator++(int);
    friend CLyric operator+(const CLyric& s, int a);//
};

int CLyric::m_MaxId=0;//静态成员变量在类外定义，注明是哪个类的，但不要加static

ostream& operator<<(ostream& out,const CLyric& s)
{
    out<<"["<<setw(2)<<setfill('0')<<s.m_Minute<<":"<<setw(2)<<s.m_Second<<"."<<setw(3)<<s.m_Millisecond<<"] "<<s.m_Sentence<<endl;
    return out;
}

CLyric operator++(CLyric& s, int)
{
    CLyric p(s);//拷贝构造函数深拷贝

    s.m_Second++;
    s.m_Minute += s.m_Second / 60;
    s.m_Second %= 60;
    s.m_Minute %= 60;

    return p;
}

//如果不采用友元函数形式
//CLyric CLyric::operator++(int)
//{
//      CLyric p(*this);
//
//	(*this).m_Second++;
//	(*this).m_Minute += (*this).m_Second / 60;
//	(*this).m_Second %= 60;
//	(*this).m_Minute %= 60;
//
//      return (*this);
//}

CLyric operator+(const CLyric& s, int a)
{
    CLyric p(s);

    p.m_Millisecond+=a;
    p.m_Second+=p.m_Millisecond/1000;
    p.m_Millisecond%=1000;
    p.m_Minute+=p.m_Second/60;
    p.m_Second%=60;
    p.m_Minute%=60;

    return p;
}

int readSong(const string& path, vector<CLyric>& song)//string也要加const &，可以传右值
{
    ifstream fin(path.c_str());//不支持string，要转化成c串
    int Min,Sec,Mill,count=0;
    string Sen;

    song.clear();
    if(fin.good())
    {
        while(fin>>Min>>Sec>>Mill>>Sen)
        {
            if(Min<0 || Min>59 || Sec<0 || Sec>59 || Mill<0 || Mill>999)
            {
                count++;
                continue;
            }
            else
            {
                song.push_back(CLyric(Min,Sec,Mill,Sen));//直接调用构造函数，在创建的时候初始化
            }
        }
        fin.close();
    }
    else
    {
        cout<<"Error!"<<endl;
        exit(0);
    }
    return count;
}

void showTopN(const vector<CLyric>& song, int n)
{
    if(n>song.size()) n=song.size();
    for(int i=1;i<=n;i++) cout<<song[i-1];
}

void offsetSong(vector<CLyric>& song)
{
    for(int i=0;i<song.size();i++)
    {
        song[i]++;
    }
}

void writeSong(const string& path, vector<CLyric>& song)
{
    ofstream fout(path.c_str());

    if(fout.good())
    {
        for(int i=0;i<song.size();i++)
        {
            fout<<song[i];
        }
        fout.close();
    }
    else
    {
        cout<<"Error!"<<endl;
        exit(0);
    }
}

int main()
{
	CLyric time1(61,12,125,"考试之歌");
	cout << "输出time1：" << endl;
	cout << "id=" << time1.getSequenceId() << " " << time1 << endl;
	CLyric time2(59, 59, 500,"双截棍");
	cout << "执行加号运算符后time2：" << endl;
	time2 = time2 + 2000;
	cout <<"id="<<time2.getSequenceId()<<" "<<time2 << endl;
	cout << "执行后置++运算符后time2：" << endl;
	time1 = time2++;
	cout << "id=" << time2.getSequenceId() << " " << time2 << endl;

	vector<CLyric> song;
	cout << "读取原始歌词文件" << endl;
	int count=readSong("d:\\in.txt", song);
	cout << "共有" << count << "行不合法数据" << endl;

	cout << "歌词前5行是：" << endl;
	showTopN(song, 5);
	offsetSong(song);
	cout << "正在生成歌词文件......"<<endl;
	writeSong("d:\\out.lrc", song);
	cout << "生成歌词文件成功！"<<endl;
	return 0;
}
