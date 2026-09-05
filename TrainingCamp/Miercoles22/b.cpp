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

ll lleganEnTiempo(vector<ll> array, ll aPoner) {
    ll maximaDistancia = 0;
    for (ll i = 0; i < array.size(); i++) {
        if (array[i] == 0)
            continue;
        ll num = array[i];
        ll esperado = num - aPoner;
        ll distancia = i - esperado + 1;
        maximaDistancia = maximaDistancia > distancia ? maximaDistancia : distancia;
    }
    return maximaDistancia;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cant;
    cin >> cant;
    int num, ceros = 0;
    for (int i = 0; i < cant; i++) {
        cin >> num;
    }
    vector<ll> preArray, array, posArray;
    ll encontro1 = 0;
    ll enOrden = false;
    for (int i = 1; i <= cant; i++) {
        cin >> num;
        if (encontro1) {
            enOrden = enOrden && (num == i - encontro1 + 1);
            posArray.push_back(num);
        }
        if (num == 1) {
            encontro1 = i;
            enOrden = true;
        }
        if (!encontro1)
            preArray.push_back(num);

        array.push_back(num);
    }

    if (enOrden) {
        ll maxDist = lleganEnTiempo(preArray, array.back() + 1);
        if (maxDist == 0) {
            cout << preArray.size() << '\n';
            return 0;
        }
    }

    ll movimientos = array.size();
    if (encontro1) {
        movimientos += encontro1;
        movimientos += lleganEnTiempo(posArray, 1);
        cout << movimientos << '\n';
    } else {
        movimientos += lleganEnTiempo(array, 1);
        cout << movimientos << '\n';
    }
}