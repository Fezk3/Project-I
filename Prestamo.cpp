#include "Prestamo.h"

// id unico por prestamo
int Prestamo::num = 1;

Prestamo::Prestamo(string id_libro, string id_usuario) : id_libro(id_libro), id_usuario(id_usuario){

	this->id += std::to_string(num);
	num++;
	setDiaInicio(); setVencimiento();
}

Prestamo::~Prestamo() {

}

//sets
void Prestamo::setIdLibro(string id_libro) {

	this->id_libro = id_libro;

}

void Prestamo::setIdUsuario(string id_usuario) {

	this->id_usuario = id_usuario;

}

void Prestamo::setDiaInicio() {

	std::time_t t = std::time(0);   
	std::tm* now = std::localtime(&t);
	dia_prestamo = std::to_string((now->tm_year + 1900)) += '-' + std::to_string((now->tm_mon + 1)) += "-" + std::to_string(now->tm_mday);

}

void Prestamo::setVencimiento() {

	int dia = 0, mes = 0;
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	if(now->tm_mday + 3 > 30){

		if (now->tm_mday == 28) {
			dia = 1;
		}
		else if (now->tm_mday == 29) {
			dia = 2;
		}
		else if (now->tm_mday == 30) {
			dia = 3;
		}
		else if (now->tm_mday == 31) {
			dia = 4;
		}
		mes = now->tm_mon+2;
		dia_vencimiento = std::to_string((now->tm_year + 1900)) += "-" + std::to_string(mes) += "-" + std::to_string(dia);

	}
	else {
		dia_vencimiento = std::to_string((now->tm_year + 1900)) += "-" + std::to_string(now->tm_mon + 1) += "-" + std::to_string(now->tm_mday + 3);
	}

}

//gets
string Prestamo::getIdUsuario() {

	return id_usuario;

}

string Prestamo::getIdLibro() {

	return id_libro;

}

string Prestamo::getVencimiento() {

	return dia_vencimiento;

}

string Prestamo::getDiaInicio() {

	return dia_prestamo;

}

string Prestamo::getId() {

	return id;

}

//methods
string Prestamo::toString() {

	stringstream x;

	x << "Id del prestamo: " << id << std::endl;
	x << "Id del usuario: " << id_usuario << std::endl;
	x << "Id del libro prestado: " << id_libro << std::endl;
	x << "Dia en que se realizo el prestamo: " << dia_prestamo << std::endl;
	x << "Dia de vencimiento: " << dia_vencimiento << std::endl;

	return x.str();

}

