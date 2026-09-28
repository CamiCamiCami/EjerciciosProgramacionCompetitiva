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
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        int n, i = 1, j = 0;
        bool terminar = false;
        cin >> n;
        for (i = 1; i <= n && !terminar;) {
            int guardar = i;
            for (int mult = 1; mult < 10; mult++) {
                if (i * mult <= n) {
                    j++;
                } else {
                    terminar = true;
                }
            }
            i = (guardar * 10) + 1;
        }

        cout << j << '\n';
    }
}