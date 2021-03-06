#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <set>
#include <string>
#include <vector>


template<typename T>
class ThreadSafeSet
{
public:
	ThreadSafeSet() {};
	~ThreadSafeSet() {};

	size_t Size()
	{
		return set_.size();
	}

	void Insert(const T item) 
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		set_.insert(item);
		mlock.unlock();
	}

	std::string ToString()
	{
		std::unique_lock<std::mutex> mlock(mutex_);
		std::string res = "";
		for (auto it : set_)
		{
			res += std::to_string(it) + " ";
		}
		mlock.unlock();

		return res;
	}

	std::vector<T> ToVector()
	{
		std::vector<T> result= std::vector<T>();
		for (auto it : set_)
		{
			result.emplace_back(it);
		}
		return result;
	}

private:
	std::set<T> set_;
	std::mutex mutex_;
	std::condition_variable cond_;
};