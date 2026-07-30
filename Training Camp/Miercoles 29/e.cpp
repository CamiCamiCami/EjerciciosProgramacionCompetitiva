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
    int cantChicos, cantChicas, num;
    vector<int> chicos, chicas;
    cin >> cantChicos;
    forr(i, cantChicos) {
        cin >> num;
        chicos.push_back(num);
    }
    cin >> cantChicas;
    forr(i, cantChicas) {
        cin >> num;
        chicas.push_back(num);
    }
    sort(chicos.begin(), chicos.end());
    sort(chicas.begin(), chicas.end());
    int ultimo = 0, parejas = 0;
    bool terminar = false;
    for (int i = 0; i < cantChicas; i++) {
        terminar = false;
        for (int j = ultimo; j < cantChicos && !terminar; j++) {
            if ((chicos[j] - chicas[i]) <= 1 && (chicos[j] - chicas[i]) >= -1) {
                parejas++;
                terminar = true;
                ultimo = j + 1;
            }
        }
    }
    cout << parejas << '\n';
}