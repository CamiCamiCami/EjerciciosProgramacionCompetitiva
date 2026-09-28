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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> compraA;
    ll vendedores, plata, tratos = 0;
    cin >> vendedores >> plata;
    forr(i, vendedores) {
        ll productos, trato = 0;
        cin >> productos;
        forr(j, productos) {
            ll precio;
            cin >> precio;
            if (precio < plata && trato == 0) {
                trato = 1;
                compraA.push_back(i + 1);
            }
        }
        tratos += trato;
    }
    cout << tratos << endl;
    for (ll compra : compraA) {
        cout << compra << " ";
    }
    cout << endl;
}