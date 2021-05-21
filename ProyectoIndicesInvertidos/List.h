#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;

class list {
	friend ostream& operator<<(ostream&, const list&);
	friend istream& operator>>(istream&, list&);
public:
	list();

	long position;
	long next;
};

#endif // !LIST_H
