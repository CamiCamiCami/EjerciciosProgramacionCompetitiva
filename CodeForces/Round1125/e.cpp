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
#define initArr(arr, largo, contenido)                                                                                 \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

#define peso(e1, e2) (e1 == e2 ? 2 : 1)
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
            vector<ll> cruzadosDesde(edificios), cambiaEn(edificios);
            cruzadosDesde[edificios - 1] = peso(empresasIzq[edificios - 1], empresasDer[edificios - 1]);
            for (ll i = edificios - 2; i >= 0; i--) {
                ll diag = peso(empresasIzq[i + 1], empresasDer[i]);
                ll antidiag = peso(empresasIzq[i], empresasDer[i + 1]);
                cruzadosDesde[i] = cruzadosDesde[i + 1] + diag + antidiag;
            }

            ll rectoHasta = 0;
            forr(i, edificios - 1) {
                cambiaEn[i] = rectoHasta + cruzadosDesde[i];
                ll diag = peso(empresasIzq[i + 1], empresasDer[i]);
                ll horizontal = peso(empresasIzq[i], empresasDer[i]);
                rectoHasta += diag + horizontal;
            }
            cambiaEn[edificios - 1] = rectoHasta + cruzadosDesde[edificios - 1];

            ll largo = 0;
            for (ll opcion : cambiaEn) {
                largo = max(largo, opcion);
            }

            cout << largo << endl;
        }
    }
}