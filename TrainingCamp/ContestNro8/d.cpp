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
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

int main() {
    ll vertices;
    cin >> vertices;
    vector<ll> deciciones(vertices, 0LL);
    vector<ll> anterior(vertices, -1LL);
    vector<ll> hotel;
    forr(i, vertices) {
        int b;
        cin >> b;
        if (b == 1)
            hotel.push_back(i);
    }
    forr(i, vertices) {
        ll ant;
        cin >> ant;
        ant--;
        anterior[i] = ant;
        if (ant == -1)
            continue;
        deciciones[ant]++;
    }
    ll maximo = 0;
    ll inicioMaximo;
    for (ll inicio : hotel) {
        ll largoCamino = 1;
        ll actual = inicio;
        while (anterior[actual] != -1 && deciciones[anterior[actual]] <= 1) {
            largoCamino++;
            actual = anterior[actual];
        }
        if (maximo < largoCamino) {
            maximo = largoCamino;
            inicioMaximo = inicio;
        }
    }
    vector<ll> camino;
    ll caminante = inicioMaximo;
    while (anterior[caminante] != -1 && deciciones[anterior[caminante]] <= 1) {
        camino.push_back(caminante);
        caminante = anterior[caminante];
    }
    camino.push_back(caminante);
    cout << maximo << endl;
    for (ll i = camino.size() - 1; i >= 0; i--) {
        cout << camino[i] + 1 << ' ';
    }
    cout << endl;
}