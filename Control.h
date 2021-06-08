#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include "Biblioteca.h"
class Control
{
public:
	Control();
	virtual ~Control();
	void MenuInicioS();
	void MenuLibros(Usuario*);
	void MenuUsuarios(Usuario *);
	void MenuPrestamo(Usuario*);
	void MenuPrincipal();
	void SubMenu(Usuario *);
	void LlenaListas();
	void UsuarioNuevo(Usuario *);
	void cambioEstadoUsuario(string);
private:
	Biblioteca Global;
};

#endif // !CONTROL_H