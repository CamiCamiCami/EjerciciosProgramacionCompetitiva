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
#define endl '\n'
#define initArr(arr, largo, contenido)                                                                                                               \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll edificios;
            cin >> edificios;
            vector<ll> empresasIzq(edificios), empresasDer(edificios);
            forr(i, edificios) { cin >> empresasIzq[i]; }
            forr(i, edificios) { cin >> empresasDer[i]; }
            vector<ll> caminosIzq(edificios), caminosDer(edificios), caminosDobles(edificios), caminosParalelos(edificios);
            caminosDobles[0] = caminosDer[0] = caminosIzq[0] = empresasIzq[0] == empresasDer[0] ? 2 : 1;
            caminosParalelos[0] = 0;
            forrr(i, 1, edificios) {
                ll horizontal = empresasIzq[i] == empresasDer[i] ? 2 : 1;
                ll diag = empresasIzq[i - 1] == empresasDer[i] ? 2 : 1;
                ll antidiag = empresasIzq[i] == empresasDer[i - 1] ? 2 : 1;
                caminosDobles[i] = caminosDobles[i - 1] + diag + antidiag;
                ll ambasPrll = diag + antidiag + caminosParalelos[i - 1];
                ll diagPrll = max(diag + caminosIzq[i - 1], antidiag + caminosDer[i - 1]);
                ll doblePrll = max(diag, antidiag) + caminosDobles[i - 1];
                caminosParalelos[i] = max(ambasPrll, max(diagPrll, doblePrll));
                caminosIzq[i] = horizontal + diag + max(caminosDobles[i - 1], caminosIzq[i - 1]);
                caminosDer[i] = horizontal + antidiag + max(caminosDobles[i - 1], caminosDer[i - 1]);
            }
            caminosParalelos[edificios - 1] += empresasIzq[edificios - 1] == empresasDer[edificios - 1] ? 2 : 1;
            ll resultadoFinal =
                max(max(caminosIzq[edificios - 1], caminosDer[edificios - 1]), max(caminosParalelos[edificios - 1], caminosDobles[edificios - 1]));
            cout << resultadoFinal << endl;
        }
    }
}