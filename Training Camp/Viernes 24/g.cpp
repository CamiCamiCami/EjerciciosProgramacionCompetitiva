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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;

    for (int j = 0; j < casos; j++) {
        int n;
        cin >> n;
        ll ini = 1, ant = 0;
        int rego, murio = 0;

        for (int i = 0; i < n; i++) {
            cin >> rego;
            if (rego) {
                if (ant) {
                    ini += 5;
                } else {
                    ini += 1;
                }
            } else if (!ant && i > 0) {
                murio = 1;
            }
            ant = rego;
        }
        cout << (murio ? -1 : ini) << '\n';
    }
}