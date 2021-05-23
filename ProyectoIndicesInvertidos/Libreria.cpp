#include "Libreria.h"

Libreria::Libreria() {
    InitLibreria();
}

bool Libreria::agregar() {
    ofstream file(fileArchivoPrincipal, ios::out | ios::binary);

    if (!archivoPrincipal) {
        cout << "Error al intentar abrir el archivo .bin de libros\n\n";
        return;
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
        _getch();
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
