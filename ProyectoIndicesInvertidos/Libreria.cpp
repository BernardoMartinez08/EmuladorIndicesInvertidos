#include "Libreria.h"
#include <cstring>

//TODO Funcion para importar los libros desde el csv.
//TODO Funcion que el leer los libros del archivo original agregue palabras a los vectores y sus posiciones.

Libreria::Libreria() {
    InitLibreria();
}

bool Libreria::agregar() {
    ofstream file(fileArchivoPrincipal, ios::out | ios::binary);

    if (!archivoPrincipal) {
        cout << "Error al intentar abrir el archivo .bin de libros\n\n";
        return false;
    }

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
    file.close();
}

bool Libreria::consultarSecuencial(istream file,string _bookID) {
    while (!file.eof()) {
        book book;
        file >> book;

        if (book.bookID.compare(_bookID)) {
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

vector<long> Libreria::buscarByTitulo(string _word) {
    cargarIndiceTitulo();
    cargarIndicePrincipal();

    long _posicion = -1;

    while (!lecturaIndice_titulo.eof()) {
        index aux;
        lecturaIndice_titulo >> aux;
        
        if (aux.word == _word) {
            _posicion = aux.posicion;
            break;
        }
    }
    
    vector<long> posiciones;

    if (_posicion != -1) {
        lecturaIndicePrincipal.seekg(ios::beg, _posicion);
        while (!lecturaIndicePrincipal.eof()) {
            list aux;
            lecturaIndicePrincipal >> aux;
            if (aux.position != -1)
                posiciones.push_back(aux.position);
            else
                break;
        }
    }
    else {
        cout << "\nNO HAY LIBROS RELACIONADOS.";
    }

    return posiciones;
}

vector<long> Libreria::buscarByAutor(string _word) {
    cargarIndiceAutor();
    cargarIndicePrincipal();

    long _posicion = -1;

    while (!lecturaIndice_autor.eof()) {
        index aux;
        lecturaIndice_autor >> aux;

        if (aux.word == _word) {
            _posicion = aux.posicion;
            break;
        }
    }

    vector<long> posiciones;

    if (_posicion != -1) {
        lecturaIndicePrincipal.seekg(ios::beg, _posicion);
        while (!lecturaIndicePrincipal.eof()) {
            list aux;
            lecturaIndicePrincipal >> aux;
            if (aux.position != -1)
                posiciones.push_back(aux.position);
            else
                break;
        }
    }
    else {
        cout << "\nNO HAY LIBROS RELACIONADOS.";
    }

    return posiciones;
}

vector<long> Libreria::buscarByPublicador(string _word) {
    cargarIndicePublicador();
    cargarIndicePrincipal();

    long _posicion = -1;

    while (!lecturaIndice_publicador.eof()) {
        index aux;
        lecturaIndice_titulo >> aux;

        if (aux.word == _word) {
            _posicion = aux.posicion;
            break;
        }
    }

    vector<long> posiciones;

    if (_posicion != -1) {
        lecturaIndicePrincipal.seekg(ios::beg, _posicion);
        while (!lecturaIndicePrincipal.eof()) {
            list aux;
            lecturaIndicePrincipal >> aux;
            if (aux.position != -1)
                posiciones.push_back(aux.position);
            else
                break;
        }
    }
    else {
        cout << "\nNO HAY LIBROS RELACIONADOS.";
    }

    return posiciones;
}

void Libreria::cargarVectorLibros()
{
    cout << "Para cargar los datos:\nIndique la ubicacion del archivo .csv: ";
    cin >> fileArchivoPrincipal;

    archivoPrincipal.open(fileArchivoPrincipal, ios::in);

    if (archivoPrincipal.fail()) {
        cout << "No se pudo abrir el archivo Principal" << endl;
       // _getch();
        return;
    }

    book libroActual;
    while(!archivoPrincipal.eof())
    {
        long pos = archivoPrincipal.tellg();
        archivoPrincipal >> libroActual;
        libros.push_back(libroActual);
        // TODO usar la posicion actual del apuntador para escribir al indice principal
    }

    archivoPrincipal.close();
}

void Libreria::cargarArchivosIndices()
{
    cargarIndicePrincipal();

    cargarIndiceTitulo();

    cargarIndiceAutor();

    cargarIndicePublicador();
}

void Libreria::cargarIndicePublicador()
{
    // Indice publicador
    indice_publicador.open(fileIndice_publicador, ios::out);
    lecturaIndice_publicador.open(fileIndice_publicador, ios::in);
}

void Libreria::cargarIndiceAutor()
{
    // Indice Autor
    indice_publicador.open(fileIndice_publicador, ios::out);
    lecturaIndice_autor.open(fileIndice_autor, ios::in);
}

void Libreria::cargarIndiceTitulo()
{
    // Indice titulo
    indice_titulo.open(fileIndice_titulo, ios::out);
    lecturaIndice_titulo.open(fileIndice_titulo, ios::in);
}

void Libreria::cargarIndicePrincipal()
{
    // Indice Principal
    indicePrincipal.open(fileIndicePrincipal, ios::out);
    lecturaIndicePrincipal.open(fileIndicePrincipal, ios::in);
}

void Libreria::InitLibreria()
{
    cargarVectorLibros();
    cargarArchivosIndices();
}

void Libreria::crearIndicePrincipal()
{
    //TODO crear el indice principal    
}

void Libreria::crearIndiceSec_Titulo()
{
    //TODO Verificar si esto es funcional.
    cargarIndiceTitulo();
    cargarIndicePrincipal();
    
    for (int i = 0; i < titulos.size(); i++) {
        //Escribe la palabra en el indice de titulos.
        //Saca la posicion actual donde se va a guardar la lista en e archivo principal.
        long _posicion = indicePrincipal.tellp();
        titulos[i].posicion = _posicion;
        indice_titulo << titulos[i];

        //Cada palabra tiene un vector con sus posiciones, escribir esas posiciones en el indice principal.
        for (int j = 0; j < titulos[i].lista.size(); j++) {
            indicePrincipal << titulos[i].lista[j];
        }
        indicePrincipal << -1; //Al final indicar -1 de que el anterior era el ultimo libro.
    }
    indice_titulo.close();
    indicePrincipal.close();
}

void Libreria::crearIndiceSec_Autor()
{
    //TODO Verificar si esto es funcional.
    cargarIndiceAutor();
    cargarIndicePrincipal();

    for (int i = 0; i < autores.size(); i++) {
        //Escribe la palabra en el indice de titulos.
        //Saca la posicion actual donde se va a guardar la lista en e archivo principal.
        long _posicion = indicePrincipal.tellp();
        autores[i].posicion = _posicion;
        indice_autor << autores[i];

        //Cada palabra tiene un vector con sus posiciones, escribir esas posiciones en el indice principal.
        for (int j = 0; j < autores[i].lista.size(); j++) {
            indicePrincipal << autores[i].lista[j];
        }
        indicePrincipal << -1; //Al final indicar -1 de que el anterior era el ultimo libro.
    }
    indice_autor.close();
    indicePrincipal.close();
}

void Libreria::crearIndiceSec_Publicador()
{
    //TODO Verificar si esto es funcional.
    cargarIndicePublicador();
    cargarIndicePrincipal();

    for (int i = 0; i < publicador.size(); i++) {
        //Escribe la palabra en el indice de titulos.
        //Saca la posicion actual donde se va a guardar la lista en e archivo principal.
        long _posicion = indicePrincipal.tellp();
        publicador[i].posicion = _posicion;
        indice_publicador << publicador[i];

        //Cada palabra tiene un vector con sus posiciones, escribir esas posiciones en el indice principal.
        for (int j = 0; j < autores[i].lista.size(); j++) {
            indice_publicador << publicador[i].lista[j];
        }
        indicePrincipal << -1; //Al final indicar -1 de que el anterior era el ultimo libro.
    }
    indice_publicador.close();
    indicePrincipal.close();
}

//TODO Se puede hacer estas tres funciones en una sola?
//Recordar que se debe hacer un match entre palabras de diferentes campos entonces creo
//que es mejor tenerlas separadas.

//TODO Hacer una funcion quer reciba 2 vectores<long> y devuelva un vector del mismo tipo con la intersepcion de los dos recibidos.
//Esta bien??
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

vector<long> Libreria::buscarByTituloSec(string _titulo) {
    vector<long> posiciones;
    while (!archivoPrincipal.eof()) {
        book book;
        long _posicion = archivoPrincipal.tellg();
        archivoPrincipal >> book;

        if (book.title.find(_titulo) != string::npos) {
            posiciones.push_back(_posicion);
        }
    }
    archivoPrincipal.close();
    return posiciones;
}

vector<long> Libreria::buscarByAutorSec(string _autor) {
    vector<long> posiciones;
    while (!archivoPrincipal.eof()) {
        book book;
        long _posicion = archivoPrincipal.tellg();
        archivoPrincipal >> book;

        if (book.title.find(_autor) != string::npos) {
            posiciones.push_back(_posicion);
        }
    }
    archivoPrincipal.close();
    return posiciones;
}

vector<long> Libreria::buscarByPublicadorSec(string _publicador) {
    vector<long> posiciones;
    while (!archivoPrincipal.eof()) {
        book book;
        long _posicion = archivoPrincipal.tellg();
        archivoPrincipal >> book;

        if (book.title.find(_publicador) != string::npos) {
            posiciones.push_back(_posicion);
        }
    }
    archivoPrincipal.close();
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