#include "Index.h"
index::index() {
	word;
	posicion = 0;
	lista = new vector<list>;
}

ostream& operator<<(ostream& stream, const index& data) {
	// escribir datos al stream
	stream
		<< data.word << ","
		<< data.posicion
		<< flush;

	return stream;
}

istream& operator>>(istream& stream, index& data) {
	// leer datos del stream

	//palabra
	char _word[20];
	stream.getline(_word, 20, ',');
	data.word = string(_word);

	//first
	char _first[8];
	stream.getline(_first, 8);
	data.posicion = int(_first);

	//stream.ignore(1);

	return stream;
}