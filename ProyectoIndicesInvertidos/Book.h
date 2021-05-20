#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class book {
public:
	book();

	
	bool guardar();


	void print();

	int bookID;
	string title;
	string authors;
	double average_rating;
	string isbn;
	string isbn13;
	string language_code;
	int num_pages;
	int ratings_count;
	int text_reviews_count;
	string publication_date;
	string publisher;
};

#endif // !BOOK_H
