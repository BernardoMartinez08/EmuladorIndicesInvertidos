#pragma once
#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include "Book.h"
#include "Index.h"
#include "List.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Libreria
{
public:
	Libreria();

	bool read(istream&, book&);

	vector<book> libros;

	vector<index> titulos;
	vector<index> autores;
	vector<index> publicador;


	bool agregar();

	bool consultarSecuencial(istream file, string bookID);
	bool consultarLibro(istream file, int posicion);
	bool agregarPalabras(book&, long);

	//Busqueda a traves del indice
	vector<long> buscarByTitulo(string);
	vector<long> buscarByAutor(string);
	vector<long> buscarByPublicador(string);

	//Busqueda secuencial
	vector<long> buscarByTituloSec(string);
	vector<long> buscarByAutorSec(string);
	vector<long> buscarByPublicadorSec(string);

	vector<long> matchLibros(vector<long>&, vector<long>&);


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

	void crearIndicePrincipal();
	void crearIndiceSec_Titulo();
	void crearIndiceSec_Autor();
	void crearIndiceSec_Publicador();
};

#endif // !LIBRERIA_H

