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


};

