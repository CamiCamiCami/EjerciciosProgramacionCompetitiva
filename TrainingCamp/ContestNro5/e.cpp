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
    string inicial, buscado;
    cin >> inicial >> buscado;
    map<char, ll> apariciones, enBuscado;
    forrr(c, 'a', 'z' + 1) {
        apariciones[c] = 0;
        enBuscado[c] = 0;
    }
    ll idxBuscado = 0;
    for (char c : inicial) {
        if (idxBuscado != buscado.size() && buscado[idxBuscado] == c)
            idxBuscado++;
        apariciones[c]++;
    }
    if (idxBuscado == buscado.size()) {
        cout << "automaton" << endl;
        return 0;
    }
    for (char c : buscado) {
        enBuscado[c]++;
    }
    bool soloArray = true, ambos = true;
    forrr(c, 'a', 'z' + 1) {
        soloArray = soloArray && apariciones[c] == enBuscado[c];
        ambos = ambos && apariciones[c] >= enBuscado[c];
    }
    if (soloArray) {
        cout << "array" << endl;
    } else if (ambos) {
        cout << "both" << endl;
    } else {
        cout << "need tree" << endl;
    }
}