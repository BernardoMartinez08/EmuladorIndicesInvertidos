#pragma once

#include "Book.h"
#include "Index.h"
#include "List.h"
#include <vector>
#include <string>

using namespace std;

class Libreria
{
public:
	Libreria();

	vector<book> libros;

	vector<index> titulos;
	vector<index> autores;
	vector<index> publicador;


	bool agregar(ostream file,book& newBook);

	bool consultarSecuencial(istream file, int bookID);
	bool consultarLibro(istream file, int posicion);

	vector<long> buscarByTitulo(istream file,string);
	vector<long> buscarByAutor(istream file,string);
	vector<long> buscarByPublicador(istream file,string);

	bool modificar(int bookID);
	bool eliminarLibro(ostream file, int bookID);

	string fileIndicePrincipal{ "mainIndex.txt" };
	string fileIndice_titulo{ "titleIndex.txt" };
	string fileIndice_autor{ "authorIndex.txt" };
	string fileIndice_publicador{ "publisherIndex.txt" };
	string fileArchivoPrincipal{};

	ifstream archivoPrincipal;

	ifstream lecturaIndicePrincipal;
	ifstream lecturaIndice_titulo;
	ifstream lecturaIndice_autor;
	ifstream lecturaIndice_publicador;

	ofstream indicePrincipal;
	ofstream indice_titulo;
	ofstream indice_autor;
	ofstream indice_publicador;

private:
	void cargarVectorLibros();
	void cargarArchivosIndices();
	void InitLibreria();

	void crearIndicePrincipal();
	void crearIndiceSec_Titulo();
	void crearIndiceSec_Autor();
	void crearIndiceSec_Publicador();
};

