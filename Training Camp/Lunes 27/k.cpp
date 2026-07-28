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
    int n;
    char let;
    vector<char> segs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> let;
        segs.push_back(let);
    }
    bool sepuede = false;
    for (int salto = 1; salto < n && !sepuede; salto++) {
        for (int arranque = 0; arranque < n && !sepuede; arranque++) {
            int plat = 0;
            for (int k = 0; k < 5 && !sepuede; k++) {
                if (arranque + (k * salto) <= n - 1 && segs[arranque + (k * salto)] == '*') {
                    plat++;
                }
            }
            if (plat > 4) {
                sepuede = true;
            }
        }
    }
    cout << (sepuede ? "yes" : "no") << '\n';
}