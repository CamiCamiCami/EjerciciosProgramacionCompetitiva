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
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            int bordesFaciles = 0, faciles = 0, problemas;
            cin >> problemas;
            forr(i, problemas) {
                int num;
                cin >> num;
                if (num == 1)
                    continue;
                if (i == 0 || i == problemas - 1) {
                    bordesFaciles++;
                }
                faciles++;
            }
            if (faciles < 2) {
                cout << -1 << endl;
            } else {
                cout << 2 - bordesFaciles << endl;
            }
        }
    }
}