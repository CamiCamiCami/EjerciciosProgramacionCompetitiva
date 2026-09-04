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

vector<pair<ll, ll>> objetos;

ll valorConseguido[105][100005];

void precalcular(ll W) {
    forrr(i, 1, objetos.size() + 1) {
        auto [peso, valor] = objetos[i - 1];
        forr(j, peso) {
            valorConseguido[i][j] = valorConseguido[i - 1][j];
        }
        forrr(j, peso, W + 1) {
            valorConseguido[i][j] = max(valorConseguido[i - 1][j - peso] + valor, valorConseguido[i - 1][j]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, W;
    initArr(valorConseguido[0], 100005, 0);
    while (cin >> N) {
        cin >> W;
        objetos.clear();
        forr(i, N) {
            ll peso, valor;
            cin >> peso >> valor;
            objetos.push_back({peso, valor});
        }
        precalcular(W);
        cout << valorConseguido[N][W] << endl;
    }
}