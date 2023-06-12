#include <vector>
#include<queue>
#include<stack>
#include <sstream>
#include <iostream>

using namespace std;
class Adyacente {
    public:
        int dest, coste;
        Adyacente(int dest, int coste){
            this->dest = dest;
            this->coste = coste;
        }
};

class Grafo {
    public:
        int numNodos, numAristas;
        std::vector<int> gradosEntrada;
        std::vector<std::vector<Adyacente>> adyacentes;

        Grafo(int numNodos) {
            this->numNodos = numNodos;
            this->numAristas = 0;
            gradosEntrada.resize(numNodos, 0);
            adyacentes.resize(numNodos);
        }

        void insertarArista(int origen, int dest, int coste){
            Adyacente ady(dest, coste);
            adyacentes[origen].push_back(ady);
            gradosEntrada[dest]++;
            numAristas++;
        }

        int getArista(int origen, int dest) {
            for(auto ady : adyacentes[origen]) {
                if(ady.dest == dest) {
                    return ady.coste;
                }
            }
        }

        bool existeArista(int origen, int dest) {
            for(auto ady : adyacentes[origen]) {
                if(ady.dest == dest){
                    return true;
                }
            }
            return false;
        }

        void eliminarArista(int origen, int dest) {
            for(unsigned int i = 0; i < adyacentes[origen].size(); i++){
                Adyacente ady = adyacentes[origen][i];
                if(ady.dest == dest) {
                    adyacentes[origen].erase(adyacentes[origen].begin() + i);
                    gradosEntrada[origen]--;
                    numAristas--;
                }
            }
        }

        std::string toString() {
            std::stringstream res;
            for(int i = 0; i< numNodos; i++){
                res << "Vertice: " << i;
                std::vector<Adyacente> l = adyacentes[i];
                if(l.empty()) {
                    res << " sin adyacentes ";
                } else {
                    res << " con adyacentes: ";
                }
                for(auto ady : l) {
                    res << ady.dest << "(" << ady.coste << ") ";
                }
            }
            return res.str();
        }

        vector<int> dfs(int origen) {
            vector<bool> visitados(adyacentes.size(), false);
            vector <int> ordenVisita;
            stack<int> pilaDFS;
            pilaDFS.push(origen);
            visitados[origen] = true;
            while(!pilaDFS.empty()){
                int actual = pilaDFS.top();
                pilaDFS.pop();
                ordenVisita.push_back((actual));
                for(auto ady : adyacentes[actual]) {
                    if(!visitados[ady.dest]) {
                        pilaDFS.push(ady.dest);
                        visitados[ady.dest] = true;
                    }
                }
            }
            return ordenVisita;
        }

        int dfsTamanyoVisitados(int origen, vector<bool> &visitados) {

            stack<int> pilaDFS;
            pilaDFS.push(origen);
            visitados[origen] = true;
            int tamanyo = 1;
            while(!pilaDFS.empty()){
                int actual = pilaDFS.top();
                pilaDFS.pop();
                for(auto ady : adyacentes[actual]) {
                    if(!visitados[ady.dest]) {
                        pilaDFS.push(ady.dest);
                        visitados[ady.dest] = true;
                        tamanyo++;
                    }
                }
            }
            return tamanyo;
        }     
};

int main(){
    int n, trees, acorns;
    cin >> n;
    for(int i = 0; i<n; i++){
        Grafo g = Grafo(27);
        string arista;
        cin >> arista;
        int a, b;
        while(arista[0] != '*'){
            a = arista[1] - 'A';
            b = arista[3] - 'A';
            Adyacente c = Adyacente(a, 1);
            Adyacente d = Adyacente(b, 1);
            g.adyacentes[a].push_back(d);
            g.adyacentes[b].push_back(c);
            cout << "test\n";
            cin >> arista;
        }
        string nodes;
        cin >> nodes;
        for(int j = 0; j<nodes.length(); j+=2){
            int a = nodes[j] - 'A';

            if(g.adyacentes[a].size() == 0){
                Adyacente n = Adyacente(-1, 0);
                g.adyacentes[a].push_back(n);
            } 
            cout << "esst" << endl;
        }

        vector<bool> visitados(28, false);
        trees = acorns = 0;
        for(int j = 0; j<27; j++){
            cout << j << endl;
            cout << g.adyacentes.size() << endl;
            cout << g.adyacentes[j][0].coste << endl;
            if(g.adyacentes[j][0].dest == -1){
                cout << 1 << endl;
                visitados[j] = true;
                cout << 2 << endl;
            } else {
                if(visitados[j] == false){
                    int size = g.dfsTamanyoVisitados(j, visitados);
                    if(size == 1){
                        acorns++;
                    } else {
                        trees++;
                    }
                }
            }
            cout << trees << " " << acorns << " "  << g.adyacentes[j][0].dest << endl;
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }
    
    return 0;
}