#include <iostream>
#include <algorithm>
#include <vector>


#define pb push_back
#define ini -1
using namespace std;

// accepted
class Aresta{
private:
	int vertice1;
	int vertice2;
	int peso;
public:
	Aresta(int vert1, int vert2, int pe){
		vertice1 = vert1;
		vertice2 = vert2;
		peso = pe;
	}

	int getVertice1(){
		return vertice1;
	}

	int getVertice2(){
		return vertice2;
	}

	int getPeso(){
		return peso;
	}

	// sobrecarga de operador para ordenar em ordem crescente de pesos no sort
	bool operator <(const Aresta& aresta) const{
		return peso < aresta.peso;
	}
};

class Grafo{
private:
	int vertices;
	vector<Aresta> arestas;
public:
	Grafo(int vert){
		vertices = vert;
	}

	void addAresta(int vert1, int vert2, int peso){
		Aresta aresta(vert1, vert2, peso);

		// no plural eh o vetor de aresta
		arestas.pb(aresta);
	}

	int buscar(int subset[], int i){
		if(subset[i] == ini)
			return i;
		return buscar(subset, subset[i]);
	}

	void unir(int subset[], int vert1, int vert2){
		subset[vert1] = vert2;
	}

	int kruskal(){
		// vector<Aresta> arvore;  // nao vai precisar dela, ja calcula logo
		int tamAresta = arestas.size();
		int soma = 0;

		sort(arestas.begin(), arestas.end());

		// sub conjunto de tamanho igual ao num de vertices
		int *subset = new int[vertices];

		fill(subset, subset + vertices, ini);

		for(int i = 0; i < tamAresta; i++){
			int v1 = buscar(subset, arestas[i].getVertice1());
			int v2 = buscar(subset, arestas[i].getVertice2());

			if(v1 != v2){
				soma = soma + arestas[i].getPeso();
				unir(subset, v1, v2);
			}
		}

		return soma;
	}
};


int main(){
	int vert, arestas, v1, v2, custo;

	while(cin >> vert >> arestas){
		if(vert == 0 && arestas == 0)
			break;

		Grafo g(vert);
		for(int i = 0; i < arestas; i++){
			cin >> v1 >> v2 >> custo;
			g.addAresta(v1, v2, custo);
		}

		cout << g.kruskal() << "\n";
	}

	return 0;
}
