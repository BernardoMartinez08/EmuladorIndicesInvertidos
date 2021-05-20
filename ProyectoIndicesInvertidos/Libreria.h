#pragma once

#include "Book.h"
#include <vector>

using namespace std;

class Libreria
{
	Libreria();

	vector<book> libros;

	bool agregar(book newBook);

	bool consultarSecuencial(int bookID);
	bool modificar(int bookID);
	bool eliminarLibro(int bookID);


};

