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

bool book::guardar() {
    ofstream file("books.csv", ios::out | ios::app);

    if (!file) {
        cout << "\nSe presento un problema al intentar abrir el archivo de libros . csv :(\n";
        return false;
    }

    return file.good();
}