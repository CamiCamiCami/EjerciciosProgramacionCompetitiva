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

vector<Par> pares;
vector<ll> colores;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices;
    aristas = vertices - 1;
    set<ll> verticesTranscolor;
    forr(i, aristas) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        verticesTranscolor.insert(n1);
        verticesTranscolor.insert(n2);
        pares.push_back({n1, n2});
    }
    forr(i, vertices) {
        ll c;
        cin >> c;
        colores.push_back(c);
    }

    for (auto [v1, v2] : pares) {
        if (colores[v1] == colores[v2])
            continue;
        set<ll> s;
        if (verticesTranscolor.count(v1) == 1) {
            s.insert(v1);
        }
        if (verticesTranscolor.count(v2) == 1) {
            s.insert(v2);
        }
        verticesTranscolor = s;
        if (s.empty()) {
            break;
        }
    }
    if (verticesTranscolor.size() != 0) {
        cout << "YES" << endl;
        cout << *(verticesTranscolor.begin()) + 1 << endl;
    } else {
        cout << "NO" << endl;
    }
}