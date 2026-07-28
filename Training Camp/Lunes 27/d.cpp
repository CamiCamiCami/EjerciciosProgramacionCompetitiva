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
    ll largo;
    cin >> largo;
    vector<ll> arr(largo);
    ll maximo = 0;
    forr(i, largo) {
        cin >> arr[i];
        maximo = max(maximo, arr[i]);
    }
    ll seguidos = 0, masSeguidos = 0;
    forr(i, largo) {
        if (arr[i] == maximo) {
            seguidos++;
            masSeguidos = max(seguidos, masSeguidos);
        } else {
            seguidos = 0;
        }
    }
    cout << masSeguidos << endl;
}