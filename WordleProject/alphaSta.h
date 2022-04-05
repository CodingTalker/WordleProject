#pragma once
#include"Configure.h"
class alphaSta
{
public:
	alphaSta();
	//unsigned int pos;
	vector<int>pos;
	char alpha, sta;
	bool operator==(const alphaSta& right) const;
	bool operator>(const alphaSta& right) const;
	bool operator<(const alphaSta& right) const;
};

