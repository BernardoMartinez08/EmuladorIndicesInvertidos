#include "Libreria.h"

Libreria::Libreria() {

}

bool Libreria::agregar(ostream file, book& newBook) {
    file << newBook;
}

bool Libreria::consultarSecuencial(istream file,int _bookID) {
    while (!file.eof()) {
        book book;
        file >> book;

        if (book.bookID == _bookID) {
            book.print();
            return true;
        }
    }
    return false;
}

bool Libreria::consultarLibro(istream file, int _posicion) {
    book book;
    file.seekg(ios::beg, _posicion);
    file >> book;
    book.print();
    return file.good();
}

