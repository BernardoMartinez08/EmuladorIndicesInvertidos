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

	vector<index>* titulos;
	vector<index>* autores;
	vector<index>* publicador;


	bool agregar(ostream&);

	bool agregarDataToIndex(istream& file);
	bool guardarIndices();
	bool consultarLibro(istream& file, int posicion);
	bool agregarPalabras(book&, long);
	void cargarArchivosIndices(istream&);

	//Busqueda a traves del indice
	vector<long> buscarByTitulo(string);
	vector<long> buscarByAutor(string);
	vector<long> buscarByPublicador(string);

	//Busqueda secuencial
	vector<long> buscarByTituloSec(string, istream&);
	vector<long> buscarByAutorSec(string, istream&);
	vector<long> buscarByPublicadorSec(string, istream&);

	vector<long> matchLibros(vector<long>&, vector<long>&);


	string fileIndicePrincipal{ "mainIndex.txt" };
	string fileIndice_titulo{ "titleIndex.txt" };
	string fileIndice_autor{ "authorIndex.txt" };
	string fileIndice_publicador{ "publisherIndex.txt" };

private:
	void crearIndiceSec_Titulo();
	void crearIndiceSec_Autor();
	void crearIndiceSec_Publicador();
};

#endif // !LIBRERIA_H

