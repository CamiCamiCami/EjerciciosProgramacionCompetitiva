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
    ll cantEnemigos, vida;
    cin >> cantEnemigos >> vida;
    vector<ll> enemigos;
    forr(i, cantEnemigos - 1) {
        ll vidaEnemigo;
        cin >> vidaEnemigo;
        enemigos.push_back(vidaEnemigo);
    }
    sort(enemigos.begin(), enemigos.end());

    ll enemigoActual = 0;
    while (vida > 0 && enemigoActual < enemigos.size()) {
        ll minimo = enemigos[enemigoActual];
        ll danno = ((enemigos.size() - enemigoActual) * minimo) - 1;
        vida -= danno;
        enemigoActual++;
    }
    if (vida <= 0)
        cout << "NO" << endl;
    else
        cout << "SI" << endl;
}