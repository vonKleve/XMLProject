#include "stdafx.h"
#include <iostream>
#include "WorkManager.h"
#include "ESieve.h"
#include <exception>

using namespace std;

int main()
{
	WorkManager manager;
	string path = "C:\\Users\\Dell\\source\\repos\\XMLProject\\XMLProject\\input1.xml";
	string outpath = "C:\\Users\\Dell\\source\\repos\\XMLProject\\XMLProject\\output1.xml";
	manager.Run(path, outpath);
	system("pause");
	return 0;
}

