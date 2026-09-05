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

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        string p, h;
        cin >> p >> h;
        ll pl = p.length(), hl = h.length();
        map<char, ll> buscado, apariciones;
        for (char c = 'a'; c <= 'z'; c++) {
            buscado[c] = apariciones[c] = 0;
        }
        for (char c : p) {
            buscado[c]++;
        }
        forr(0, pl) {
            apariciones[h[i]]++;
        }
        bool aceptado = false;
        for (int i = 0; i <= hl - pl && !aceptado; i++) {
            aceptado = true;
            for (char c = 'a'; c <= 'z'; c++) {
                aceptado = aceptado && buscado[c] == apariciones[c];
            }
            apariciones[h[i]]--;
            apariciones[h[pl + i]]++;
        }
        cout << (aceptado ? "YES\n" : "NO\n");
    }
}