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
        int a, b;
        cin >> a >> b;
        if (b > a) {
            int r = (b - a) / 5;
            int x = b - (r * 5) - a;
            if (x >= 3) {
                cout << r + 2 << '\n';
            } else if (x >= 1) {
                cout << r + 1 << '\n';
            } else {
                cout << r << '\n';
            }

        } else {
            int r = (a - b) / 5;
            int x = a - (r * 5) - b;
            if (x >= 3) {
                cout << r + 2 << '\n';
            } else if (x >= 1) {
                cout << r + 1 << '\n';
            } else {
                cout << r << '\n';
            }
        }
    }
}