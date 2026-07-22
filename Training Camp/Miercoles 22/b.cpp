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

ll cumple(vector<ll> array, ll aPoner) {
    ll maximaDistancia = 0;
    for (ll i = 0; i < array.size(); i++) {
        ll num = array[i];
        ll esperado = num - aPoner;
        ll distancia = esperado - i + 1;
        maximaDistancia = maximaDistancia > distancia ? distancia : maximaDistancia;
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
        if (num == 1) {
            encontro1 = i;
            enOrden = true;
        }
        if (!encontro1)
            preArray.push_back(num);
        if (encontro1) {
            enOrden = (num == i - encontro1 + 1);
            posArray.push_back(num);
        }
        array.push_back(num);
    }

    if (enOrden) {
        ll maxDist = cumple(preArray, array.back() + 1);
        if (maxDist == 0) {
            cout << array.size() - posArray.size() << '\n';
            return 0;
        }
    }
    if (encontro1) {
        ll movimientos = encontro1;
        movimientos += cumple(posArray, 1);
        cout << movimientos + array.size() << '\n';
    } else {
        ll movimientos = cumple(array, 1);
        cout << movimientos + array.size() << '\n';
    }
}