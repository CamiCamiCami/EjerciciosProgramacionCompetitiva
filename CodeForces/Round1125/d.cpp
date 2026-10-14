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
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

#define puedeSubir(a, b, c) (a > b || a > c || b > c)

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll laboratorios, ajustes;
            cin >> laboratorios >> ajustes;
            vector<tuple<ll, ll, ll>> laboratorio;
            vector<pair<ll, ll>> sumas;
            forr(i, laboratorios) {
                ll a, b, c;
                cin >> a >> b >> c;
                laboratorio.push_back({a, b, c});
                sumas.push_back({a + b + c, i});
            }

            sort(sumas.begin(), sumas.end());

            ll maximo = sumas[0].first;
            forr(i, laboratorios) {
                auto [a, b, c] = laboratorio[sumas[i].second];
                if (a == b && b == c) break;

                if (!puedeSubir(a, b, c)) {
                    if (a == b || b == c) {
                        ajustes -= 2;
                    } else {
                        ll calibre = min(min(b - a, c - a), c - b) + 1;
                        ajustes -= calibre * 2;
                    }
                }

                if (i + 1 < laboratorios) {
                    ll hasta = sumas[i + 1].first;
                    ll necesita = (i + 1) * (hasta - maximo);
                    if (ajustes >= necesita) {
                        ajustes -= necesita;
                        maximo = hasta;
                    } else {
                        ll pudoSubir = max(ajustes / (i + 1), 0LL);
                        maximo += pudoSubir;
                        break;
                    }
                } else {
                    ll pudoSubir = max(ajustes / (i + 1), 0LL);
                    maximo += pudoSubir;
                    break;
                }
            }
            cout << maximo << endl;
        }
    }
}