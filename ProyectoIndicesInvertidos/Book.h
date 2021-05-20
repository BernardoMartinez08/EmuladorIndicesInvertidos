#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class book {
public:
	book();

	bool agregar(int bookID, char* title, char* authors, int average_rating, int isbn, int isbn13, char* language_code, int num_pages, int ratings_count, int text_reviews_count, char* publication_date, char* publisher);
	bool guardar();
	bool consultarSecuencial(int bookID);
	bool modificar();
	bool eliminar();

	void print();

private:
	int bookID;
	char* title;
	char* authors;
	int average_rating;
	int isbn;
	int isbn13;
	char* language_code;
	int num_pages;
	int ratings_count;
	int text_reviews_count;
	char* publication_date;
	char* publisher;
};

#endif // !BOOK_H
