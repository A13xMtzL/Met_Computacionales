//	Analizador_Lexico.cpp: Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
//	Codigo trabajado por: Alejandro Martínez Luna       - A01276785
//						  Monserrat Karime Moreno Casas - A01276775
#include <iostream>
#include <string>
#include <cstdlib>

#include <sstream>
#include <fstream>

#include "lexerAritmetico.h"
using namespace std;
int main() {

	//	//---------------------------------------------------------------------------
	//
	//	// Apertura del archivo y lectura de los elementos
	//	//Otro comentario feo 
	//
	//
	//	ifstream archivo("input1.txt");
	//	//archivo.open("input1.txt", ios::in);
	//
	//	string texto, temporal;
	//
	//	if (!archivo.fail()) {
	//		while (!archivo.eof()) {
	//			getline(archivo, temporal);
	//			texto += temporal + "\n";
	//
	//			archivo.close();
	//		}
	//	}
	//
	//	//---------------------------------------------------------------------------
	//
	//	lexerAritmetico* analizador_lexico = new lexerAritmetico(); // Se hace la creacion del objeto lexer, que nos permitirá 
	//																// identificar los tokens del archivo
	//
	//	string palabras = ("b = 7"
	//
	//		"a = 32.4 * (-8.6 - b) / 6.1E-8  "
	//
	//		"d = a ^ b int x // Esto es un comentario WHILE");
	//
	//
	//
	//	analizador_lexico->entrada(palabras); //AQUI SE DEBERÍA DE ABRIR EL ARCHIVO
	//
	//
	//	cout << "\tToken\t\t|Type" << endl;
	//	cout << "-------------------------------------------------------------" << endl;
	//
	//	while (analizador_lexico->simbolo.compare("$") != 0)
	//	{
	//		analizador_lexico->sigSimbolo();
	//
	//		cout << "\t" << analizador_lexico->simbolo << "\t\t" << "|" << analizador_lexico->tipoAcad(analizador_lexico->tipo) << endl;
	//		cout << "-------------------------------------------------------------" << endl;
	//	}
	//	cin.get();
	//
	//	return 0;
	//
	//}
	//
	//



	//------------------------------------------------ 
	// Se abre el archivo y se guarda el contenido en una variable

	ifstream archivo("input2.txt");
	string texto = "", temporal = "";

	if (!archivo.fail()) {
		while (!archivo.eof()) {
			getline(archivo, temporal);
			texto += temporal + "\n";
		}
		archivo.close();
	}

	//------------------------------------------------ 

	lexerAritmetico* lexer = new lexerAritmetico(); // Se realiza la creación de un objeto 
													// para poder usar las funciones del analizador

	/*string palabras = ("b = 7"

		"a = 32.4 * (-8.6 - b) / 6.1E-8   "

		"d = a ^ b int x // Esto es un comentario WHILE");

	string prueba1 = "8 3.5 4.8 = - + ( b = 100 / 10 ) *  ^ ";*/

	lexer->entrada(texto); // Pasamos como parámetro el contenido del archivo almacenado en una variable


	cout << "\tToken\t\t|Type\n";
	cout << "-------------------------------------------------------------" << endl;

	while (lexer->simbolo.compare("$") != 0) {

		lexer->sigSimbolo();

		cout << "\t" << lexer->simbolo << "\t\t" << "|" << lexer->tipoAcad(lexer->tipo) << "\n";
		//cout << "-------------------------------------------------------------\n";
	}
	system("pause");

	return 0;

}

