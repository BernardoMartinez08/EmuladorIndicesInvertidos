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

vector<long> Libreria::buscarByTitulo(istream file, string _word) {
    if (!file) {
        cout << "\nSe presento un problema al intentar abrir el archivo de lista .list :(\n";
        return;
    }

    long _first = -1;
    vector<long> posiciones;

    for (int i = 0; i < autores.size(); i++) {
        if (autores[i].word == _word) {
            if (autores[i].status != false) {
                _first = autores[i].first;
                break;
            }
            else {
                cout << "NO EXISTEN LIBROS RELACIONADOS";
                break;
            }
        }
    }

    long _next = 0;
    while (_next != -1) {
        list data;
        file >> data;

        posiciones.push_back(data.position);
        _next = data.next;
    }

    return posiciones;
}

