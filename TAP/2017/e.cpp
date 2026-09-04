#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<ll, ll>> puntos;
    vector<ll> radios;
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    if ((n + m) * (m * x + n * y) > 2 * (x + y) * n * m)
        cout << "A" << '\n';
    else if ((n + m) * (m * x + n * y) < 2 * (x + y) * n * m)
        cout << "B" << '\n';
    else
        cout << "C" << '\n';
}