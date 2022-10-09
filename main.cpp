//Programa que: Implementa la estructura Tries y algoritmos DFS. 
//Programadores: León Emiliano García Pérez [A00573074] y Carla Morales López [A01639225].
//Fecha de entrega: Sábado 08 de Octubre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <string>
#include <vector>

//Ajuste a estandar.
using namespace std;

//Función que imprime un espacio en consola, no recibe valores, no tiene valor de retorno.
void espacio() {  //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función. 
	cout << endl;
}

//Definición de la Clase Nodo, la cual se constitiye de un arreglo de Nodos y un booleano que determina si es un nodo final de palabra.
class Nodo {
	public:
		//Atributos de la Clase
		Nodo* hijos[26];
		bool esPalabra; //Si es lo último perteneciente a la palabra exacta, o en otras palabras: un nodo hoja.

		//Constructor de la Clase Nodo
		Nodo() { //Complejidad Computacional: O(26) [Considerada O(1), por ser constante], es una ejecución lineal del contenido de la función. 
			esPalabra = false;
			for (int i = 0; i < 26; i++) {
				hijos[i] = NULL;
			}
		}
};

//Definición de la Clase Trie, la cual se constitiye de un apuntador a un Nodo.
class Trie {
	public:
		//Atributos de la Clase
		Nodo* raiz;

		//Constructor de la Clase Trie
		Trie() { //Complejidad Computacional: O(1), es una ejecución lineal del contenido de la función. 
			raiz = new Nodo();
		}

		//Función que permita insertar una palabra a la estructura del Trie, recibe un string como parámetro, y no tiene valor de retorno.
		void insertar(string palabra) { //Complejidad Computacional: O(n), siendo n el tamaño de la palabra a ingresar.
			Nodo* actual = raiz;

			for (int i = 0; i < palabra.size(); i++) {
				int index = palabra[i] - 'a';
				if (actual->hijos[index] == NULL) {
					actual->hijos[index] = new Nodo();
				}
				actual = actual->hijos[index];
			}
			actual->esPalabra = true;
		}

		//Función que permita buscar una palabra en la estructura Trie, recibe el string a buscar, imprime el recorrido a lo largo del mismo y retorna un booleano respecto a si se encuentra la palabra o no. 
		bool busqueda(string palabra) { //Complejidad Computacional: O(n), siendo n el tamaño de la palabra a ingresar.
			Nodo* actual = raiz;

			for (int i = 0; i < palabra.size(); i++) {
				int index = palabra[i] - 'a';

				if (actual->hijos[index] == NULL) {
					espacio();
					return false;
				}
				cout << palabra[i];
				if (i != palabra.size() - 1 &&
					actual->hijos[index]->hijos[palabra[i + 1] - 'a'] != NULL) {
					cout << "->";
				}
				actual = actual->hijos[index];
			}

			espacio();
			return actual->esPalabra;
		}

		//Función que implementa el DFS sobre el Trie, imprime un recorrido sobre el Trie por cada caracter, recibe un apuntador a un Nodo, y no tiene valor de retorno. 
		void dfs(Nodo* actual) { //Complejidad Computacional: O(26) [Considerada O(1), por ser constante], es una ejecución lineal del contenido de la función. 
			for (int i = 0; i < 26; i++) {
				if (actual->hijos[i] != NULL) {
					cout << (char)(i + 'a') << endl;
					cout << "↓" << endl;
					dfs(actual->hijos[i]);
				}
			}
		}

		//Función que implementa el DFS sobre el Trie, imprime las palabras en orden de recorrido, recibe un apuntador a un nodo, un string y no tiene valor de retorno. 
		void recorridoDFSPorPalabras(Nodo* actual, string palabra) { //Complejidad Computacional: O(26) [Considerada O(1), por ser constante], es una ejecución lineal del contenido de la función. 
			if (actual == NULL)
				return;

			if (actual->esPalabra)
				cout << palabra << endl;

			for (int i = 0; i < 26; i++) {
				if (actual->hijos[i]) {
					palabra.push_back(((char)(i + 'a')));
					recorridoDFSPorPalabras(actual->hijos[i], palabra);
					palabra.pop_back();
				}
			}
		}
};

//Función main de ejecución del programa, no recibe valores, retorna un valor 0 al finalizar la ejecución.
int main() {//Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función. 

	cout << "---------- INICIA PROGRAMA ----------" << endl;
	int n; //Cantidad de palabras a ingresar en el Trie
	int m; //Cantidad de palabras a buscar dentro del Trie
	Trie trie; //Declaración del Trie

	espacio();
	cout << "INGRESE LA CANTIDAD PALABRAS A INSERTAR EN EL TRIE: " << endl;
	cin >> n; //Ingresa la cantidad de palabras a introducir en el Trie
	espacio();

  cout << "INTRODUZCA LAS PALABRAS: " << endl;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp; //Escribe las palabras
		trie.insertar(temp); //Se inserta en el Trie
	}

	espacio();
	cout << "RECORRIDO DFS SOBRE EL TRIE [POR PALABRAS]: " << endl;
	trie.recorridoDFSPorPalabras(trie.raiz, ""); //Se hace el recorrido del Trie por palabras

	espacio();
	cout << "RECORRIDO DFS SOBRE EL TRIE [POR CARACTERES]: " << endl;
	cout << "RAIZ" << endl;
	cout << "↓" << endl;
	trie.dfs(trie.raiz); //Se hace el recorrido del Trie por caracteres
	cout << "FIN" << endl;
	espacio();

	cout << "INGRESE LA CANTIDAD PALABRAS A BUSCAR EN EL TRIE: " << endl;
	cin >> m; //Ingresa la cantidad de palabras a buscar en el Trie
	espacio();

  cout << "INTRODUZCA LAS PALABRAS: " << endl;
	for (int j = 0; j < m; j++) {
		string temp;
		cin >> temp; //Escribe las palabras

		cout << (trie.busqueda(temp) ? "TRUE" : "FALSE") << endl; //Se realiza la búsqueda de la palabra precisa en el Trie
		espacio();
	}

	cout << "---------- TERMINA PROGRAMA ----------" << endl;
	return 0;
}