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
    bool esPrimo = true;
    ll divisorPrimo = 0;
    string respuesta;
    for (int primo : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}) {
        cout << primo << endl;
        fflush(stdout);
        cin >> respuesta;
        if (respuesta == "yes") {
            if (divisorPrimo != 0) {
                esPrimo = false;
                break;
            } else if (primo >= 11) {
                break;
            }
            divisorPrimo = primo;
        }
    }
    if (!esPrimo) {
        cout << "composite" << endl;
    } else if (divisorPrimo == 0) {
        cout << "prime" << endl;
    } else {
        cout << divisorPrimo * divisorPrimo << endl;
        fflush(stdout);
        cin >> respuesta;
        cout << (respuesta == "no" ? "prime" : "composite") << endl;
    }
    fflush(stdout);
}
