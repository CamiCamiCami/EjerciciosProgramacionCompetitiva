#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll num;
    cin >> num;
    if (num == 0) {
        cout << "0 0 0\n";
    } else if (num == 1) {
        cout << "0 0 1\n";
    } else {
        ll anterior = 1, anteanterior = 0, actual = 1;
        while (actual != num) {
            anteanterior = anterior;
            anterior = actual;
            actual = anteanterior + anterior;
        }
        cout << "0 " << anteanterior << ' ' << anterior << '\n';
    }
}