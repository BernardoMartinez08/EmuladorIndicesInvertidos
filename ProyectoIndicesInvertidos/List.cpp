#include "List.h"

list::list() {
	position = 0;
	next = 0;
}

ostream& operator<<(ostream& stream, const list& data) {
	if (!stream) {
		cout << "\nSe presento un problema al intentar abrir el archivo de lista .list :(\n";
		return stream;
	}

	stream
		<< data.position 
		<< data.next
		<< flush;

	return stream;
}

istream& operator>>(istream& stream, list& data) {
	if (!stream) {
		cout << "\nSe presento un problema al intentar abrir el archivo de indice .index :(\n";
		return stream;
	}

	// leer datos del stream

	//first
	char _position[8];
	stream.getline(_position, 8);
	data.position = long(_position);

	//status
	char _next[8];
	stream.getline(_next, 8);
	data.next = long(_next);

	//stream.ignore(1);

	return stream;
}