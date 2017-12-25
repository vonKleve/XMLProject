#include "stdafx.h"
#include "ESieve.h"

//void ESieve::Generate()
//{
//	std::vector<int>lp(MILLION + 1, 0);
//	for (int i = 2; i <= MILLION; ++i) {
//		if (lp[i] == 0) {
//			lp[i] = i;
//			pr.push_back(i);
//		}
//		for (int j = 0; j<(int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= MILLION; ++j)
//			lp[i * pr[j]] = pr[j];
//	}
//}
