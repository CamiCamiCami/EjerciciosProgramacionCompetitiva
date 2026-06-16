#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

vector<ll> encontrarCamino(Grafo grafo, ll desde, ll hasta) {
    vector<ll> camino;
    stack<ll> busqueda;
    vector<bool> visitado(grafo.size(), false);
    busqueda.push(desde);
    ll actual = desde;
    while (!busqueda.empty() && actual != hasta) {
        actual = busqueda.top();
        visitado[actual] = true;
        if (!camino.empty() && camino.back() == actual) {
            busqueda.pop();
            camino.pop_back();
            continue;
        }
        camino.push_back(actual);
        for (ll vecino : grafo[actual]) {
            if (!visitado[vecino])
                busqueda.push(vecino);
        }
    }
    return camino;
}

ll subarraysEspeciales(vector<ll> array) {
    ll desde = 0, hasta = 0;
    ll xorAcc = 0, sumAcc = 0;
    ll subarrays = 0;
    while (hasta < array.size()) {
        xorAcc = xorAcc ^ array[hasta];
        sumAcc = sumAcc + array[hasta];
        while (xorAcc != sumAcc) {
            xorAcc = xorAcc ^ array[desde];
            sumAcc = sumAcc - array[desde];
            desde++;
        }
        subarrays += hasta - desde + 1;
        hasta++;
    }
    return subarrays;
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll n, queries;
        cin >> n >> queries;
        Grafo g(n + 1, vector<ll>(0));
        vector<ll> pesos;
        pesos.push_back(0);  // NO SE USA (uso indices desde 1)
        for (int i = 0; i < n; i++) {
            ll peso;
            cin >> peso;
            pesos.push_back(peso);
        }
        for (int i = 0; i < n - 1; i++) {
            ll n1, n2;
            cin >> n1 >> n2;
            g[n1].push_back(n2);
            g[n2].push_back(n1);
        }
        while (queries--) {
            ll desde, hasta;
            cin >> desde >> hasta;
            vector<ll> camino = encontrarCamino(g, desde, hasta);
            for (int i = 0; i < camino.size(); i++) {
                camino[i] = pesos[camino[i]];
            }
            cout << subarraysEspeciales(camino) << endl;
        }
    }
}