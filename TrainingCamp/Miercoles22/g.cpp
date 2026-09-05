#include <algorithm>
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
    ll amigos, mensajes;
    cin >> amigos >> mensajes;
    vector<set<ll>> rachas(amigos);
    vector<ll> maxPos(amigos);
    vector<ll> minPos(amigos);
    maxPos[0] = 1;
    forr(1, amigos) {
        minPos[i] = maxPos[i] = maxPos[i - 1] + 1;
        rachas[i] = set<ll>(rachas[i - 1]);
        rachas[i].insert(i - 1);
    }

    forr(0, mensajes) {
        ll mensaje;
        cin >> mensaje;
        mensaje--;
        maxPos[mensaje] = maxPos[mensaje] < (rachas[mensaje].size() + 1) ? (rachas[mensaje].size() + 1) : maxPos[mensaje];
        minPos[mensaje] = 1;
        cout << "Mensaje:" << mensaje << '\n';
        for (int i = 0; i < amigos; i++) {
            rachas[i].insert(mensaje);
            for (ll e : rachas[i])
                cout << e << ' ';
            cout << '\n';
        }
        rachas[mensaje].clear();
    }
    forr(0, amigos) {
        cout << minPos[i] << ' ' << maxPos[i] << '\n';
    }
}