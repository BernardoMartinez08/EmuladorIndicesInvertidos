#include "Libreria.h"
#include "DelimTextBuffer.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

istream& operator >> (istream& stream, book& b)
{ // leer datos del stream
	char delim = ',';

	//BookID
	char _bookID[7];
	stream.getline(_bookID, 7, delim);
	b.bookID = int(_bookID);

	//title
	char _title[260];
	stream.getline(_title, 260, delim);
	b.title = string(_title);

	//authors
	char _authors[800];
	stream.getline(_authors, 800, delim);
	b.authors = string(_authors);

	//average rating
	char averate[100];
	stream.getline(averate, 100, delim);
	b.average_rating = atof(averate);

	// isbn
	char _isbn[20];
	stream.getline(_isbn, 20, delim);
	b.isbn = string(_isbn);

	//isbn13
	char _isbn13[20];
	stream.getline(_isbn13, 20, delim);
	b.isbn13 = string(_isbn13);

	//language_code
	char _langcode[20];
	stream.getline(_langcode, 20, delim);
	b.language_code = string(_langcode);

	//numpages
	char pages[20];
	stream.getline(pages, 20, delim);
	b.num_pages = int(pages);

	//ratings count
	char ratecount[20];
	stream.getline(ratecount, 20, delim);
	b.ratings_count = int(ratecount);

	//text review count
	char txtreviews[20];
	stream.getline(txtreviews, 20, delim);
	b.text_reviews_count = int(txtreviews);

	// pub date
	char pubdate[20];
	stream.getline(pubdate, 20, delim);
	b.publication_date = string(pubdate);

	//publisher
	char pub[80];
	stream.getline(pub, 80, delim);
	b.publisher = string(pub);

	stream.ignore(1);

	return stream;
}

ostream& operator << (ostream& stream, book& b)
{
	stream
		<< "Book ID = " << b.bookID << endl
		<< "Title = " << b.title << endl
		<< "Authors = " << b.authors << endl
		<< "Average Rating = " << b.average_rating << endl
		<< "ISBN = " << b.isbn << endl
		<< "ISBN13 = " << b.isbn13 << endl
		<< "Language Code = " << b.language_code << endl
		<< "Number of Pages = " << b.num_pages << endl
		<< "Count of Ratings = " << b.ratings_count << endl
		<< "Count of Text Reviews = " << b.text_reviews_count << endl
		<< "Publication Date = " << b.publication_date << endl
		<< "Publisher = " << b.publisher << endl
		<< endl << flush;

	return stream;
}
