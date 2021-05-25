#include "book.h"

book::book() {
	bookID;
    title;
    authors;
    average_rating;
    isbn;
    isbn13;
    language_code;
    num_pages;
    ratings_count;
    text_reviews_count;
    publication_date;
    publisher;
}

ostream& operator<<(ostream& stream, const book& book) {
	/*if (!stream) {
		cout << "\nSe presento un problema al intentar abrir el archivo de libros .csv :(\n";
		return stream;
	}*/
	
	stream << book.bookID;
	stream << ",";
	stream << book.title;
	stream << ",";
	stream << book.authors;
	stream << ",";
	stream << book.average_rating;
	stream << ",";
	stream << book.isbn;
	stream << ",";
	stream << book.isbn13;
	stream << ",";
	stream << book.language_code;
	stream << ",";
	stream << book.num_pages;
	stream << ",";
	stream << book.ratings_count;
	stream << ",";
	stream << book.text_reviews_count;
	stream << ",";
	stream << book.publication_date;
	stream << ",";
	stream << book.publisher;
	stream << "/";

	return stream;
}

istream& operator>>(istream& stream, book& book) {
	// leer datos del stream
	char delim = ',';

	//BookID
	char _bookID[7];
	stream.getline(_bookID, 7, delim);
	book.bookID = string(_bookID);

	//title
	char _title[260];
	stream.getline(_title, 260, delim);
	book.title = string(_title);

	//authors
	char _authors[800];
	stream.getline(_authors, 800, delim);
	book.authors = string(_authors);

	//average rating
	char averate[100];
	stream.getline(averate, 100, delim);
	book.average_rating = string(averate);

	// isbn
	char _isbn[20];
	stream.getline(_isbn, 20, delim);
	book.isbn = string(_isbn);

	//isbn13
	char _isbn13[20];
	stream.getline(_isbn13, 20, delim);
	book.isbn13 = string(_isbn13);

	//language_code
	char _langcode[20];
	stream.getline(_langcode, 20, delim);
	book.language_code = string(_langcode);

	//numpages
	char pages[20];
	stream.getline(pages, 20, delim);
	book.num_pages = string(pages);

	//ratings count
	char ratecount[20];
	stream.getline(ratecount, 20, delim);
	book.ratings_count = string(ratecount);

	//text review count
	char txtreviews[20];
	stream.getline(txtreviews, 20, delim);
	book.text_reviews_count = string(txtreviews);

	// pub date
	char pubdate[20];
	stream.getline(pubdate, 20, delim);
	book.publication_date = string(pubdate);

	//publisher
	char pub[80];
	stream.getline(pub, 80, '/');
	book.publisher = string(pub);

	//stream.ignore(1);

	return stream;
}


void book::print() {
	cout
		<< "\n\nBook ID = " << bookID << endl
		<< "Title = " << title << endl
		<< "Authors = " << authors << endl
		<< "Average Rating = " << average_rating << endl
		<< "ISBN = " << isbn << endl
		<< "ISBN13 = " << isbn13 << endl
		<< "Language Code = " << language_code << endl
		<< "Number of Pages = " << num_pages << endl
		<< "Count of Ratings = " << ratings_count << endl
		<< "Count of Text Reviews = " << text_reviews_count << endl
		<< "Publication Date = " << publication_date << endl
		<< "Publisher = " << publisher << endl;
}