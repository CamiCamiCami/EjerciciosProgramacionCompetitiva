#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

vector<ll> sumasPrefijas;
ll sumaArr;
ll largo;

ll calcularHasta(ll idx) {
    ll corrimiento = idx / largo;
    ll posSubarr = idx % largo;
    ll posOriginal = (posSubarr + corrimiento) % largo;
    ll extra = sumaArr * corrimiento;
    ll sumaSubarr;
    if (posOriginal < posSubarr)
        sumaSubarr = sumaArr - (sumasPrefijas[posOriginal + largo - posSubarr] - sumasPrefijas[posOriginal]);
    else
        sumaSubarr = sumasPrefijas[posOriginal] - sumasPrefijas[posOriginal - posSubarr];
    ll suma = extra + sumaSubarr;
    return suma;
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll queries;
        cin >> largo >> queries;
        sumasPrefijas.push_back(0);
        for (int i = 0; i < largo; i++) {
            ll val;
            cin >> val;
            sumasPrefijas.push_back(sumasPrefijas.back() + val);
        }
        sumaArr = sumasPrefijas[largo];
        while (queries--) {
            ll desde, hasta;
            cin >> desde >> hasta;
            ll suma = calcularHasta(hasta) - calcularHasta(desde - 1);
            cout << suma << endl;
        }
        sumasPrefijas.clear();
    }
}