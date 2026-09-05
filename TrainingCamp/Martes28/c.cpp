#include <algorithm>
#include <deque>
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
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo;
        string cadena;
        cin >> largo;
        cin >> cadena;
        deque<ll> Ts;
        bool noPudo = false;
        forr(i, largo) {
            if (cadena[i] == 'T') {
                Ts.push_back(i);
            } else {
                if (Ts.empty()) {
                    noPudo = true;
                    break;
                } else {
                    Ts.pop_front();
                }
            }
        }
        if (noPudo) {
            cout << "NO" << endl;
            continue;
        }
        for (ll i = largo - 1; i >= 0; i--) {
            if (cadena[i] == 'T')
                continue;
            if (Ts.empty() || Ts.back() < i) {
                noPudo = true;
                break;
            } else {
                Ts.pop_back();
            }
        }
        if (noPudo || !Ts.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}