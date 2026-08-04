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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo;
        string desde, busca;
        cin >> largo >> desde >> busca;
        bool sePuede;
        if (largo < 3) {
            sePuede = desde == busca;
        } else {
            vector<ll> unosDesde(2, 0), unosBusca(2, 0);
            forr(i, largo) {
                if (desde[i] == '1') {
                    unosDesde[i % 2]++;
                }
                if (busca[i] == '1') {
                    unosBusca[i % 2]++;
                }
            }
            sePuede = unosDesde[0] == unosBusca[0] && unosDesde[1] == unosBusca[1];
        }
        cout << (sePuede ? "YES" : "NO") << endl;
    }
}