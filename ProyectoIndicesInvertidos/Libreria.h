#pragma once

#include "Book.h"
#include <vector>

using namespace std;

class Libreria
{
public:
	Libreria();

	vector<book> libros;

	bool agregar(ostream file,book& newBook);

	bool consultarSecuencial(istream file, int bookID);
	bool consultarLibro(istream file, int posicion);

	int posicionLibro(istream index, int key);

	bool modificar(int bookID);
	bool eliminarLibro(ostream file, int bookID);


};

