#include "Libreria.h"
#include <cstring>


Libreria::Libreria() {
    titulos = new vector<index>;
    autores = new vector<index>;
    publicador = new vector<index>;
}

bool Libreria::agregar(ostream& file) {
    cout << " ***** I N G R E S O  D E  L I B R O S ***** \n\n";

    book nuevo;
    cout << "INGRESE LOS DATOS PARA EL LIBRO:\nIndique el id: ";
    cin >> nuevo.bookID;

    cout << "Indique el titulo: ";
    cin >> nuevo.title;

    cout << "Indique el autor: ";
    cin >> nuevo.authors;

    cout << "Indique la puntuacion media: ";
    cin >> nuevo.average_rating;

    cout << "Indique el isbn: ";
    cin >> nuevo.isbn;

    cout << "Indique el isbn13: ";
    cin >> nuevo.isbn13;

    cout << "Indique el codigo de idioma: ";
    cin >> nuevo.language_code;

    cout << "Indique el numero de paginas: ";
    cin >> nuevo.num_pages;

    cout << "Indique el numero de puntuaciones: ";
    cin >> nuevo.ratings_count;

    cout << "Indique el numero de reviews: ";
    cin >> nuevo.text_reviews_count;

    cout << "Indique el numero de paginas: ";
    cin >> nuevo.num_pages;

    cout << "Indique el fecha de publicacion: ";
    cin >> nuevo.publication_date;

    cout << "Indique el publicador: ";
    cin >> nuevo.publisher;

    file << nuevo;
    return true;
}

bool Libreria::agregarDataToIndex(istream& file) {
    while (!file.eof()) {
        book book;
        long posicion = file.tellg();
        file >> book;
        agregarPalabras(book,posicion);
    }
    return true;
}

bool Libreria::consultarLibro(istream& file, int _posicion) {
    book book;
    file.seekg(ios::beg, _posicion);
    file >> book;
    book.print();
    return file.good();
}

vector<long> Libreria::buscarByTitulo(string _word) {
    vector<long> aux;
    for (int i = 0; i < titulos->size(); i++) {
        if (titulos->at(i).word == _word) {
            for (int j = 0; j < titulos->at(i).lista->size(); j++) {
                aux.push_back(titulos->at(i).lista->at(j).position);
            }
        }
    }
    return aux;
}

vector<long> Libreria::buscarByAutor(string _word) {
    vector<long> aux;
    for (int i = 0; i < autores->size(); i++) {
        if (autores->at(i).word == _word) {
            for (int j = 0; j < autores->at(i).lista->size(); j++) {
                aux.push_back(autores->at(i).lista->at(j).position);
            }
        }
    }
    return aux;
}

vector<long> Libreria::buscarByPublicador(string _word) {
    vector<long> aux;
    for (int i = 0; i < publicador->size(); i++) {
        if (publicador->at(i).word == _word) {
            for (int j = 0; j < publicador->at(i).lista->size(); j++) {
                aux.push_back(publicador->at(i).lista->at(j).position);
            }
        }
    }
    return aux;
}

void Libreria::cargarArchivosIndices(istream& file){
    //CARGAR EL INDICE DE TITULOS
    ifstream lecturaIndice_titulo(fileIndice_titulo, ios::in | ios::binary);

    long _posicion = -1;

    while (!lecturaIndice_titulo.eof()) {
        index auxIndex;
        lecturaIndice_titulo >> auxIndex;

        titulos->push_back(auxIndex);
        _posicion = auxIndex.posicion;


        if (_posicion != -1) {
            file.seekg(_posicion);
            while (!file.eof()) {
                list auxList;
                file >> auxList;
                if (auxList.position != -1)
                    auxIndex.lista->push_back(auxList);
                else
                    break;
            }
        }
    }
    lecturaIndice_titulo.close();

    //CARGAR EL INDICE DE AUTORES
    ifstream lecturaIndice_autor(fileIndice_autor, ios::in | ios::binary);

    _posicion = -1;

    while (!lecturaIndice_autor.eof()) {
        index auxIndex;
        lecturaIndice_autor >> auxIndex;

        autores->push_back(auxIndex);
        _posicion = auxIndex.posicion;


        if (_posicion != -1) {
            file.seekg(_posicion);
            while (!file.eof()) {
                list auxList;
                file >> auxList;
                if (auxList.position != -1)
                    auxIndex.lista->push_back(auxList);
                else
                    break;
            }
        }
    }
    lecturaIndice_autor.close();
    
    //CARGAR EL INDICE DE PUBLICADORES
    ifstream lecturaIndice_publicador(fileIndice_publicador, ios::in | ios::binary);

    _posicion = -1;

    while (!lecturaIndice_publicador.eof()) {
        index auxIndex;
        lecturaIndice_publicador >> auxIndex;

        publicador->push_back(auxIndex);
        _posicion = auxIndex.posicion;


        if (_posicion != -1) {
            file.seekg(_posicion);
            while (!file.eof()) {
                list auxList;
                file >> auxList;
                if (auxList.position != -1)
                    auxIndex.lista->push_back(auxList);
                else
                    break;
            }
        }
    }
    lecturaIndice_publicador.close();
}

bool Libreria::guardarIndices(){
    crearIndiceSec_Titulo();
    crearIndiceSec_Autor();
    crearIndiceSec_Publicador();
    return true;
}

void Libreria::crearIndiceSec_Titulo(){
    ofstream indice_titulo(fileIndice_titulo, ios::out | ios::app | ios::binary);
    ofstream indicePrincipal(fileIndicePrincipal, ios::out | ios::app | ios::binary);

    for (int i = 0; i < titulos->size(); i++) {
        long _posicion = indicePrincipal.tellp();
        titulos->at(i).posicion = _posicion;
        indice_titulo << titulos->at(i);

        for (int j = 0; j < titulos->at(i).lista->size(); j++) {
            indicePrincipal << titulos->at(i).lista->at(j);
        }
        indicePrincipal << -1;
    }
    indice_titulo.close();
    indicePrincipal.close();
}

void Libreria::crearIndiceSec_Autor(){
    ofstream indice_autor(fileIndice_autor, ios::out | ios::app | ios::binary);
    ofstream indicePrincipal(fileIndicePrincipal, ios::out | ios::app | ios::binary);

    for (int i = 0; i < autores->size(); i++) {
        long _posicion = indicePrincipal.tellp();
        autores->at(i).posicion = _posicion;
        indice_autor << autores->at(i);

        for (int j = 0; j < autores->at(i).lista->size(); j++) {
            indicePrincipal << autores->at(i).lista->at(j);
        }
        indicePrincipal << -1;
    }
    indice_autor.close();
    indicePrincipal.close();
}

void Libreria::crearIndiceSec_Publicador(){
    ofstream indice_publicador(fileIndice_publicador, ios::out | ios::app |  ios::binary);
    ofstream indicePrincipal(fileIndicePrincipal, ios::out | ios::app | ios::binary);

    for (int i = 0; i < publicador->size(); i++) {
        long _posicion = indicePrincipal.tellp();
        publicador->at(i).posicion = _posicion;
        indice_publicador << publicador->at(i);

        for (int j = 0; j < publicador->at(i).lista->size(); j++) {
            indicePrincipal << publicador->at(i).lista->at(j);
        }
        indicePrincipal << -1;
    }
    indice_publicador.close();
    indicePrincipal.close();
}

vector<long> Libreria::matchLibros(vector<long>& a, vector<long>& b) {
    vector<long> resultado;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j])
                resultado.push_back(a[i]);
        }
    }

    return resultado;
}

vector<long> Libreria::buscarByTituloSec(string _titulo, istream& file) {
    vector<long> posiciones;
    while (!file.eof()) {
        book book;
        long _posicion = file.tellg();
        file >> book;

        if (book.title.find(_titulo) != string::npos) {
            posiciones.push_back(_posicion);
        }
    }
    return posiciones;
}

vector<long> Libreria::buscarByAutorSec(string _autor, istream& file) {
    vector<long> posiciones;
    while (!file.eof()) {
        book book;
        long _posicion = file.tellg();
        file >> book;

        if (book.title.find(_autor) != string::npos) {
            posiciones.push_back(_posicion);
        }
    }
    return posiciones;
}

vector<long> Libreria::buscarByPublicadorSec(string _publicador, istream& file) {
    vector<long> posiciones;
    while (!file.eof()) {
        book book;
        long _posicion = file.tellg();
        file >> book;

        if (book.title.find(_publicador) != string::npos) {
            posiciones.push_back(_posicion);
        }
    }
    return posiciones;
}

bool Libreria::read(istream& stream, book& book) {
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
    stream.getline(pub, 80, ';');
    book.publisher = string(pub);

    //stream.ignore(1);

    return stream.good();
}

bool Libreria::agregarPalabras(book& _book, long _posicion) {
    //Agregar el titulo
    istringstream isstream(_book.title);

    while (!isstream.eof()) {
        string tempStr;
        isstream >> tempStr;
        bool existe = false;
        list auxList;
        auxList.position = _posicion;

        
        for (int i = 0; i < titulos->size(); i++) {
            if (titulos->at(i).word == (tempStr)) {
                titulos->at(i).lista->push_back(auxList);
                existe = true;
            }
        }
        

        if (!existe) {
            index auxIndex;
            auxIndex.word = tempStr;
            auxIndex.lista->push_back(auxList);
            titulos->push_back(auxIndex);
        }
    }

    //Agregar el autores
    istringstream isstream2(_book.authors);

    while (!isstream2.eof()) {
        string tempStr;
        isstream2 >> tempStr;
        bool existe = false;
        list auxList;
        auxList.position = _posicion;

       
        for (int i = 0; i < autores->size(); i++) {
            if (autores->at(i).word == (tempStr)) {
                autores->at(i).lista->push_back(auxList);
                existe = true;
            }
        }
        

        if (!existe) {
            index auxIndex;
            auxIndex.word = tempStr;
            auxIndex.lista->push_back(auxList);
            autores->push_back(auxIndex);
        }
    }

    //Agregar en publicadores
    istringstream isstream3(_book.publisher);

    while (!isstream3.eof()) {
        string tempStr;
        isstream3 >> tempStr;
        bool existe = false;
        list auxList;
        auxList.position = _posicion;

       
        for (int i = 0; i < publicador->size(); i++) {
            if (publicador->at(i).word == (tempStr)) {
                publicador->at(i).lista->push_back(auxList);
                existe = true;
            }
        }
        

        if (!existe) {
            index auxIndex;
            auxIndex.word = tempStr;
            auxIndex.lista->push_back(auxList);
            publicador->push_back(auxIndex);
        }
    }
    return true;
}