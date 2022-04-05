#pragma once
#include"Configure.h"
#include"alphaSta.h"
class typeLine
{
public:
	typeLine();
	bool isfit(const string& t)const;
	bool islegal()const;
	bool posIsIn(const vector<int>& t, int val)const;
	void update();
	void clear();
	char word[6];
	char type[6];
	//vector<char>needFound;
	vector<alphaSta>alphabet;
};

