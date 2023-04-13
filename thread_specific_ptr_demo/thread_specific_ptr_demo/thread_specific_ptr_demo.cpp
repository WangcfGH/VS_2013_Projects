// thread_specific_ptr_demo.cpp : 定义控制台应用程序的入口点。
//

// 引入需要的头文件 
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
// 日志消息
class logmsg
{
public:
	logmsg(time_t t, string tid, string tmsg)
		:timeinfo(t), id(tid), msg(tmsg)
	{};
	// 通过时间比较两条日志消息
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
	time_t timeinfo;  // 时间
	string id;  // 线程id
	string msg; // 内容
};
// 日志文件
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
	// 记录一条日志消息到文件
	void log(string text)
	{
		logs.push_back(logmsg(gettime(), id, text));
	}
	// 将另外一个日志文件的消息合并到本文件
	void combin(logfile* other)
	{
		logs.insert(logs.end(),
			other->logs.begin(),
			other->logs.end());
		//
	}
	// 显示所有日志消息
	void display()
	{
		// 对所有消息按照时间排序
		std::sort(logs.begin(), logs.end());
		for (auto it = logs.begin(); it != logs.end(); ++it)
		{
			cout << (*it).tostring() << endl;
		}
	}
private:
	// 获得当前时间
	time_t gettime()
	{
		return time(NULL);
	}
private:
	// 线程ID
	string id;
	// 所有日志消息
	vector<logmsg> logs;
};
mutex m;
boost::shared_ptr<logfile> cmblog(new logfile);

// 这是thread_specific_ptr的清理函数，负责清理它所管理的资源
// 他会在线程退出时被自动调用，所以我们可以在这里将这个线程记录的日志
// 合并到全局的最终日志文件中，并delete掉线程管理的日志文件
void cmb(logfile* log)
{
	mutex::scoped_lock lk(m);
	// 合并日志
	cmblog->combin(log);
	// 释放掉thread_specific_ptr管理的资源
	delete log;

}
// 全局的thread_specific_ptr对象，用他来管理需要共享访问的全局对象
// cmb是它的释放资源的函数
thread_specific_ptr<logfile> plog(cmb);// 


// 线程函数
void run(int id)
{
	// 为每个线程new一个对象，交给thread_specific_ptr进行管理
	plog.reset(new logfile(id));
	// 记录一条日志到这个线程本地存储的logfile
	plog->log("线程启动");

	random::uniform_int_distribution<int>  wt(100, 5000);
	random::mt19937 gen;

	posix_time::milliseconds worktime(wt(gen));
	this_thread::sleep(worktime);

	plog->log("线程结束");
	// 在线程结束的时候，默认情况下，它会自动delete它所管理的资源，如果我们在构造函数中提高了资源清理函数，例如这里的cmb函数，则会自动调用这个函数来完成清理工作。

	// 另外，我们也可以调用它的release()函数返回它所管理的资源，自己进行处理，它不再负责资源的清理
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 主线程也需要本地存储一个对象
	plog.reset(new logfile(100));
	// 记录日志
	plog->log("程序开始");

	random::uniform_int_distribution<int>  waittime(100, 500);
	random::mt19937 gen;

	// 创建一个线程组
	thread_group tg;
	for (int i = 0; i < 5; ++i)
	{
		tg.create_thread(boost::bind(run, i));

		posix_time::milliseconds wt(waittime(gen));
		this_thread::sleep(wt);
	}
	// 等待所有线程结束
	tg.join_all();
	plog->log("程序结束");



	// 显示最终合并得到的日志文件
	cmblog->display();

	getchar();
	getchar();

	return 0;
}