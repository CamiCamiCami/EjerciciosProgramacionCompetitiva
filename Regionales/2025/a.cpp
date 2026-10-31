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
        break;
    }
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        if (visitados[actual]) continue;
        visitados[actual] = true;
        forrr(i, 1, N + 1) {
            if (visitados[i]) continue;
            auto par = minmax(actual, i);
            if (conectados.count(par)) continue;
            q.push(i);
        }
    }
    return visitados;
}

bool hayCircuito(ll N, vector<ll> &grados, vector<bool> &componente) {
    forrr(i, 1, N + 1) {
        if (grados[i] % 2) return false;
        if (!componente[i] && grados[i] != 0) return false;
    }
    return true;
}

bool hayRecorrido(ll N, vector<ll> &grados, vector<bool> &componente, ll desde, ll hasta) {
    ll impares = 0;
    forrr(i, 1, N + 1) {
        if (grados[i] % 2) impares++;
        if (!componente[i] && grados[i] != 0) return false;
    }
    if (impares != 2) return false;
    if (desde != -1 && grados[desde] % 2 == 0) return false;
    if (hasta != -1 && grados[hasta] % 2 == 0) return false;
    return true;
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
        ll extIni = -1, extFin = -1;
        ll extremos = 0;
        cin >> cantIni;
        if (cantIni != 0) {
            extremos++;
            ll ant;
            cin >> ant;
            forr(i, cantIni - 1) {
                ll act;
                cin >> act;
                auto [menor, mayor] = minmax(act, ant);
                if (conexiones.count({menor, mayor})) posible = false;
                if (menor == mayor) posible = false;
                conexiones.insert({menor, mayor});
                grados[menor]--;
                grados[mayor]--;
                ant = act;
            }
            extIni = ant;
        }

        cin >> cantFin;
        if (cantFin != 0) {
            extremos++;
            ll ant;
            cin >> ant;
            extFin = ant;
            forr(i, cantFin - 1) {
                ll act;
                cin >> act;
                auto [menor, mayor] = minmax(act, ant);
                if (conexiones.count({menor, mayor})) posible = false;
                if (menor == mayor) posible = false;
                conexiones.insert({menor, mayor});
                grados[menor]--;
                grados[mayor]--;
                ant = act;
            }
        }

        bool vacio = true;
        forrr(i, 1, N) { vacio = vacio && grados[i] == 0; }
        if (vacio && extremos == 2) {
            posible = false;
        }

        vector<bool> componente = conexos(N, conexiones, grados);
        if (extremos == 2 && extIni == extFin) {
            // Circuito euleriano
            posible = posible && hayCircuito(N, grados, componente);
        } else if (extremos == 2) {
            // Recorrido euleriano
            posible = posible && hayRecorrido(N, grados, componente, extIni, extFin);
        } else {
            // Recorrido o circuito euleriano
            posible = posible && (hayCircuito(N, grados, componente) || hayRecorrido(N, grados, componente, extIni, extFin));
        }

        if (posible) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}