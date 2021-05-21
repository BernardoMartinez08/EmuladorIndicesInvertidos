#pragma once
#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class index {
	friend ostream& operator<<(ostream&, const index&);
	friend istream& operator>>(istream&, index&);
public:
	index();

	string word;
	long first;
	bool status;
};
#endif // !INDEX_H
