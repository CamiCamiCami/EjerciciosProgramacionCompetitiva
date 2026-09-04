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

vector<ll> vecTazas;

bool func(ll dias, ll paginas) {
    ll vueltas = 0, dia = 0, escrito = 0;
    for (ll taza : vecTazas) {
        escrito += taza - vueltas;
        vueltas = dia + 1 == dias ? vueltas + 1 : vueltas;
        dia = dia + 1 == dias ? 0 : dia + 1;
        if (escrito >= paginas)
            return true;
    }
    return false;
}

ll diasNecesarios(ll paginas) {
    ll L = 1;
    ll R = 100;
    ll ans = -1;
    while (L <= R) {
        ll mid = L + (R - L) / 2;

        if (func(mid, paginas)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    return ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tazas, paginas;
    while (cin >> tazas) {
        vecTazas.clear();
        cin >> paginas;
        forr(i, tazas) {
            ll cafe;
            cin >> cafe;
            vecTazas.push_back(cafe);
        }
        sort(vecTazas.begin(), vecTazas.end());
        reverse(vecTazas.begin(), vecTazas.end());
        cout << diasNecesarios(paginas) << endl;
    }
}