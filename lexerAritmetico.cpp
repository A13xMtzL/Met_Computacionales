#include "lexerAritmetico.h"

//	Constructores:
lexerAritmetico::lexerAritmetico() {

	//ind = 0;
}

lexerAritmetico::lexerAritmetico(string fuente) {

	ind = 0;
	this->fuente = fuente;
}


string lexerAritmetico::tipoAcad(int tipo) {

	string cad = "";
	switch (tipo) {

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
		cad = "Cadena";
		break;
	case TipoSimbolo::Suma:
		cad = "SUMA";
		break;
	case TipoSimbolo::Resta:
		cad = "RESTA";
		break;
	case TipoSimbolo::Multiplicacion:
		cad = "MULTIPLICATION";
		break;
	case TipoSimbolo::Igualdad:
		cad = "ASSIGMENT";
		break;

	case TipoSimbolo::Parentesis_abre:
		cad = "LEFT PARENTHESIS ";
		break;
	case TipoSimbolo::Parentesis_cierra:
		cad = "RIGHT PARENTHESIS  ";
		break;

	case TipoSimbolo::Comentario:
		cad = "COMENTARIO";
		break;

	case TipoSimbolo::Igual:
		cad = "ASSIGMENT";
		break;
		//case TipoSimbolo::IF:
		//	cad = "RESERVED WORD";
		//	break;
		//case TipoSimbolo::WHILE:
		//	cad = "RESERVED WORD";
		//	break;
		//case TipoSimbolo::RETURN:
		//	cad = "RESERVED WORD";
		//	break;
		//case TipoSimbolo::ELSE:
		//	cad = "RESERVED WORD";
		//	break;


	case TipoSimbolo::Potencia:
		cad = "POWER";
		break;
	}
	return cad;


}
void lexerAritmetico::entrada(string fuente) {

	//ind = 0;
	this->fuente = fuente;
}
int lexerAritmetico::sigSimbolo() {

	estado = 0;
	continua = true;
	simbolo = "";
	cont = 0;

	while (continua)
	{
		sig_char = Siguiente_Caracter();

		switch (estado)
		{
		case 0:
			if (EsLetra(sig_char)) {
				estado = 1;
				simbolo += sig_char;
			}
			if (EsDigito(sig_char)) {
				estado = 2;
				simbolo += sig_char;
			}

			if (sig_char == '+')Aceptacion(4);
			if (sig_char == '-')Aceptacion(5);
			if (sig_char == '*') Aceptacion(6);
			if (sig_char == '(')Aceptacion(9);
			if (sig_char == ')') Aceptacion(10);
			if (sig_char == '^') Aceptacion(12);
			if (sig_char == '=') {
				estado = 8;
				simbolo += sig_char;
			}
			else {
				if (sig_char == '$')Aceptacion(23);
			}
			break;
		case 1:
			if (EsLetra(sig_char) || EsDigito(sig_char)) {
				estado = 1;
				simbolo += sig_char;

			}
			else if (!EsLetra(sig_char) || !EsDigito(sig_char)) {
				aux = simbolo;

				if (aux == "//") {
					simbolo += sig_char;
					Aceptacion(13);

				}

				//if (aux == "int" || aux == "float" || aux == "void") {
				//	Aceptacion(4);
				//}
				//else {
				//	Aceptacion(0);
				//}
				//if (aux == "if") {
				//	Aceptacion(19);
				//}
				//if (aux == "while") {
				//	Aceptacion(20);
				//}
				//if (aux == "return") {
				//	Aceptacion(21);
				//}
				//if (aux == "else") {
				//	Aceptacion(22);
				//}
			}
			break;

		case 2:
			if (EsDigito(sig_char)) {
				estado = 2;
				simbolo += sig_char;
			}
			else if (sig_char == '.') {
				estado = 3;
				simbolo += sig_char;
			}

			else if (sig_char != '.' || !EsDigito(sig_char)) {
				Aceptacion(1);
			}


			break;
			case 3:
				if (EsDigito(c)) {
					estado = 4;
					simbolo += c;
				}
				break;
		case 3:
			if (EsDigito(sig_char)) {
				estado = 4;
				simbolo += sig_char;
			}
			else {
				Aceptacion(2);
			}
			break;

		case 4:
			if (sig_char != '=') {
				Aceptacion(8);
			}
			else if (sig_char == '=') {
				Aceptacion(10);
			}
			break;

		case 5:
			if (sig_char == '/') {
				simbolo += sig_char;
				if (sig_char == '/') {
					Aceptacion(15);
				}
				else {
					Aceptacion(8);
				}
			}
			else if (sig_char == '=') { //OJO ACA
				Aceptacion(10);
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
		tipo = TipoSimbolo::Suma;
		break;
	case 5:
		tipo = TipoSimbolo::Resta;
		break;
	case 6:
		tipo = TipoSimbolo::Multiplicacion;
		break;
	case 7:
		tipo = TipoSimbolo::Division;
		break;

	case 8:
		tipo = TipoSimbolo::Igualdad;
		break;
	case 9:
		tipo = TipoSimbolo::Parentesis_abre;
		break;
	case 10:
		tipo = TipoSimbolo::Parentesis_cierra;
		break;
	case 11:
		tipo = TipoSimbolo::Igual;
		break;
	case 12:
		tipo = TipoSimbolo::Potencia;
		break;
	case 13:
		tipo = TipoSimbolo::Comentario;
		break;
	default:
		tipo = TipoSimbolo::Error;
		break;

	}
	return tipo;
}
char lexerAritmetico::Siguiente_Caracter()
{
	if (terminado()) return '$';

	return fuente[ind++];
}
void lexerAritmetico::Siguiente_Estado(int estado)
{
	this->estado = estado;
	if (estado != 0) {
		simbolo += sig_char;
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
bool lexerAritmetico::EsLetra(char c)
{
	return c >= 'a' && c <= 'z' || c == '_' || c >= 'A' && c <= 'Z';
}
bool lexerAritmetico::EsDigito(char c)
{
	return isdigit(c);

}
bool lexerAritmetico::Espacio(char c)
{
	return c == ' ' || c == '\t';
}
void lexerAritmetico::retroceso()
{
	if (sig_char != '$') ind--;
	continua = false;
}