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
	static const int Op_Igualdad = 9; // 11
	//static const int PUNTO_COMA = 12;
	//static const int COMA = 13;
	static const int Parentesis_Abre = 10; // 14
	static const int Parentesis_Cierra = 11; //15
	//static const int LLAVE1 = 16;
	//static const int LLAVE2 = 17;
	static const int Igual = 12; //18
	static const int Potencia = 13; //18
	static const int Comentario = 14; //18




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

	bool esLetra(char c);
	bool esDigito(char c);
	bool esEspacio(char c);
	
	char Siguiente_Caracter();
	void Siguiente_Estado(int estado);
	
	void Aceptacion(int estado);
	void Retroceso();

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
