#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();

private:
	std::vector<std::thread> workers;
	std::queue<std::function<void()>> tasks;
};

