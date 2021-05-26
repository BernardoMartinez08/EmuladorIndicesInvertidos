#include "List.h"

list::list() {
	position = 0;
}

ostream& operator<<(ostream& stream, const list& data) {
	// escribir datos al stream
	stream
		<< data.position 
		<< flush;

	return stream;
}

istream& operator>>(istream& stream, list& data) {
	// leer datos del stream

	//Posicion
	char _position[8];
	stream.getline(_position, 8);
	data.position = long(_position);

	//stream.ignore(1);

	return stream;
}