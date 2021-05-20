#include "book.h"

book::book() {

}

bool book::agregar(int _bookID, char* _title, char* _authors, int _average_rating, int _isbn, int _isbn13, char* _language_code, int _num_pages, int _ratings_count, int _text_reviews_count, char* _publication_date, char* _publisher) {
    bookID = _bookID;
    average_rating = _average_rating;
    isbn = _isbn;
    isbn13 = isbn13;
    num_pages = _num_pages;
    ratings_count = _ratings_count;
    text_reviews_count = _text_reviews_count;

    title = new char[strlen(_title)];
    strcpy_s(title, strlen(_title) + 1, _title);

    authors = new char[strlen(_authors)];
    strcpy_s(authors, strlen(_authors) + 1, _authors);

    language_code = new char[strlen(_language_code)];
    strcpy_s(language_code, strlen(_language_code) + 1, _language_code);

    publication_date = new char[strlen(_publication_date)];
    strcpy_s(publication_date, strlen(_publication_date) + 1, _publication_date);

    return true;
}

bool book::guardar() {
    ofstream file("books.csv", ios::out | ios::app);

    if (!file) {
        cout << "\nSe presento un problema al intentar abrir el archivo de libros . csv :(\n";
        return false;
    }

    return file.good();
}

bool book::consultarSecuencial(int _bookID) {
   ifstream file("books.csv", ios::in);

    if (!file) {
        cout << "\nSe presento un problema al intentar abrir el archivo de libros . csv :(\n";
        return false;
    }


    return file.good();
}

bool book::modificar() {

}

bool book::eliminar() {

}