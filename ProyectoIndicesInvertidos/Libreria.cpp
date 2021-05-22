#include "Libreria.h"

Libreria::Libreria() {
    InitLibreria();
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

    long _next = -1;
    vector<long> posiciones;

    for (int i = 0; i < autores.size(); i++) {
        if (autores[i].word == _word) {
            if (autores[i].status != false) {
                _next = autores[i].first;
                break;
            }
            else {
                cout << "NO EXISTEN LIBROS RELACIONADOS";
                break;
            }
        }
    }

    while (_next != -1) {
        list data;
        file.seekg(_next);

        file >> data;

        posiciones.push_back(data.position);
        _next = data.next;
    }

    return posiciones;
}

void Libreria::cargarVectorLibros()
{
    //TODO que imprima texto para pedir el nombre del libro
    cin >> fileArchivoPrincipal << flush;

    archivoPrincipal(fileArchivoPrincipal, ios::in);

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
    // Indice Principal
    indicePrincipal(fileIndicePrincipal, ios::out);
    lecturaIndicePrincipal(fileIndicePrincipal, ios::in);

    // Indice titulo
    indice_titulo(fileIndice_titulo, ios::out);
    lecturaIndice_titulo(fileIndice_titulo, ios::in);

    // Indice Autor
    fileIndice_autor(fileIndice_autor, ios::out);
    lecturaIndice_autor(fileIndice_autor, ios::in);

    // Indice publicador
    indice_publicador(fileIndice_publicador, ios::out);
    lecturaIndice_publicador(fileIndice_publicador, ios::in);
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
    //TODO crear el indice de titulos
}

void Libreria::crearIndiceSec_Autor()
{
    //TODO crear el indice de autores
}

void Libreria::crearIndiceSec_Publicador()
{
    //TODO crear el indice de publicadores
}
