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
#define endl '\n'
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll documentos;
            cin >> documentos;
            vector<bool> impreso(documentos, false);
            ll impresos = 0;
            stack<ll> memoria;
            forr(i, documentos) {
                char instruccion;
                cin >> instruccion;
                if (instruccion == '1') {
                    memoria.push(i);
                } else if (instruccion == '2' && !memoria.empty()) {
                    if (!impreso[memoria.top()]) impresos++;
                    impreso[memoria.top()] = true;
                    memoria.pop();
                } else {
                    if (!impreso[i]) impresos++;
                    impreso[i] = true;
                }
            }
            cout << documentos - impresos << endl;
            forr(i, documentos) {
                if (impreso[i]) continue;
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    }
}