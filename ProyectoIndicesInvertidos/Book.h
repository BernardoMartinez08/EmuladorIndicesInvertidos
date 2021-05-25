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
	friend ostream& operator<<(ostream&, const book&);
	friend istream& operator>>(istream&, book&);
public:
	book();

	void print();

	string bookID;
	string title;
	string authors;
	string average_rating;
	string isbn;
	string isbn13;
	string language_code;
	string num_pages;
	string ratings_count;
	string text_reviews_count;
	string publication_date;
	string publisher;
};

#endif // !BOOK_H
