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
#define INF (1e18)
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

ll cortesPosibles[4000 + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    initArr(cortesPosibles, n, -INF);
    cortesPosibles[a - 1] = cortesPosibles[b - 1] = cortesPosibles[c - 1] = 0;
    forr(i, n) {
        if (i - a >= 0) {
            cortesPosibles[i] = max(cortesPosibles[i], cortesPosibles[i - a]);
        }
        if (i - b >= 0) {
            cortesPosibles[i] = max(cortesPosibles[i], cortesPosibles[i - b]);
        }
        if (i - c >= 0) {
            cortesPosibles[i] = max(cortesPosibles[i], cortesPosibles[i - c]);
        }
        cortesPosibles[i] = cortesPosibles[i] == -INF ? -INF : cortesPosibles[i] + 1;
    }
    cout << cortesPosibles[n - 1] << endl;
}