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

ll sobrantes[50005];

void precalcular(vector<ll>& bolsas) {
    sort(bolsas.begin(), bolsas.end());
    deque<ll> masGrandes;
    vector<ll> masChicas;
    for (ll bolsa : bolsas) {
        masGrandes.push_back(bolsa);
    }
    masGrandes.push_back(1e10);
    forr(i, 50005) {
        sobrantes[i] = masGrandes.front() - i;
        for (ll bolsa : masChicas) {
            if (bolsa <= i) {
                sobrantes[i] = min(sobrantes[i], sobrantes[i - bolsa]);
            }
        }
        if (masGrandes.front() == i) {
            masChicas.push_back(masGrandes.front());
            masGrandes.pop_front();
        }
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        ll P;
        cin >> P;
        vector<ll> bolsas;
        forr(i, P) {
            ll tam;
            cin >> tam;
            bolsas.push_back(tam);
        }
        precalcular(bolsas);

        while (casos--) {
            ll necesita;
            cin >> necesita;
            cout << sobrantes[necesita] << endl;
        }
    }
}