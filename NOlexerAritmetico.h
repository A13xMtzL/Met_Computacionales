//#pragma once
////#ifndef _LEXER
////#define _LEXER
//
//#include <iostream>
//#include <string>
//
//
//using namespace std;
//
//class TipoSimbolo {
//public:
//	// Creamos una lista de todos los posibles casos de tokens presentes en un documento
//	static const int Error = -1;
//	static const int Identificador = 0;
//	static const int Entero = 1;
//	static const int Real = 2;
//	static const int Cadena = 3;
//
//	static const int Suma = 4;
//	static const int Resta = 5; //------------FALTA IMPLEMENTAR--------------
//	static const int Multiplicacion = 6;
//	static const int Division = 7; //------------FALTA IMPLEMENTAR--------------
//
//	static const int Igualdad = 8;
//	static const int Parentesis_abre = 9;
//	static const int Parentesis_cierra = 10;
//	
//	static const int Igual = 11;
//	static const int Potencia = 12;
//	static const int Comentario = 13;
//
//	//-----------------------------------------------------------------------------------------------------------
//
//	// Palabras reservadas 
//	
//	//static const int IF = 16;
//	//static const int WHILE = 17;
//	//static const int RETURN = 18;
//	//static const int ELSE = 19;
//	//-----------------------------------------------------------------------------------------------------------
//};
//
//class lexerAritmetico {
//public:
//	string fuente;
//	int ind;
//	bool continua;
//	char sig_char;
//	int estado;
//	int cont;
//
//	bool EsLetra(char c);
//	bool EsDigito(char c);
//	bool Espacio(char c);
//
//	char Siguiente_Caracter();
//	void Siguiente_Estado(int estado);
//
//	void Aceptacion(int estado);
//
//	void retroceso();
//
////public:
//	string simbolo;
//	int tipo;
//	string aux;
//
//	lexerAritmetico(string fuente);
//	lexerAritmetico();
//
//	void entrada(string fuente);
//	string tipoAcad(int tipo);
//
//	int sigSimbolo();
//	bool terminado();
//
//};
//
//
////#endif
