#pragma once

#include <vector>

#define MAX 100

class ESieve
{
public:
	std::vector<int> pr;

	ESieve() {};
	~ESieve() {};

	void Generate()
	{
		std::vector<int>lp(MAX + 1, 0);
		for (int i = 2; i <= MAX; ++i) {
			if (lp[i] == 0) {
				lp[i] = i;
				pr.emplace_back(i);
			}
			for (int j = 0; j<(int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= MAX; ++j)
				lp[i * pr[j]] = pr[j];
		}
	}
};

