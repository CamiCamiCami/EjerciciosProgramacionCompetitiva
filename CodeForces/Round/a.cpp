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
        ll bolsas;
        cin >> bolsas;
        vector<ll> bolsa(bolsas);
        forr(i, bolsas) {
            cin >> bolsa[i];
        }
        if (bolsas % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        bool sePuede = true;

        ll menorMayor = 10E9 + 1, mayorMenor = 0;
        for (ll i = 0; i < bolsas && sePuede; i += 2) {
            sePuede = sePuede && bolsa[i] >= bolsa[i + 1];
            menorMayor = min(menorMayor, bolsa[i]);
            mayorMenor = max(mayorMenor, bolsa[i + 1]);
        }
        sePuede = sePuede && (mayorMenor + 1) < menorMayor;
        cout << (sePuede ? "YES\n" : "NO\n");
    }
}