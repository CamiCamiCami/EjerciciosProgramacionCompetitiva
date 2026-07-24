#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define dd long double
#define ll long long
#define forr(d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (ll i = 0; i < largo; i++)     \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    ll masPuntos[200000];
    while (casos--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> maximos(n), primeras(n);
        forr(0, n) {
            cin >> primeras[i];
        }
        cin >> maximos[0];
        forr(1, n) {
            cin >> maximos[i];
            maximos[i] = max(maximos[i], maximos[i - 1]);
        }
        if (n < k) {
            masPuntos[n - 1] = primeras[n - 1] + (k - n) * maximos[n - 1];
            for (ll i = n - 2; i >= 0; i--) {
                ll jugadas = k - i;
                ll repitiendo = (jugadas - 1) * maximos[i];
                masPuntos[i] = primeras[i] + max(repitiendo, masPuntos[i + 1]);
            }
        } else {
            masPuntos[k] = 0;
            for (ll i = k - 1; i >= 0; i--) {
                ll jugadas = k - i;
                ll repitiendo = (jugadas - 1) * maximos[i];
                masPuntos[i] = primeras[i] + max(repitiendo, masPuntos[i + 1]);
            }
        }
        cout << masPuntos[0] << '\n';
    }
}