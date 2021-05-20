#include "book.h"

book::book() {
    bookID = 0;
    title;
    authors;
    average_rating = 0;
    isbn;
    isbn13;
    language_code;
    num_pages = 0;
    ratings_count = 0;
    text_reviews_count = 0;
    publication_date;
    publisher;
}

ostream& operator<<(ostream& stream, const book& book) {
	if (!stream) {
		cout << "\nSe presento un problema al intentar abrir el archivo de libros .csv :(\n";
		return stream;
	}
	
	stream
		<< book.bookID << ","
		<< book.title << ","
		<< book.authors << ","
		<< book.average_rating << ","
		<< book.isbn << ","
		<< book.isbn13 << ","
		<< book.language_code << ","
		<< book.num_pages << ","
		<< book.ratings_count << ","
		<< book.text_reviews_count << ","
		<< book.publication_date << ","
		<< book.publisher << ","
		<< flush;

	return stream;
}

istream& operator>>(istream& stream, book& book) {
	if (!stream) {
		cout << "\nSe presento un problema al intentar abrir el archivo de libros .csv :(\n";
		return stream;
	}
	
	// leer datos del stream
	char delim = ',';

	//BookID
	char _bookID[7];
	stream.getline(_bookID, 7, delim);
	book.bookID = int(_bookID);

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
	book.average_rating = atof(averate);

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
	book.num_pages = int(pages);

	//ratings count
	char ratecount[20];
	stream.getline(ratecount, 20, delim);
	book.ratings_count = int(ratecount);

	//text review count
	char txtreviews[20];
	stream.getline(txtreviews, 20, delim);
	book.text_reviews_count = int(txtreviews);

	// pub date
	char pubdate[20];
	stream.getline(pubdate, 20, delim);
	book.publication_date = string(pubdate);

	//publisher
	char pub[80];
	stream.getline(pub, 80, delim);
	book.publisher = string(pub);

	stream.ignore(1);

	return stream;
}

void book::print() {
	cout 
		<< "Book ID = " << bookID << endl
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
		<< "Publisher = " << publisher << endl
		<< endl << flush;
}