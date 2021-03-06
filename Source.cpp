#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <math.h>
#include <limits>
#include <string>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <list>
#include <unordered_map>
#include <stack>

typedef char Variable;
typedef int  Entero;
using namespace std;

class AYED2019 {
private:
	typedef char Nombre;
	typedef int Valor;
    unordered_map <Nombre, Valor> Entorno;
	unordered_map <char, int>::iterator iterador_mapa, iterador_aux ;
	list<string> Script;
	list<string>::iterator linea_actual;
	bool ok = true;
	bool condicionchequeada;
	bool isnum(string valor);
	bool condicionIfElse(char h, int o1, int o2);
	
public:
	AYED2019() {
	};
	int error = 0;
	int total = 0;
	bool readFile();
	bool ArePair(char opening, char closing);
	bool areParanthesisBalanced(string expr);
	bool operaciones(list<string> Original);
	bool isnumS(char valor);
	int calcular(int o1, int o2, char aux);
};

bool AYED2019::isnumS(char valor) {
	if(!isalpha(valor) && isalnum(valor)) {
		return true;
	}
	else {
		return false;
	 }
}

bool AYED2019::isnum(string valor) {
	if (isdigit(atoi(valor.c_str())))
		return true;
	return false;
}
bool AYED2019::readFile() {
	iterador_mapa = Entorno.begin();
	string fichero = "trabajo1.txt";
	ifstream inputFile;
	inputFile.open(fichero.c_str());
	string word;
	if (!inputFile) {
		cerr << "Open Faiulre" << endl;
		exit(1);
		return false;
	}
	while (getline(inputFile, word)) {
		linea_actual = Script.begin();
		Script.push_back(word);
		linea_actual ++;
	}
	for (linea_actual = Script.begin(); linea_actual != Script.end(); linea_actual++) {
		string& cadena = *linea_actual;
		if (areParanthesisBalanced(cadena)) {
			
		}
		else {
			
		}
	}

	if (ok == true) {
		operaciones(Script);
	}
	else {
		cout << "Revise la sintaxis.";
		cout << "Recuerde que por cada linea solo puede haber una operacion, siempre entre parentesis y separada por espacios, una linea nueva es marcada tras cada salto de linea." << endl;
	}
	
}

// function to check if paranthesis are balanced
bool AYED2019:: ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}

bool AYED2019::areParanthesisBalanced(string expr){
	stack<char> s;
	char x;
	// Traversing the Expression 
	for (int i = 0; i < expr.length(); i++){
		if (expr.at(i) == '(')
			s.push('(');
		else if (expr.at(i) == ')')
			if (s.empty())
				ok = false;
			else
				s.pop();
	}
	if (!s.empty())		//Si la pila no es vacia significa que quedo un parentesis sin cerrar y por ende la expresion estaba mal.
		ok = false;
	return ok;					//Si la pila es vacia retorna la variable "correcto" que sera false o true dependiendo de que sucedio en el ciclo for.
}


bool AYED2019::operaciones(list<string> Original) {
	bool cond;
	int aux1 = 0, aux2 = 0, o2 = 0, o1 = 0, tempA = 0, tempB = 0;
	char auxiliar;
	int d = 0;
	char h, k, operacion;
	for (linea_actual = Script.begin(); linea_actual != Script.end(); linea_actual++) {
		string& cadena = *linea_actual;
		if (cadena.find("INT") == 0) {
			Entorno[cadena.at(4)];
		}
		//}

	//for (linea_actual = Script.begin(); linea_actual != Script.end(); linea_actual++) {
			//string& cadena = *linea_actual;
		if (cadena.at(2) == '=') {
			for (iterador_mapa = Entorno.begin(); iterador_mapa != Entorno.end(); iterador_mapa++) {
				//cout << "int: " << iterador_mapa->first << " " << "value: " << iterador_mapa->second;
				if (Entorno.find(cadena.at(0)) != Entorno.end() && isnumS(cadena.at(4))) {
					Entorno[cadena.at(0)] = atoi(&cadena.at(4));
				}
			}
		}
		//}

		//for (linea_actual = Script.begin(); linea_actual != Script.end(); linea_actual++) {
		iterador_mapa = Entorno.begin();
		//string& cadena = *linea_actual;
			if (cadena.size() > 8) {
			if (cadena.at(2) == '=' && cadena.length() < 14) {
				if (cadena.at(4) == '(') {
					if (Entorno.find(cadena.at(6)) != Entorno.end()) {
						auxiliar = iterador_mapa->first;
						tempA = Entorno[cadena.at(6)];
					}
					iterador_mapa++;
					if (isnumS(cadena.at(10))) {
						tempB = atoi(&cadena.at(10));
					}
					else {
						tempB = Entorno[cadena.at(10)];
					}
					operacion = cadena.at(8);
				}
				else {
					if (Entorno.find(cadena.at(4)) != Entorno.end()) {
						auxiliar = iterador_mapa->first;
						tempA = Entorno[cadena.at(4)];
					}
					iterador_mapa++;
					if (isnumS(cadena.at(8))) {
						tempB = atoi(&cadena.at(8));
					}
					else {
						tempB = Entorno[cadena.at(8)];
					}
					operacion = cadena.at(6);
				}
				calcular(tempA, tempB, operacion);
				Entorno[cadena.at(0)] = calcular(tempA, tempB, operacion);
			}
		}
		//	}

			//for (linea_actual = Script.begin(); linea_actual != Script.end(); linea_actual++) {
		iterador_mapa = Entorno.begin();
		//string& cadena = *linea_actual;
		if (cadena.at(0) == 'I' && cadena.at(1) == 'F') {
			size_t pos1 = cadena.find("IF");
			string str1 = cadena.substr(pos1);
			for (iterador_mapa = Entorno.begin(); iterador_mapa != Entorno.end(); iterador_mapa++) {
				if (Entorno.find(cadena.at(5)) != Entorno.end()) {
					o1 = Entorno[cadena.at(5)];
					//	cout << "El valor de o1 es: " << o1 << endl;
					aux1 = 1;
					iterador_mapa++;
					if (Entorno.find(cadena.at(9)) != Entorno.end()) {
						o2 = Entorno[cadena.at(9)];
						//		cout << "El valor de o2 es: " << o2 << endl;
						aux2 = 1;
					}
					else {
						o2 = atoi(&str1.at(9));
						//		cout << "El valor de o2 es: " << o2 << endl;
						aux2 = 1;
					}
					if (aux1 == 1 && aux2 == 1) {
						h = str1.at(7);
						condicionIfElse(h, o1, o2);
						break;
					}
				}
			}
			if (condicionchequeada) {
				if (size_t pos = cadena.find("THEN")) {
					string str3 = cadena.substr(pos);
					iterador_mapa = Entorno.begin();
					if (str3.find("SHOW")) {
						if (Entorno.find(cadena.at(23)) != Entorno.end()) {
								cout << "Showing: " << Entorno[cadena.at(23)] << endl;
								break;
						}
					}
					if (str3.find("JUMP")) {
						if (isnumS(cadena.at(23))) {
							int numeropos = (atoi(&str3.at(23)));
							linea_actual = Script.begin();
							for (int i = 0; i < numeropos -1 ; i++) {
								linea_actual++;
							}

						}
					}
				}
			}
		}
		//}
		//for (linea_actual = Script.begin(); linea_actual != Script.end(); linea_actual++) {
			//iterador_mapa = Entorno.begin();
		//	string& cadena = *linea_actual;
		if (cadena.at(0) == 'S' && cadena.at(1) == 'H' && cadena.at(2) == 'O' && cadena.at(3) == 'W') {
			if ((iterador_mapa = Entorno.find(cadena.at(5))) != Entorno.end()) {
				cout << "Showing: " << Entorno[cadena.at(5)] << endl;;
			}
		}

		if (cadena.at(0) == 'J' && cadena.at(1) == 'U' && cadena.at(2) == 'M' && cadena.at(3) == 'P') {
			if (total == 0) {
				continue;
			}
			else {
				if (isnumS(cadena.at(5))) {
					d = (atoi(&cadena.at(5)));
					linea_actual = Script.begin();
					for (int i = 0; i < d - 2; i++) {
						linea_actual++;
					}
				}
			}
		}

		if (cadena.at(0) == 'E' && cadena.at(1) == 'N' && cadena.at(2) == 'D') {
			for (iterador_mapa = Entorno.begin(); iterador_mapa != Entorno.end(); iterador_mapa++) {
				cout << " " << iterador_mapa->first << " : " << iterador_mapa->second << endl;
			}
		}
	}
}

bool AYED2019::condicionIfElse(char aux,int o1, int o2) {
	switch (aux) {
		case '=': if (o1 == o2) {
			condicionchequeada = true;
			//cout << "Cierto.";
		}
				  else {
			condicionchequeada = false;
			//cout << "Falso.";
		}
				  break;

		case '>': if (o1 > o2) {
			condicionchequeada = true;
			//cout << "Cierto.";
		}
				  else {
			condicionchequeada = false;
			//cout << "Falso.";
		}
				  break;

		case '<': if (o1 < o2) {
			condicionchequeada = true;
			//cout << "Cierto.";
		}
				  else {
			condicionchequeada = false;
			//cout << "Falso.";
		}
				  break;

		default: if (o1 != o2) {
			condicionchequeada = true;
		}
				 else {
			condicionchequeada = false;
		}
				 break;
	}
	return condicionchequeada;
}

int AYED2019::calcular(int o1, int o2, char aux) {
	switch (aux) {
		case '+': {
			total = o1 + o2;
		}
				  break;
		case '-' : {
			total = o1 - o2;
		}
				   break;
		case '*': {
			total = o1 * o2;
		}
				  break;
		case '/': {
			if (o2 == 0) {
				cout << "Division por 0 no posible.";
			}
			else {
				total = o1 / o2;
			}
		}
	}
	//cout << "Total: " << total << endl;
	return total;
}

int main() {
	AYED2019 lista;
	
	if (lista.readFile()) {
		cout << "Success" << endl;
	}
	else {
		cout << "Failure" << endl;
	}
	return 0;
}
