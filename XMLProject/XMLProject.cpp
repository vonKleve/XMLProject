#include "stdafx.h"
#include <iostream>
#include "MillerRabinTest.h"
#include "APArithmetic.h"

using namespace std;

int main()
{
	/*string path = "C:\\Users\\Dell\\source\\repos\\XMLProject\\XMLProject\\input1.xml";
	Intervals intrls = Intervals();
	XmlParser obj(path, intrls);
	obj.LoadFile();
	obj.Read();

	for (int i = 0; i < intrls.GetSize(); i++)
	{
		cout << intrls.Get(i).GetLow() << " " << intrls.Get(i).GetHigh() << endl;
	}*/
	/*vector<unsigned int> mvec = {1, 2, 10, 11};
	string outpath = "C:\\Users\\Dell\\source\\repos\\XMLProject\\XMLProject\\output1.xml";
	XmlWriter writer(outpath);
	writer.Write(mvec);*/

	/*MillerRabinTest test;
	test.IsPrime(43, 10);
	for (int i = 1; i <= 1000; i++)
	{
		bool res = test.IsPrime(i, 10);
		if (res)
			cout << i << " ";
	}
	cout << endl;*/

	APArithmetic a({ 4, 3, 2, 2}), b({ 4, 2, 2, 1 });
	APArithmetic c = a.Mod(3);

	APArithmetic bb(143);
	cout << endl << bb.ToString() << endl;

	system("pause");
	return 0;
}

