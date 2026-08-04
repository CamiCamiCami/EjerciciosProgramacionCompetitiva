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

ll pasosConvierte(string desde, string hasta) {
    vector<ll> unosDesde, unosHasta;
    forr(i, desde.size()) {
        if (desde[i] == '1') {
            unosDesde.push_back(i);
        }
        if (hasta[i] == '1') {
            unosHasta.push_back(i);
        }
    }
    if (unosDesde.size() != unosHasta.size()) {
        return -1;
    }
    ll pasos = 0;
    forr(i, unosDesde.size()) {
        ll dist = unosDesde[i] - unosHasta[i];
        dist = dist < 0 ? -dist : dist;
        pasos += dist;
    }
    return pasos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo;
        string desde, desdePar = "", desdeImpar = "", hasta, hastaPar = "", hastaImpar = "";
        cin >> largo >> desde >> hasta;
        if (largo < 3) {
            if (desde == hasta) {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        bool par = true;
        for (char c : desde) {
            if (par) {
                desdePar = c + desdePar;
            } else {
                desdeImpar = c + desdeImpar;
            }
            par = not par;
        }
        par = true;
        for (char c : hasta) {
            if (par) {
                hastaPar = c + hastaPar;
            } else {
                hastaImpar = c + hastaImpar;
            }
            par = not par;
        }

        ll pasosPares = pasosConvierte(desdePar, hastaPar);
        ll pasosImpar = pasosConvierte(desdeImpar, hastaImpar);
        if (pasosPares == -1 || pasosImpar == -1) {
            cout << -1 << endl;
        } else {
            cout << pasosPares + pasosImpar << endl;
        }
    }
}