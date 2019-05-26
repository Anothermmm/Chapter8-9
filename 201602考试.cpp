#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class CLyric
{
private://��д��ͨ��Ա��������д��̬��Ա����
	int m_Minute;			//����
	int m_Second;			//��
	int m_Millisecond; 	//����
	string m_Sentence;		//һ����
    int	m_SequenceId;		//��1��ʼ����ˮ��ţ�ÿ�������ظ�
    static int m_MaxId;    //��ˮ���

public:
    CLyric(int minute, int second, int millisecond, const string& sentence)//���캯��
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
    CLyric(const CLyric& s)//�������캯��
    {
        m_Minute=s.m_Minute;
        m_Second=s.m_Second;
        m_Millisecond=s.m_Millisecond;
        m_Sentence=s.m_Sentence;

        m_MaxId++;
        m_SequenceId=m_MaxId;
    }
    int getMinute()const//�Ƚ϶̲��������еĳ�Ա���������ڶ���
    {
        return m_Minute;
    }
    int getSecond()const//ֻ�Զ�����ж�����������ѡ���峣��Ա����
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

    friend ostream& operator<<(ostream& out,const CLyric& s);//<<����������붨��Ϊ��Ԫ������ԭ��
    friend CLyric operator++(CLyric& s, int);
    friend CLyric operator+(const CLyric& s, int a);
};

int CLyric::m_MaxId=0;//��̬��Ա���������ⶨ�壬ע�����ĸ���ģ�����Ҫ��static

ostream& operator<<(ostream& out,const CLyric& s)
{
    out<<"["<<setw(2)<<setfill('0')<<s.m_Minute<<":"<<setw(2)<<s.m_Second<<"."<<setw(3)<<s.m_Millisecond<<"] "<<s.m_Sentence<<endl;
    return out;
}

CLyric operator++(CLyric& s, int)
{
    CLyric p(s);

	s.m_Second++;
	s.m_Minute += s.m_Second / 60;
	s.m_Second %= 60;
	s.m_Minute %= 60;

    return p;
}

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









int readSong(const string& path, vector<CLyric>& song)
{
    ifstream fin(path.c_str());
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
                song.push_back(CLyric(Min,Sec,Mill,Sen));
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
	CLyric time1(61,12,125,"����֮��");
	cout << "���time1��" << endl;
	cout << "id=" << time1.getSequenceId() << " " << time1 << endl;
	CLyric time2(59, 59, 500,"˫�ع�");
	cout << "ִ�мӺ��������time2��" << endl;
	time2 = time2 + 2000;
	cout <<"id="<<time2.getSequenceId()<<" "<<time2 << endl;
	cout << "ִ�к���++�������time2��" << endl;
	time1 = time2++;
	cout << "id=" << time2.getSequenceId() << " " << time2 << endl;

	vector<CLyric> song;
	cout << "��ȡԭʼ����ļ�" << endl;
	int count=readSong("d:\\in.txt", song);
	cout << "����" << count << "�в��Ϸ�����" << endl;

	cout << "���ǰ5���ǣ�" << endl;
	showTopN(song, 5);
	offsetSong(song);
	cout << "�������ɸ���ļ�......"<<endl;
	writeSong("d:\\out.lrc", song);
	cout << "���ɸ���ļ��ɹ���"<<endl;
	return 0;
}
