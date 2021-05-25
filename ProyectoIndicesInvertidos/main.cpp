#include "Libreria.h"
#include "DelimTextBuffer.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(){
	ifstream leer("books_fixed.csv",ios::in);
	ofstream escribir("copia.bin", ios::out, ios::binary);
	Libreria lib;
	while (!leer.eof()) {
		book libro;

		char titulos[256];
		leer.getline(titulos, 256, '\n');

		lib.read(leer, libro);
		//libro.print();
		escribir << libro;
	}
	leer.close();
	escribir.close();
}
