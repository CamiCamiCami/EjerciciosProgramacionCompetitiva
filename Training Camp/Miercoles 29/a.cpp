#include <algorithm>
#include <cmath>
#include <iomanip>
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
    dd conejos;
    dd alturaTotal;
    cin >> conejos;
    cin >> alturaTotal;
    dd areaBuscada = (alturaTotal) / conejos;
    dd areaAcc = 0;
    vector<dd> cortes;
    forr(i, conejos - 1) {
        dd altCuadrado = (areaBuscada + areaAcc) * alturaTotal;
        dd altura = sqrt(altCuadrado);
        cortes.push_back(altura);
        areaAcc = altura * altura * (1.0 / alturaTotal);
    }
    for (dd corte : cortes) {
        cout << fixed << setprecision(13) << corte << ' ';
    }
    cout << endl;
}