#include "Libreria.h"
#include "DelimTextBuffer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

using namespace std;
int main(int args, char *argv[]) {

	if (args >= 6) {
		int registros = 1;
		ifstream origen(argv[1], ios::in);
		ofstream destino(argv[2], ios::out | ios::app | ios::binary);
		Libreria Lib;

		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;

		//RECUPERAR LOS DATOS DEL ARCHIVO ORIGINAL
		start = std::chrono::steady_clock::now();

		cout << "\n\n***RECUPERACION EN PROCESO***";
		while (!origen.eof()) {
			book _book;
			char titulos[256];
			origen.getline(titulos, 256, '\n');

			Lib.read(origen,_book);

			if (_book.bookID == "")
				break;

			destino << _book;
			registros++;
		}

		end = std::chrono::steady_clock::now();
		std::chrono::duration<float> duration = end - start;

		float tiempo = duration.count();

		cout << "\n\n***RECUPERACION FINALIZADA***\nSe recuperraron: " << registros << "  registros en total.\nEl programa tomo: " << tiempo << " segundos en recuperar los datos y guardarlos en el nuevo archivo.";

		origen.close();
		destino.close();




		//CREAR INDICES
		ifstream File(argv[2], ios::in | ios::binary);

		start = std::chrono::steady_clock::now();

		cout << "\n\n***CREACION DE INDICES***\nEsto puede tomar un poco de tiempo.";

		Lib.agregarDataToIndex(File);
		cout << "\nCREADOS!*\nGUARDANDO.";
		Lib.guardarIndices();

		end = std::chrono::steady_clock::now();
		duration = end - start;

		tiempo = duration.count();

		cout << "\n\n***CREACION FINALIZADA***\nEl programa tomo: " << tiempo << " segundos en crear y guardar los indices.";
		File.close();





		//RECUPERAR INDICES
		Libreria Lib2;
		ifstream File2(argv[2], ios::in | ios::binary);
		start = std::chrono::steady_clock::now();

		cout << "\n\n***RECUPERACION DE INDICES***";

		Lib2.cargarArchivosIndices(File2);

		end = std::chrono::steady_clock::now();
		duration = end - start;

		tiempo = duration.count();

		cout << "\n\n***RECUPERACION FINALIZADA***\nEl programa tomo: " << tiempo << " segundos en recuperar los indices.";
		File2.close();




		//BUSQUEDA EN INDICES
		ifstream File3(argv[2], ios::in | ios::binary);
		start = std::chrono::steady_clock::now();

		cout << "\n\n***BUSQUEDA CON INDICES***";

		vector<long> titulos = Lib2.buscarByTitulo(argv[3]);
		vector<long> autores = Lib2.buscarByAutor(argv[4]);
		vector<long> publicadores = Lib2.buscarByPublicador(argv[5]);

		vector<long> match = Lib2.matchLibros(titulos, autores);
		match = Lib2.matchLibros(match, publicadores);

		cout << "\n\nResultados de la Busqueda:\n";
		for (int i = 0; i < match.size(); i++) {
			book _book;
			File3.seekg(match[i]);
			File3 >> _book;
			_book.print();
		}


		end = std::chrono::steady_clock::now();
		duration = end - start;

		tiempo = duration.count();
		File3.close();
		cout << "\n\n***BUSQUEDA FINALIZADA***\nEl programa tomo: " << tiempo << " segundos en buscar en indices.";





		//BUSQUEDA SECUENCIAL
		ifstream File4(argv[2], ios::in | ios::binary);
		start = std::chrono::steady_clock::now();

		cout << "\n\n***BUSQUEDA SECUENCIAL***";

		vector<long> titulos2 = Lib2.buscarByTituloSec(argv[3], File4);
		vector<long> autores2 = Lib2.buscarByAutorSec(argv[4], File4);
		vector<long> publicadores2 = Lib2.buscarByPublicadorSec(argv[5], File4);

		match = Lib2.matchLibros(titulos2, autores2);
		match = Lib2.matchLibros(match, publicadores2);

		cout << "\n\nResultados de la Busqueda:\n";
		for (int i = 0; i < match.size(); i++) {
			book _book;
			File4.seekg(match[i]);
			File4 >> _book;
			_book.print();
		}


		end = std::chrono::steady_clock::now();
		duration = end - start;

		tiempo = duration.count();

		cout << "\n\n***BUSQUEDA FINALIZADA***\nEl programa tomo: " << tiempo << " segundos en buscar secuencialmente";


	}
	else {
		cout << "\n\n\"!!!\" FALTAN PARAMETROS.\nLos parametros son:\n1. Archivo Origen (.csv).\n2. Archivo Destino (.bin).\n3. Titulo a buscar.\n4. Autor a buscar.\n5. Publicador a buscar.\n\nINTENTALO DENUEVO.";

	}


	system("PAUSE");
	return 0;
}
