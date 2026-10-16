#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define ull unsigned long long
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define endl '\n'
#define initArr(arr, largo, contenido)                                                                                                               \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;



pair<ll, ll> caminoMasPesado(Grafo& g, ll desde, vector<ll> &peso, vector<bool> &visitado) {
    ll pesoCamino = peso[desde];
    ll llega = desde;
    visitado[desde] = true;
    for(ll vecino : g[desde]) {
        if(visitado[vecino]) continue;
        auto [pesoVe, llegaVe] = caminoMasPesado(g, vecino, peso, visitado);
        if(pesoVe + peso[desde] > pesoCamino) {
            pesoCamino = pesoVe + peso[desde];
            llega = llegaVe;
        }
    }
    return {pesoCamino, llega};
}


int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll nodos;
            cin >> nodos;
            vector<ll> importancia(nodos, -1);
            Grafo g(nodos);
            forr(i, nodos-1) {
                ll desde, hasta;
                cin >> desde >> hasta;
                desde--;
                hasta--;
                importancia[desde]++;
                importancia[hasta]++;
                g[desde].push_back(hasta);
                g[hasta].push_back(desde);
            }
            vector<bool> visitado(nodos, false);
            auto [_, extremo] = caminoMasPesado(g, 0, importancia, visitado);
            visitado = vector<bool>(nodos, false);
            auto [peso, __] = caminoMasPesado(g, extremo, importancia, visitado);
            cout << peso + 2 << endl;
        }
    }
}