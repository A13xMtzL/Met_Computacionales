#pragma once
#ifndef _LEXER
#define _LEXER


#include <iostream>
#include <string>


using namespace std;

class TipoSimbolo {
public:
	static const int Error = -1;
	static const int Identificador = 0;
	static const int Entero = 1;
	static const int Real = 2;
	static const int Cadena = 3;
	static const int Tipo = 4;
	static const int Suma = 5;

	static const int Resta = 6; // este es nuevo, para reordenar 

	static const int Op_Multiplicacion = 7;

	static const int Op_Division = 8;// este es nuevo, para reordenar 

	//static const int OPREL = 7;
	//static const int OPOR = 8;
	//static const int OPAND = 9;
	//static const int OPNOT = 10;
	static const int OPIGUALDAD = 9; // 11
	//static const int PUNTO_COMA = 12;
	//static const int COMA = 13;
	static const int PARENTESIS_ABRE = 10; // 14
	static const int PARENTESIS_CIERRA = 11; //15
	//static const int LLAVE1 = 16;
	//static const int LLAVE2 = 17;
	static const int IGUAL = 12; //18
	static const int POTENCIA = 13; //18
	//static const int IF = 19;
	//static const int WHILE = 20;
	//static const int RETURN = 21;
	//static const int ELSE = 22;
	//static const int PESOS = 23;
};

class lexerAritmetico {
private:
	string fuente;
	int ind;
	bool continua;
	char c;
	int estado;
	int cont;

	char sigCaracter();
	void sigEstado(int estado);
	void aceptacion(int estado);
	bool esLetra(char c);
	bool esDigito(char c);
	bool esEspacio(char c);
	void retroceso();

public:
	string simbolo;
	int tipo;
	string aux;

	lexerAritmetico(string fuente);
	lexerAritmetico();

	void entrada(string fuente);
	string tipoAcad(int tipo);

	int sigSimbolo();
	bool terminado();

};


#endif
