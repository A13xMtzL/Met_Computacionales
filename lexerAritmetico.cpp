#include "lexerAritmetico.h"

lexerAritmetico::lexerAritmetico(string fuente)
{
	ind = 0;
	this->fuente = fuente;
}

lexerAritmetico::lexerAritmetico()
{
	ind = 0;
}
string lexerAritmetico::tipoAcad(int tipo)
{
	string cad = "";
	switch (tipo)
	{
	case TipoSimbolo::Identificador:
		cad = "VARIABLE";
		break;
	case TipoSimbolo::Entero:
		cad = "INTEGER";
		break;
	case TipoSimbolo::Real:
		cad = "REAL";
		break;
	case TipoSimbolo::Cadena:
		cad = "STRING";
		break;
	case TipoSimbolo::Tipo:
		cad = "Tipo de Dato";
		break;
	case TipoSimbolo::Suma:
		cad = "SUMA";
		break;

	case TipoSimbolo::Resta:
		cad = "SUBTRACTION";
		break;

		//case TipoSimbolo::Resta:
		//	cad = "Operador de Resta"; // este es nuevo, para reordenar 
		//	break;


	case TipoSimbolo::Op_Multiplicacion:
		cad = "MULTIPLICATION";
		break;

	case TipoSimbolo::Op_Division:
		cad = "DIVISION";// este es nuevo, para reordenar 
		break;

		//case TipoSimbolo::OPREL:
		//	cad = "Operador de Relacion";
		//	break;
		//case TipoSimbolo::OPOR:
		//	cad = "Operador OR";
		//	break;
		//case TipoSimbolo::OPAND:
		//	cad = "Operador AND";
		//	break;
		//case TipoSimbolo::OPNOT:
		//	cad = "Operador NOT";
		//	break;
	case TipoSimbolo::Op_Igualdad:
		cad = "ASSIGMENT";
		break;
		//case TipoSimbolo::PUNTO_COMA:
		//	cad = "Punto y Coma";
		//	break;
		//case TipoSimbolo::COMA:
		//	cad = "Coma";
		//	break;
	case TipoSimbolo::Parentesis_Abre:
		cad = "LEFT PARENTHESIS";
		break;
	case TipoSimbolo::Parentesis_Cierra:
		cad = "RIGHT PARENTHESIS";
		break;



		//case TipoSimbolo::LLAVE1:
		//	cad = "Llave";
		//	break;
		//case TipoSimbolo::LLAVE2:
		//	cad = "Llave";
		//	break;
	case TipoSimbolo::Igual:
		cad = "ASSIGMENT";
		break;


	case TipoSimbolo::Potencia:
		cad = "POWER";
		break;
		//case TipoSimbolo::IF:
		//	cad = "Palabra Reservada";
		//	break;
		//case TipoSimbolo::WHILE:
		//	cad = "Palabra Reservada";
		//	break;
		//case TipoSimbolo::RETURN:
		//	cad = "Palabra Reservada";
		//	break;
		//case TipoSimbolo::ELSE:
		//	cad = "Palabra Reservada";
		//	break;
		//case TipoSimbolo::PESOS:
		//	cad = "";
			//break;
	}

	return cad;
}
void lexerAritmetico::entrada(string fuente)
{
	ind = 0;
	this->fuente = fuente;
}
int lexerAritmetico::sigSimbolo()
{
	estado = 0;
	continua = true;
	simbolo = "";
	cont = 0;

	while (continua)
	{
		c = Siguiente_Caracter();

		switch (estado)
		{
		case 0:
			if (esLetra(c)) {
				estado = 1;
				simbolo += c;
			}
			if (esDigito(c)) {
				estado = 2;
				simbolo += c;
			}
			//if (c == '+' || c == '-') {
			//	Aceptacion(5);
			//}
			//if (c == '*' || c == '/')Aceptacion(6);
			//if (c == '<' || c == '>') {
			//	estado = 5; // 5
			//	simbolo += c;
			//}



			//if (c == '|') {
			//	estado = 7; // 6
			//	simbolo += c;
			//}



			//if (c == '&') {
			//	estado = 7; // 7
			//	simbolo += c;
			//}
			//if (c == '!') {
			//	estado = 8; // 8
			//	simbolo += c;
			//}
			//if (c == ';')Aceptacion(12);
			//if (c == ',')Aceptacion(13);
			if (c == '+')Aceptacion(5);
			if (c == '-')Aceptacion(6);
			if (c == '*')Aceptacion(7);
			if (c == '/') Aceptacion(8);



			if (c == '(')Aceptacion(10);
			if (c == ')') Aceptacion(11);
			if (c == '^') Aceptacion(13);
			//if (c == '{') Aceptacion(16);
			//if (c == '}') Aceptacion(17);
			if (c == '=') {
				estado = 9; // este se queda 9
				simbolo += c;
			}
			//else {
			//	if (c == '$')Aceptacion(23);
			//}
			break;
		case 1:
			if (esLetra(c) || esDigito(c)) {
				estado = 1;
				simbolo += c;

			}

			else {
				Aceptacion(0);
			}
			
			//else if (!esLetra(c) || !esDigito(c)) {
			//	aux = simbolo;
			//	if (aux == "int" || aux == "float" || aux == "void") {
			//		Aceptacion(4);
			//	}
			//	else {
			//		Aceptacion(0);
			//	}
			//	if (aux == "if") {
			//		Aceptacion(19);
			//	}
			//	if (aux == "while") {
			//		Aceptacion(20);
			//	}
			//	if (aux == "return") {
			//		Aceptacion(21);
			//	}
			//	if (aux == "else") {
			//		Aceptacion(22);
			//	}


			//}
			break;
		case 2:
			if (esDigito(c)) {
				estado = 2;
				simbolo += c;
			}
			else if (c == '.') {
				estado = 3;
				simbolo += c;
			}
			else if (c != '.' || !esDigito(c)) {
				Aceptacion(1);
			}
			break;
		case 3:
			if (esDigito(c)) {
				estado = 4;
				simbolo += c;
			}
			break;
		case 4:
			if (esDigito(c)) {
				estado = 4;
				simbolo += c;
			}
			else {
				Aceptacion(2);
			}
			break;
		//case 5:
		//	if (c != '=') {
		//		Aceptacion(7); // 7
		//	}
		//	else if (c == '=') {
		//		Aceptacion(7); // 7
		//	}
		//	break;



		//case 6:
		//	if (c != '|') {
		//		Aceptacion(23); // este no
		//	}
		//	else if (c == '|') {
		//		Aceptacion(8); // 8
		//	}
		//	break;




		//case 7:
		//	if (c != '&') {
		//		Aceptacion(23);
		//	}
		//	else if (c == '&') {
		//		Aceptacion(9);
		//	}
		//	break;


		case 8:
			//if (c != '=') {
			//	Aceptacion(10);
			//}
			//else if (c == '=') {
			//	Aceptacion(11);
			//}

			if (c == '=') {
				Aceptacion(9);
			}

			break;
		case 9:	//----------->	Si pasa algo feo, fue esto
			if (c != '=') {
				Aceptacion(12);		
			}
			else if (c == '=') {
				Aceptacion(9);
			}
			break;
		}
	}
	switch (estado)
	{
	case -1:
		tipo = TipoSimbolo::Error;
		break;
	case 0:
		tipo = TipoSimbolo::Identificador;
		break;
	case 1:
		tipo = TipoSimbolo::Entero;
		break;
	case 2:
		tipo = TipoSimbolo::Real;
		break;
	case 3:
		tipo = TipoSimbolo::Cadena;
		break;
	case 4:
		tipo = TipoSimbolo::Tipo;
		break;
	case 5:
		tipo = TipoSimbolo::Suma;
		break;

	case 6:
		tipo = TipoSimbolo::Resta;
		break;
	case 7:
		tipo = TipoSimbolo::Op_Multiplicacion;
		break;

	case 8:
		tipo = TipoSimbolo::Op_Division;
		break;
		//case 7:
		//	tipo = TipoSimbolo::OPREL;
		//	break;
		//case 8:
		//	tipo = TipoSimbolo::OPOR;
		//	break;
		//case 9:
		//	tipo = TipoSimbolo::OPAND;
		//	break;
		//case 10:
		//	tipo = TipoSimbolo::OPNOT;
		//	break;
	case 9:
		tipo = TipoSimbolo::Op_Igualdad;
		break;
		//case 12:
		//	tipo = TipoSimbolo::PUNTO_COMA;
		//	break;
		//case 13:
		//	tipo = TipoSimbolo::COMA;
		//	break;
	case 10:
		tipo = TipoSimbolo::Parentesis_Abre;
		break;
	case 11:
		tipo = TipoSimbolo::Parentesis_Cierra;
		break;
		//case 16:
		//	tipo = TipoSimbolo::LLAVE1;
		//	break;
		//case 17:
		//	tipo = TipoSimbolo::LLAVE2;
		//	break;
	case 12:
		tipo = TipoSimbolo::Igual;
		break;

	case 13:
		tipo = TipoSimbolo::Potencia;
		break;
		//case 19:
		//	tipo = TipoSimbolo::IF;
		//	break;
		//case 20:
		//	tipo = TipoSimbolo::WHILE;
		//	break;
		//case 21:
		//	tipo = TipoSimbolo::RETURN;
		//	break;
		//case 22:
		//	tipo = TipoSimbolo::ELSE;
		//	break;
		//case 23:
		//	tipo = TipoSimbolo::PESOS;
		//	break;
	default:
		tipo = TipoSimbolo::Error;
		break;
	}
	return tipo;
}
char lexerAritmetico::Siguiente_Caracter()
{
	if (terminado()) return '$';  //ACAJNSKAJSNAKJ FIN DEL ARCHIVO

	return fuente[ind++];
}
void lexerAritmetico::Siguiente_Estado(int estado)
{
	this->estado = estado;
	if (estado != 0) {
		simbolo += c;
	}
}
void lexerAritmetico::Aceptacion(int estado)
{
	Siguiente_Estado(estado);
	continua = false;
}
bool lexerAritmetico::terminado()
{
	return ind >= fuente.length();

}
bool lexerAritmetico::esLetra(char c)
{
	return c >= 'a' && c <= 'z' || c == '_' || c >= 'A' && c <= 'Z';
}
bool lexerAritmetico::esDigito(char c)
{
	return isdigit(c);

}
bool lexerAritmetico::esEspacio(char c)
{
	return c == ' ' || c == '\t';
}
void lexerAritmetico::Retroceso()
{
	if (c != '$') ind--;   //ACAJNSKAJSNAKJ FIN DEL ARCHIVO
	continua = false;
}
