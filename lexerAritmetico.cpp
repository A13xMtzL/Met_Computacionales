#include "lexerAritmetico.h"

lexerAritmetico::lexerAritmetico(string fuente){
	
	indice = 0;
	this->fuente = fuente;
}

lexerAritmetico::lexerAritmetico() {
	
	indice = 0; // Se inicializa el índice 
}
string lexerAritmetico::tipoAcad(int tipo){
	
	string cad = "";
	switch (tipo) // Inicio del switch case en donde se declaran los mensajes para
				 // monstrar en consola


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
void lexerAritmetico::entrada(string fuente){ // Recibe el string a leer
	
	indice = 0;
	this->fuente = fuente;
}
int lexerAritmetico::sigSimbolo(){
	
	estado = 0;
	continua = true;
	simbolo = "";
	//cont = 0;

	while (continua)
	{
		caracter = Siguiente_Caracter();

		switch (estado)
		{

		//	Aquí se empiezan a identificar los tipos de tokens

		case 0:
			if (Es_Letra(caracter)) {
				estado = 1;
				simbolo += caracter;
			}
			if (Es_Digito(caracter)) {
				estado = 2;
				simbolo += caracter;
			}
			//if (caracter == '+' || caracter == '-') {
			//	Aceptacion(5);
			//}
			//if (caracter == '*' || caracter == '/')Aceptacion(6);
			//if (caracter == '<' || caracter == '>') {
			//	estado = 5; // 5
			//	simbolo += caracter;
			//}



			//if (caracter == '|') {
			//	estado = 7; // 6
			//	simbolo += caracter;
			//}



			//if (caracter == '&') {
			//	estado = 7; // 7
			//	simbolo += caracter;
			//}
			//if (caracter == '!') {
			//	estado = 8; // 8
			//	simbolo += caracter;
			//}
			//if (caracter == ';')Aceptacion(12);
			//if (caracter == ',')Aceptacion(13);




			if (caracter == '+')Aceptacion(5);
			if (caracter == '-')Aceptacion(6);
			if (caracter == '*')Aceptacion(7);
			if (caracter == '/') Aceptacion(8);



			if (caracter == '(')Aceptacion(10);
			if (caracter == ')') Aceptacion(11);
			if (caracter == '^') Aceptacion(13);
			//if (caracter == '{') Aceptacion(16);
			//if (caracter == '}') Aceptacion(17);
			if (caracter == '=') {
				estado = 9; // este se queda 9
				simbolo += caracter;
			}
			//else {
			//	if (caracter == '$')Aceptacion(23);
			//}
			//if (caracter == "//") Aceptacion(13);

			break;
		case 1:
			if (Es_Letra(caracter) || Es_Digito(caracter)) {
				estado = 1;
				simbolo += caracter;

			}

			else {
				Aceptacion(0);
			}

			//else if (!Es_Letra(caracter) || !Es_Digito(caracter)) {
			//	**
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


			//	Case para identificar numeros reales 

		case 2:
			if (Es_Digito(caracter)) {
				estado = 2;
				simbolo += caracter;
			}
			else if (caracter == '.') {
				estado = 3;
				simbolo += caracter;
			}
			else if (caracter != '.' || !Es_Digito(caracter)) {
				Aceptacion(1);
			}
			break;


		case 3:
			if (Es_Digito(caracter)) {
				estado = 4;
				simbolo += caracter;
			}
			break;
		case 4:
			if (Es_Digito(caracter)) {
				estado = 4;
				simbolo += caracter;
			}
			else {
				Aceptacion(2);
			}
			break;
			//case 5:
			//	if (caracter != '=') {
			//		Aceptacion(7); // 7
			//	}
			//	else if (caracter == '=') {
			//		Aceptacion(7); // 7
			//	}
			//	break;



			//case 6:
			//	if (caracter != '|') {
			//		Aceptacion(23); // este no
			//	}
			//	else if (caracter == '|') {
			//		Aceptacion(8); // 8
			//	}
			//	break;




			//case 7:
			//	if (caracter != '&') {
			//		Aceptacion(23);
			//	}
			//	else if (caracter == '&') {
			//		Aceptacion(9);
			//	}
			//	break;


		case 8:
			//if (caracter != '=') {
			//	Aceptacion(10);
			//}
			//else if (caracter == '=') {
			//	Aceptacion(11);
			//}

			if (caracter == '=') {
				Aceptacion(9);
			}

			break;
		case 9:	//----------->	Si pasa algo feo, fue esto
			if (caracter != '=') {
				Aceptacion(12);
			}
			else if (caracter == '=') {
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
	case 14:
		tipo = TipoSimbolo::Comentario;
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
char lexerAritmetico::Siguiente_Caracter(){
	
	if (terminado()) return '$';  //  FIN DEL ARCHIVO

	return fuente[indice++];
}
void lexerAritmetico::Siguiente_Estado(int estado){
	
	this->estado = estado;
	if (estado != 0) {
		simbolo += caracter;
	}
}
void lexerAritmetico::Aceptacion(int estado){ // Estado en el que se encuentra el token
	
	Siguiente_Estado(estado);
	continua = false;
}
bool lexerAritmetico::terminado(){ // Verifica la medida del archivo
	
	return indice >= fuente.length();

}
bool lexerAritmetico::Es_Letra(char c){ // Identifica si el char actual es una letra
	
	return c >= 'a' && c <= 'z' || c == '_' || c >= 'A' && c <= 'Z';
}
bool lexerAritmetico::Es_Digito(char c){ // Identifica si se trata de un numero
	
	return isdigit(c);
}
bool lexerAritmetico::Es_Espacio(char c){ // Identifica si el char actual se	 trata de	
										// Un espacio en blanco
	return c == ' ' /*|| caracter == '\t'*/;
}
void lexerAritmetico::Retroceso(){
	
	if (caracter != '$') indice--;   //ACAJNSKAJSNAKJ FIN DEL ARCHIVO
	continua = false;
}
