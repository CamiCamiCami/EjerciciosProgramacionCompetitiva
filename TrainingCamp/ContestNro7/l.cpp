#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll int
#define dd long double
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < (largo); i++)  \
        (arr)[i] = (contenido);
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

set<ll> apostantesIgnorados;
vector<vector<ll>> indicesApostante;
vector<pair<ll, ll>> ultimaAparicion;
vector<pair<ll, ll>> historial;
ll ignoradoExtra = -1;

bool siguenIgnorados(ll x) {
    ll revisoDesde = lower_bound(ultimaAparicion.begin(), ultimaAparicion.end(), pair<ll, ll>{x + 1, 0}) - ultimaAparicion.begin();
    forrr(i, revisoDesde, ultimaAparicion.size()) {
        auto [apareceEn, apostante] = ultimaAparicion[i];
        if (apostantesIgnorados.count(apostante) != 1 && ignoradoExtra != apostante) {
            return false;
        }
    }
    return true;
}

ll buscarUltimoApostante() {
    ll L = 0;
    ll R = historial.size() - 1;
    ll ans = -1;
    ignoradoExtra = -1;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (siguenIgnorados(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    if (ans == 0) {
        if (apostantesIgnorados.count(historial[ans].first) == 1) {
            return -1;
        }
    }
    return historial[ans].first;
}

ll buscarApuestaRelevante(ll apostador) {
    if (indicesApostante[apostador].size() == 1)
        return indicesApostante[apostador][0];
    ll L = 0;
    ll R = indicesApostante[apostador].size() - 2;
    ll ans = -1;
    ignoradoExtra = apostador;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (siguenIgnorados(indicesApostante[apostador][mid])) {
            R = mid - 1;
        } else {
            ans = mid;
            L = mid + 1;
        }
    }
    return indicesApostante[apostador][ans + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll apuestas;
    cin >> apuestas;
    indicesApostante = vector<vector<ll>>(apuestas);
    ultimaAparicion = vector<pair<ll, ll>>(apuestas);
    forrr(i, 1, apuestas) {
        ultimaAparicion[i] = {0, i};
    }
    forr(i, apuestas) {
        ll apostante, tamagno;
        cin >> apostante >> tamagno;
        apostante--;
        historial.push_back({apostante, tamagno});
        ultimaAparicion[apostante] = {i, apostante};
        indicesApostante[apostante].push_back(i);
    }
    sort(ultimaAparicion.begin(), ultimaAparicion.end());

    ll queries;
    cin >> queries;
    while (queries--) {
        apostantesIgnorados.clear();
        ll aEvitar;
        cin >> aEvitar;
        forr(i, aEvitar) {
            ll n;
            cin >> n;
            n--;
            apostantesIgnorados.insert(n);
        }
        ll nuevoGanador = buscarUltimoApostante();
        if (nuevoGanador == -1) {
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
        ll ganadora = buscarApuestaRelevante(nuevoGanador);
        cout << nuevoGanador + 1 << " " << historial[ganadora].second << endl;
    }
}