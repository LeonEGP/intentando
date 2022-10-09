#include <iostream>
#include <string>
#include <vector>

using namespace std;

void espacio() {
	cout << endl;
}

class Nodo {
public:
	Nodo *hijos[26];
	bool esPalabra;

	Nodo() {
		esPalabra = false;
		for (int i = 0; i < 26; i++) {
			hijos[i] = NULL;
		}
	}
};

class Trie {
public:

  Nodo *raiz;

	Trie() {
		raiz = new Nodo();
	}

	void insertar(string palabra) {
		Nodo *actual = raiz;

		for (int i = 0; i < palabra.size(); i++) {
			int index = palabra[i] - 'a';
			if (actual->hijos[index] == NULL) {
				  actual->hijos[index] = new Nodo();
			  }
			  actual = actual->hijos[index];
		}
		actual->esPalabra = true;
	}

	bool busqueda(string palabra) {
		Nodo *actual = raiz;

		for (int i = 0; i < palabra.size(); i++) {
			int index = palabra[i] - 'a';
      
			if (actual->hijos[index] == NULL) {
        espacio();
				return false;
			}
      // Aquí
      cout << palabra[i];
      if (i != palabra.size()-1 && actual->hijos[index]->hijos[palabra[i+1] - 'a'] != NULL){
        cout << "->";
      }
			actual = actual->hijos[index];
		}
    espacio();
		return actual->esPalabra;
	}

  void dfs(Nodo *actual){

    for(int i = 0; i < 26; i++){
      if (actual->hijos[i] != NULL){
        cout << (char) (i + 'a') << endl;
        
        cout << "↓" << endl;
        dfs(actual->hijos[i]);
      }
    }
    
  }

};


int main() {
	int n; // Cantidad de palabras al Trie
	Trie trie;
	cin >> n;
  espacio();

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		trie.insertar(temp);
	}

  espacio();
  cout << "raiz" << endl;
  cout << "↓" << endl;
  trie.dfs(trie.raiz);
  cout << "fin" << endl;
  espacio();

	int m; // Cantidad de palabras de busqueda
	cin >> m;
  espacio();

	for (int j = 0; j < m; j++) {
		string temp;
		cin >> temp;

		cout << trie.busqueda(temp) << endl;
		// Buscar con DFS al Trie
    espacio();
	}

	return 0;
}