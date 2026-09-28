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
    ll n;
    cin >> n;
    vector<bool> aparecieron(n, false);
    ll mesa = 0, maxMesa = 0;
    forr(0, 2 * n) {
        ll media;
        cin >> media;
        media--;
        if (aparecieron[media]) {
            maxMesa = maxMesa > mesa ? maxMesa : mesa;
            mesa--;
        } else {
            aparecieron[media] = true;
            mesa++;
        }
    }
    maxMesa = maxMesa > mesa ? maxMesa : mesa;
    cout << maxMesa << '\n';
}