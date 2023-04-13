// #include "stdafx.h"
// #include <boost/regex.hpp>
// #include <iostream>
// #include <string>
// 
// int main()
// {
// 	std::string line;
// 	boost::regex pat("^Subject: (Re: |Aw: )*(.*)");
// 
// 	while (std::cin)
// 	{
// 		std::getline(std::cin, line);
// 		boost::smatch matches;
// 		if (boost::regex_match(line, matches, pat))
// 			std::cout << matches[2] << std::endl;
// 	}
// }






// #include "stdafx.h"
// #include <iostream>
// #include <boost/asio.hpp>
// #include <boost/date_time/posix_time/posix_time.hpp>
// 
// int main()
// {
// 	boost::asio::io_service io;
// 
// 	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
// 	t.wait();
// 
// 	std::cout << "Hello, world!\n";
// 	getchar();
// 	getchar();
// 
// 	return 0;
// }






// #include "stdafx.h"
// #include <iostream>
// #include <boost/asio.hpp>
// #include <boost/date_time/posix_time/posix_time.hpp>
// 
// void print(const boost::system::error_code& /*e*/)
// {
// 	std::cout << "Hello, world!\n";
// }
// 
// int main()
// {
// 	boost::asio::io_service io;
// 
// 	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
// 	t.async_wait(print);
// 
// 	std::cout << "Start run" << std::endl;
// 
// 	io.run();
// 
// 	std::cout << "End run" << std::endl;
// 
// 
// 	getchar();
// 	getchar();
// 
// 	return 0;
// }





// #include "stdafx.h"
// #include <iostream>
// #include <boost/asio.hpp>
// #include <boost/bind.hpp>
// #include <boost/date_time/posix_time/posix_time.hpp>
// 
// void print(const boost::system::error_code& /*e*/,
// 	boost::asio::deadline_timer* t, int* count)
// {
// 	if (*count < 5)
// 	{
// 		std::cout << *count << "\n";
// 		++(*count);
// 
// 		t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
// 		t->async_wait(boost::bind(print,
// 			boost::asio::placeholders::error, t, count));
// 	}
// }
// 
// int main()
// {
// 	boost::asio::io_service io;
// 
// 	int count = 0;
// 	boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
// 	t.async_wait(boost::bind(print,
// 		boost::asio::placeholders::error, &t, &count));
// 
// 	io.run();
// 
// 	std::cout << "Final count is " << count << "\n";
// 
// 	getchar();
// 	getchar();
// 
// 	return 0;
// }





// #include "stdafx.h"
// #include <iostream>
// #include <boost/asio.hpp>
// #include <boost/bind.hpp>
// #include <boost/date_time/posix_time/posix_time.hpp>
// 
// class printer
// {
// public:
// 	printer(boost::asio::io_service& io)
// 		: timer_(io, boost::posix_time::seconds(1)),
// 		count_(0)
// 	{
// 		timer_.async_wait(boost::bind(&printer::print, this));
// 	}
// 
// 	~printer()
// 	{
// 		std::cout << "Final count is " << count_ << "\n";
// 	}
// 
// 	void print()
// 	{
// 		if (count_ < 5)
// 		{
// 			std::cout << count_ << "\n";
// 			++count_;
// 
// 			timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
// 			timer_.async_wait(boost::bind(&printer::print, this));
// 		}
// 	}
// 
// private:
// 	boost::asio::deadline_timer timer_;
// 	int count_;
// };
// 
// int main()
// {
// 	boost::asio::io_service io;
// 	printer p(io);
// 	io.run();
// 
// 	getchar();
// 	getchar();
// 
// 	return 0;
// }





#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;
	time_t now = time(0);
	return ctime(&now);
}

class printer
{
public:
	printer(boost::asio::io_service& io)
		: strand_(io),
		timer1_(io, boost::posix_time::seconds(1)),
		timer2_(io, boost::posix_time::seconds(1)),
		count_(0)
	{
		timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
		timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
	}

	~printer()
	{
		std::cout << "Final count is " << count_ << "\n";
	}
	
	void print1()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 1: " << count_ << "\n";
			++count_;

			timer1_.expires_at(timer1_.expires_at() + boost::posix_time::seconds(1));
			timer1_.async_wait(strand_.wrap(boost::bind(&printer::print1, this)));
		}
	}

	void print2()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 2: " << count_ << "\n";
			++count_;

			timer2_.expires_at(timer2_.expires_at() + boost::posix_time::seconds(1));
			timer2_.async_wait(strand_.wrap(boost::bind(&printer::print2, this)));
		}
	}

private:
	boost::asio::strand strand_;
	boost::asio::deadline_timer timer1_;
	boost::asio::deadline_timer timer2_;
	int count_;
};

int main()
{
	boost::asio::io_service io;
	
	std::string startTime = make_daytime_string();
	std::cout << "startTime: " << startTime  << std::endl;

	printer p(io);
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
	io.run();
	t.join();

	std::string endTime = make_daytime_string();
	std::cout << "endTime: " << endTime << std::endl;

	getchar();
	getchar();
	return 0;
}