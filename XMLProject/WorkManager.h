#pragma once

#include <string>
#include "XmlParser.h"
#include "XmlWriter.h"
#include "Intervals.h"
#include "Interval.h"
#include "ThreadPool.h"
#include "MillerRabinTest.h"
#include "ThreadSafeSet.h"

#define MAX_THREADS 4

class WorkManager
{
public:
	WorkManager();
	~WorkManager();

	void Run(std::string, std::string);
};

