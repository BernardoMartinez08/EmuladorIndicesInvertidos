#pragma once
#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include <vector>

using namespace std;

class index {
	friend ostream& operator<<(ostream&, const index&);
	friend istream& operator>>(istream&, index&);
public:
	index();

	string word;
	long posicion;
	vector<list> lista;
};
#endif // !INDEX_H
