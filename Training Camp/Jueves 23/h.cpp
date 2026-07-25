#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, char>>>;
using Grafo = vector<vector<ll>>;

GrafoPesado digrafo;


void digrafear(GrafoPesado& g) {
    digrafo = GrafoPesado(g.size());
    vector<ll> distancias(g.size(), -2);
    vector<bool> visitados(g.size(), false);
    queue<ll> q;
    q.push(g.size() - 1);
    distancias[g.size() - 1] = 0;
    while(!q.empty()) {
        ll actual = q.front();
        ll distActual = distancias[actual];
        q.pop();
        visitados[actual] = true;

        for(auto [vecino, letra] : g[actual]){
            if(distancias[vecino] == distActual-1) {
                digrafo[actual].push_back({vecino, letra});
            }
            if(distancias[vecino] == -2 || distancias[vecino] > distActual+1) {
                
            }
        }


    }
}

vector<ll> menorCamino;

string menosLexografico(ll desde, ll hasta) {
    string s = "";
    menorCamino.push_back(desde);
    while (desde != hasta) {
        ll minimoVecino = 0;
        char minimoCaracter = 'z' + 1;
        for (auto [v, l] : digrafo[desde]) {
            if (minimoCaracter > l) {
                minimoVecino = v;
                minimoCaracter = l;
            }
        }
        s += minimoCaracter;
        desde = minimoVecino;
        menorCamino.push_back(desde);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices >> aristas;
    GrafoPesado g(vertices + 1);
    forr(0, aristas) {
        ll v1, v2;
        char esp, c;
        cin >> v1 >> v2 >> c;
        g[v1].push_back({v2, c});
        g[v2].push_back({v1, c});
    }
    digrafear(g);
    string minimoLexografico = menosLexografico(1, vertices);
    cout << minimoLexografico.size() << '\n';
    for (ll n : menorCamino) {
        cout << n << ' ';
    }
    cout << '\n';
    cout << minimoLexografico << '\n';
}