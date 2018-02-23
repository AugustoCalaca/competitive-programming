#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pb push_back
#define ini -1

using namespace std;


// accepted
class Aresta{
private:
	int vertice1;
	int vertice2;
	double peso;
public:
	Aresta(int vert1, int vert2, double pso){
		vertice1 = vert1;
		vertice2 = vert2;
		peso = pso;
	}

	int getV1(){
		return vertice1;
	}

	int getV2(){
		return vertice2;
	}

	double getPeso(){
		return peso;
	}

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

	void addAresta(int v1, int v2, double peso){
		Aresta aresta(v1, v2, peso);

		arestas.pb(aresta);
	}

	int buscar(int subconj[], int i){
		if(subconj[i] == ini)
			return i;
		return buscar(subconj, subconj[i]);
	}

	void unir(int subconj[], int v1, int v2){
		subconj[v1] = v2;
	}

	double kruskal(){
		double soma = 0.0;
		int *subconj = new int[vertices];

		// inicializa todo o subconjunto com -1
		fill(subconj, subconj + vertices, ini);
		// ordena conforme peso
		sort(arestas.begin(), arestas.end());

		int v1, v2;
		for(auto it = arestas.begin(); it != arestas.end(); it++){
			v1 = buscar(subconj, it->getV1());
			v2 = buscar(subconj, it->getV2());

			// se forem diferentes entao no forma ciclo
			if(v1 != v2){
				// melhor solucao local
				soma = soma + it->getPeso();
				unir(subconj, v1, v2);
			}
		}

		// os valore estao em CM, converte pr M
		return soma / 100;
	}
};

// calcula a distancia entre os pontos
double distancia(int x1, int x2, int y1, int y2){
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){
	int casos, vertices/*num pessoas*/, x1, y1
	vector<pair<int, int> > v1v2;

	for(cin >> casos; casos; casos--){
		cin >> vertices;

		Grafo g(vertices);

		for(int aux = 0; aux < vertices; aux++){
			cin >> x1 >> y1;
			v1v2.pb(make_pair(x1, y1));
		}

		for(int i = 0; i < vertices - 1; i++){
			auto it = v1v2.begin() + i;

			for(int j = i + 1; j < vertices; j++){
				auto it2 = v1v2.begin() + j;
				g.addAresta(i, j, distancia(it->first, it2->first, it2->second, it->second));
			}
		}

		v1v2.clear();
		cout.precision(2);
		cout << fixed << g.kruskal() << "\n";
	}

	return 0;
}
