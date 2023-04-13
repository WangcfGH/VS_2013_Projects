// ChunkSvrTestDemo.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <future>
#include <string>

template<typename Callback>
class FunctionWrapper
{
public:
	FunctionWrapper() = default;
	FunctionWrapper(std::function<Callback> f) : m_cb(f) {}
	FunctionWrapper(FunctionWrapper&& other)
	{
		m_cb.swap(other.m_cb);
	}

	FunctionWrapper& operator = (FunctionWrapper&& other)
	{
		m_cb.swap(other.m_cb);
		return *this;
	}
private:
	std::function<Callback> m_cb;
};


class DBConnectPool
{
public:
	DBConnectPool(int nthread = 8);
	~DBConnectPool();

	std::future<int> dbInvokeByStrand(const std::string&key)
 	{
// 		auto p = std::make_shared<std::promise < R >>();
// 		auto assign = getStrandPtr(key);
// 		assign->strand->staff->strand().dispatch([key, p, invoke, assign, this](){
// 			auto entry = getThreadEntryByType<PoolEntry>();
// 			AutoEraseKey erase_key(this, key);
// 			try {
// 				entry->user_data = &assign->user_data;
// 				static_assert(std::is_convertible<Entry, PoolEntry>::value, "Entry Must Driver from PoolEntry");
// 				p->set_value(invoke(static_cast<Entry*>(entry)));
// 			}
// 			catch (...) {
// 				p->set_exception(std::current_exception());
// 			}
// 		});
// 		return p->get_future();
 	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::string key("LuckyCat_426508");
	std::shared_ptr<DBConnectPool> spr(new DBConnectPool());

	FunctionWrapper<std::future<int>(const std::string&)> imDBInvoke = FunctionWrapper<std::future<int>(const std::string&)>([spr, key]()
	{
		return spr->dbInvokeByStrand(key);
	});

	return 0;
}

