#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class Nodo {
public:
	Nodo *hijos[27];
	bool hoja;
	char letra;

	Nodo() {
		hoja = false;
		letra = '\0';

		for (int i = 0; i < 27; i++) {
			hijos[i] = NULL;
		}
	}
};

class Trie {
public:
	Nodo raiz;

	void insertar(string palabra) {
		Nodo *actual = &raiz;

		for (int j = 0; j < palabra.size(); j++) {
			if (actual->hijos[palabra.at(j) - 'A'] == NULL) {
				actual->hijos[palabra.at(j) - 'A'] = new Nodo;
				actual->hijos[palabra.at(j) - 'A']->letra = palabra.at(j);
			}
			actual = actual->hijos[palabra.at(j) - 'A'];
		}
		actual->hoja = true;
	}

	Nodo *buscar(string palabra) {
		Nodo *actual = &raiz;

		for (int k = 0; k < palabra.size(); k++) {
			if (actual->hijos[palabra.at(k) - 'A']) {
				actual = actual->hijos[palabra.at(k) - 'A'];
			} else {
				actual = NULL;
				return actual;
			}
		}
		return actual;
	}

	void palabrasCon(Nodo *actual, string prefijo, string sufijo) {
		if (actual->hoja && sufijo.size() != 0) {
			cout << prefijo + sufijo << endl;
		}
		for (int l = 0; l < 27; l++) {
			string temporal = sufijo;
			if (actual->hijos[l]) {
				temporal += actual->hijos[l]->letra;
				palabrasCon(actual->hijos[l], prefijo, temporal);
			}
		}
	}
};

void espacio() {
	cout << endl;
}

int main() {
	Trie trie;

	trie.insertar("HELLO");
	trie.insertar("HI");
	trie.insertar("TEABAG");
	trie.insertar("TEACAN");

	Nodo *actual = trie.buscar("");
	trie.palabrasCon(actual, "", "");

	return 0;
}
