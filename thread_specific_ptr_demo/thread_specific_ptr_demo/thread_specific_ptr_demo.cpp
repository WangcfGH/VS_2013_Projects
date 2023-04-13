// thread_specific_ptr_demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

// ������Ҫ��ͷ�ļ� 
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/thread.hpp>
#include <boost/thread/tss.hpp>   // thread_specific_ptr

using namespace boost;
using namespace std;
// ��־��Ϣ
class logmsg
{
public:
	logmsg(time_t t, string tid, string tmsg)
		:timeinfo(t), id(tid), msg(tmsg)
	{};
	// ͨ��ʱ��Ƚ�������־��Ϣ
	bool operator < (const logmsg& other)
	{
		return timeinfo < other.timeinfo;
	}
	string tostring()
	{
		struct tm* ltime = localtime(&timeinfo);
		string text(asctime(ltime));
		text += " " + id + ":" + msg;

		return text;
	}
private:
	time_t timeinfo;  // ʱ��
	string id;  // �߳�id
	string msg; // ����
};
// ��־�ļ�
class logfile
{
public:
	logfile()
	{
	}
	logfile(int tid)
	{
		ostringstream o;
		o << tid;
		id = o.str();
		cout << id << endl;
	}
	~logfile()
	{
		cout << "destructor" << endl;
	}
public:
	// ��¼һ����־��Ϣ���ļ�
	void log(string text)
	{
		logs.push_back(logmsg(gettime(), id, text));
	}
	// ������һ����־�ļ�����Ϣ�ϲ������ļ�
	void combin(logfile* other)
	{
		logs.insert(logs.end(),
			other->logs.begin(),
			other->logs.end());
		//
	}
	// ��ʾ������־��Ϣ
	void display()
	{
		// ��������Ϣ����ʱ������
		std::sort(logs.begin(), logs.end());
		for (auto it = logs.begin(); it != logs.end(); ++it)
		{
			cout << (*it).tostring() << endl;
		}
	}
private:
	// ��õ�ǰʱ��
	time_t gettime()
	{
		return time(NULL);
	}
private:
	// �߳�ID
	string id;
	// ������־��Ϣ
	vector<logmsg> logs;
};
mutex m;
boost::shared_ptr<logfile> cmblog(new logfile);

// ����thread_specific_ptr�����������������������������Դ
// �������߳��˳�ʱ���Զ����ã��������ǿ��������ｫ����̼߳�¼����־
// �ϲ���ȫ�ֵ�������־�ļ��У���delete���̹߳������־�ļ�
void cmb(logfile* log)
{
	mutex::scoped_lock lk(m);
	// �ϲ���־
	cmblog->combin(log);
	// �ͷŵ�thread_specific_ptr�������Դ
	delete log;

}
// ȫ�ֵ�thread_specific_ptr����������������Ҫ������ʵ�ȫ�ֶ���
// cmb�������ͷ���Դ�ĺ���
thread_specific_ptr<logfile> plog(cmb);// 


// �̺߳���
void run(int id)
{
	// Ϊÿ���߳�newһ�����󣬽���thread_specific_ptr���й���
	plog.reset(new logfile(id));
	// ��¼һ����־������̱߳��ش洢��logfile
	plog->log("�߳�����");

	random::uniform_int_distribution<int>  wt(100, 5000);
	random::mt19937 gen;

	posix_time::milliseconds worktime(wt(gen));
	this_thread::sleep(worktime);

	plog->log("�߳̽���");
	// ���߳̽�����ʱ��Ĭ������£������Զ�delete�����������Դ����������ڹ��캯�����������Դ�����������������cmb����������Զ�������������������������

	// ���⣬����Ҳ���Ե�������release()�������������������Դ���Լ����д��������ٸ�����Դ������
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ���߳�Ҳ��Ҫ���ش洢һ������
	plog.reset(new logfile(100));
	// ��¼��־
	plog->log("����ʼ");

	random::uniform_int_distribution<int>  waittime(100, 500);
	random::mt19937 gen;

	// ����һ���߳���
	thread_group tg;
	for (int i = 0; i < 5; ++i)
	{
		tg.create_thread(boost::bind(run, i));

		posix_time::milliseconds wt(waittime(gen));
		this_thread::sleep(wt);
	}
	// �ȴ������߳̽���
	tg.join_all();
	plog->log("�������");



	// ��ʾ���պϲ��õ�����־�ļ�
	cmblog->display();

	getchar();
	getchar();

	return 0;
}