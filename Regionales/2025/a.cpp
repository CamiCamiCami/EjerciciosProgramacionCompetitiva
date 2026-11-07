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

vector<bool> conexos(ll N, set<pair<ll, ll>> &conectados, vector<ll> &grados) {
    vector<bool> visitados(N + 1, false);
    queue<ll> q;
    forrr(i, 1, N + 1) {
        if (grados[i] == 0) continue;
        q.push(i);
        visitados[i] = true;
        break;
    }
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        forrr(i, 1, N + 1) {
            if (visitados[i]) continue;
            auto par = minmax(actual, i);
            if (conectados.count(par)) continue;
            q.push(i);
            visitados[i] = true;
        }
    }
    return visitados;
}

bool hayCircuito(ll N, vector<ll> &grados, vector<bool> &componente, set<ll> incluye) {
    forrr(i, 1, N + 1) {
        if (grados[i] % 2) return false;
        if (!componente[i] && grados[i] != 0) return false;
    }
    for (ll e : incluye) {
        if (grados[e] == 0) return false;
    }
    return true;
}

bool hayRecorrido(ll N, vector<ll> &grados, vector<bool> &componente, set<ll> extremos) {
    ll impares = 0;
    forrr(i, 1, N + 1) {
        if (grados[i] % 2) impares++;
        if (!componente[i] && grados[i] != 0) return false;
    }
    if (impares != 2) return false;
    for (ll e : extremos) {
        if (grados[e] % 2 == 0) return false;
    }
    return true;
}

tuple<ll, ll, bool> leeLinea(ll largo, vector<ll> &grados, set<pair<ll, ll>> &conexiones) {
    if (largo == 0) return {0, 0, true};
    ll ant, act, primer, ultimo;
    bool posible = true;
    cin >> ant;
    primer = ant;
    forr(i, largo - 1) {
        cin >> act;
        auto [menor, mayor] = minmax(act, ant);
        if (conexiones.count({menor, mayor})) posible = false;
        if (menor == mayor) posible = false;
        conexiones.insert({menor, mayor});
        grados[menor]--;
        grados[mayor]--;
        ant = act;
    }
    ultimo = ant;
    return {primer, ultimo, posible};
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    while (cin >> N) {
        set<pair<ll, ll>> conexiones;
        vector<ll> grados(N + 1, N - 1);
        bool posible = true;

        ll cantIni, cantFin;
        cin >> cantIni;
        auto [_, extIni, sinError1] = leeLinea(cantIni, grados, conexiones);
        posible = posible && sinError1;
        cin >> cantFin;
        auto [extFin, __, sinError2] = leeLinea(cantFin, grados, conexiones);
        posible = posible && sinError2;

        set<ll> setExtremos;
        ll extremos = 0;
        if (extIni != 0) {
            setExtremos.insert(extIni);
            extremos++;
        }
        if (extFin != 0) {
            setExtremos.insert(extFin);
            extremos++;
        }

        bool vacio = true;
        forrr(i, 1, N) { vacio = vacio && grados[i] == 0; }
        vector<bool> componente = conexos(N, conexiones, grados);

        if (!vacio) {
            if (extremos == 2 && extIni == extFin) {
                // Circuito euleriano
                posible = posible && hayCircuito(N, grados, componente, setExtremos);
            } else if (extremos == 2) {
                // Recorrido euleriano
                posible = posible && hayRecorrido(N, grados, componente, setExtremos);
            } else {
                // Recorrido o circuito euleriano
                posible = posible && (hayCircuito(N, grados, componente, setExtremos) || hayRecorrido(N, grados, componente, setExtremos));
            }
        } else if (extremos == 2) posible = false;

        if (posible) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}