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
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

vector<bool> visto;

void __calcularAlturas(Arbol& g, ll raiz, vector<ll>& altura, vector<bool>& visitado) {
    visitado[raiz] = true;
    ll maxAltura = 0;
    for (ll vecino : g[raiz]) {
        if (visitado[vecino])
            continue;
        __calcularAlturas(g, vecino, altura, visitado);
        maxAltura = max(maxAltura, altura[vecino] + 1);
    }
    altura[raiz] = maxAltura;
}

void calcularAlturas(Arbol& g, ll raiz, vector<ll>& altura) {
    vector<bool> visitados(g.size(), false);
    __calcularAlturas(g, raiz, altura, visitados);
}

ll maximaDistanciaDesde(Grafo& g, ll desde, vector<ll>& camino) {
    vector<ll> distancia(g.size(), 10E9);
    vector<ll> padres(g.size(), -1);
    queue<ll> q;
    ll maximaDistancia = -1, lejano;
    distancia[desde] = 0;
    q.push(desde);
    while (!q.empty()) {
        ll actual = q.front();
        visto[actual] = true;  // BORRAR PARA EL NOTEBOOK
        q.pop();
        if (maximaDistancia < distancia[actual]) {
            maximaDistancia = distancia[actual];
            lejano = actual;
        }
        for (ll vecino : g[actual]) {
            if (distancia[vecino] > distancia[actual] + 1) {
                padres[vecino] = actual;
                distancia[vecino] = distancia[actual] + 1;
                q.push(vecino);
            }
        }
    }
    ll recorriendo = lejano;
    while (recorriendo != -1) {
        camino.push_back(recorriendo);
        recorriendo = padres[recorriendo];
    }
    reverse(camino.begin(), camino.end());
    return maximaDistancia;
}

vector<ll> calcularDiametro(Arbol& g, ll nodo) {
    vector<ll> camino;
    maximaDistanciaDesde(g, nodo, camino);
    ll extremo = camino.back();
    camino.clear();
    maximaDistanciaDesde(g, extremo, camino);
    return camino;
}

void enraizar(Arbol& g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    queue<ll> q;
    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        visitados[actual] = true;
        vector<ll> hijos;
        for (ll vecino : g[actual]) {
            if (visitados[vecino])
                continue;
            hijos.push_back(vecino);
            q.push(vecino);
        }
        g[actual] = hijos;
    }
}

ll calcularCentro(vector<ll> diametro) {
    return diametro[diametro.size() / 2];
}

vector<Grafo> componentesConexas(Grafo& g) {
    vector<bool> visitados(g.size(), false);
    vector<Grafo> grafos;
    queue<ll> q;
    forr(nodo, g.size()) {
        if (visitados[nodo])
            continue;
        q.push(nodo);
        map<ll, ll> nuevosNombres;
        Grafo nuevo;
        ll aristas = 0;
        while (!q.empty()) {
            ll actual = q.front();
            q.pop();
            if (visitados[actual])
                continue;
            visitados[actual] = true;
            nuevosNombres[actual] = aristas;
            nuevo.push_back(vector<ll>());
            aristas++;
            for (ll vecino : g[actual]) {
                if (visitados[vecino]) {
                    ll nombreVecino = nuevosNombres[vecino], nombreActual = nuevosNombres[actual];
                    nuevo[nombreActual].push_back(nombreVecino);
                    nuevo[nombreVecino].push_back(nombreActual);
                }
                q.push(vecino);
            }
        }
        grafos.push_back(nuevo);
    }
    return grafos;
}

Grafo leerGrafo(ll vertices, ll aristas) {
    Grafo g(vertices);
    ll n1, n2;
    forr(i, aristas) {
        cin >> n1 >> n2;
        n1--;
        n2--;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices >> aristas;
    Grafo bosque = leerGrafo(vertices, aristas);
    visto = vector<bool>(bosque.size(), false);
    vector<ll> centros;
    vector<ll> alturas(bosque.size());
    ll centroDeCentros, maximaAltura = -1;
    forr(nodo, bosque.size()) {
        if (visto[nodo])
            continue;
        vector<ll> diametro = calcularDiametro(bosque, nodo);
        ll centro = calcularCentro(diametro);
        centros.push_back(centro);
        calcularAlturas(bosque, centro, alturas);
        if (alturas[centro] > maximaAltura) {
            centroDeCentros = centro;
            maximaAltura = alturas[centro];
        }
    }

    vector<pair<ll, ll>> nuevasAristas;
    forr(i, centros.size()) {
        ll centro = centros[i];
        if (centro == centroDeCentros)
            continue;
        nuevasAristas.push_back({centro, centroDeCentros});
        bosque[centroDeCentros].push_back(centro);
        bosque[centro].push_back(centroDeCentros);
        if (alturas[centroDeCentros] == alturas[centro]) {
            alturas[centroDeCentros]++;
        }
    }

    ll maximo = -1, segundoMaximo = -1;
    for (ll vecino : bosque[centroDeCentros]) {
        if (alturas[vecino] >= maximo) {
            segundoMaximo = maximo;
            maximo = alturas[vecino];
        } else if (alturas[vecino] >= segundoMaximo) {
            segundoMaximo = alturas[vecino];
        }
    }
    ll diametro = maximo + segundoMaximo + 2;
    cout << diametro << endl;
    for (auto [n1, n2] : nuevasAristas) {
        cout << n1 + 1 << ' ' << n2 + 1 << endl;
    }
}