#include "stdafx.h"
#include "WorkManager.h"


WorkManager::WorkManager()
{
}


WorkManager::~WorkManager()
{
}

#include <iostream>

void WorkManager::Run(std::string from, std::string to)
{
	Intervals intrls;
	XmlParser parser(from, intrls);
	parser.LoadFile();
	parser.Read();

	ThreadSafeSet<uint> set;
	ThreadPool pool(MAX_THREADS);
	for (int i = 0; i < intrls.Size(); i++)
	{
		pool.enqueue(WrapperGeneratePrimes, std::ref(intrls), i, std::ref(set));
	}
	pool.~ThreadPool();

	XmlWriter writer(to);
	writer.Write(set.ToString());
}
