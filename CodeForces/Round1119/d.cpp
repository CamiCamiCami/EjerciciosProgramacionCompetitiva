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
            ll largo;
            cin >> largo;
            string sol;
            bool huboCero = false;
            bool dobleCero = false;
            forr(i, largo) {
                ll num;
                cin >> num;
                if (num != 0) {
                    sol.push_back('A');
                } else if (!huboCero) {
                    huboCero = true;
                    sol.push_back('B');
                } else {
                    dobleCero = true;
                    sol.push_back('C');
                }
            }
            if (!huboCero || dobleCero) {
                cout << "YES" << endl;
                cout << sol << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}