#include "Libreria.h"
#include "DelimTextBuffer.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	//ifstream leer("books_fixed.csv",ios::in);
	//ofstream escribir("copia.bin", ios::out, ios::binary);
	Libreria lib;

	/*while (!leer.eof()) {
		book libro;

		char titulos[256];
		leer.getline(titulos, 256, '\n');

		lib.read(leer, libro);
		libro.print();
		if (libro.bookID == "")
			break;

		escribir << libro;
	}

	leer.close();
	escribir.close();*/

	//ifstream leer2("copia.bin", ios::in, ios::binary);

	/*while(!leer2.eof()) {
		book libro;

		leer2 >> libro;
		libro.print();
	}
	leer2.close();
	cout << "LISTO";*/

	/*lib.archivoPrincipal.open("copia.bin", ios::in, ios::binary);
	vector<long> posiciones;
	posiciones = lib.buscarByTituloSec("Harry");
	lib.archivoPrincipal.close();

	ifstream leer2("copia.bin", ios::in, ios::binary);
	for (int i = 0; i < posiciones.size(); i++) {
		book libro;

		cout << "\nPosicion: " << posiciones[i] << "\n";
		long pos = posiciones[i];
		leer2.seekg(pos);
		leer2 >> libro;
		libro.print();
	}
	leer2.close();
*/

}
