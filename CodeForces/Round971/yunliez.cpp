#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

ll masFrecuente(map<ll, ll> frecuencias) {
    ll frecuencia = 0;
    for (auto item : frecuencias) {
        if (item.second > frecuencia) {
            frecuencia = item.second;
        }
    }
    return frecuencia;
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> arr;
        arr.push_back(0);  // basura
        for (ll i = 1; i <= n; i++) {
            ll num;
            cin >> num;
            arr.push_back(i - num);
        }
        map<ll, ll> frecuencias;
        for (ll i = 1; i < k; i++) {
            if (frecuencias.count(arr[i]) == 0)
                frecuencias[arr[i]] = 0;
            frecuencias[arr[i]]++;
        }
        vector<ll> precalculado;
        precalculado.push_back(0);  // basura
        for (ll i = 1; i <= n; i++) {
            if (i + k - 1 <= n) {
                if (frecuencias.count(arr[i + k - 1]) == 0)
                    frecuencias[arr[i + k - 1]] = 0;
                frecuencias[arr[i + k - 1]]++;
            }
            precalculado.push_back(k - masFrecuente(frecuencias));
            frecuencias[arr[i]]--;
        }
        while (q--) {
            ll l, r;
            cin >> l >> r;
            cout << precalculado[l] << endl;
        }
        arr.clear();
    }
}