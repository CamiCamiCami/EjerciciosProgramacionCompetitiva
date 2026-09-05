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

bool abajo(ll uno, ll cero) {
    return uno < cero;
}

long long porDebajo(vector<ll>& unos, ll cero) {
    long long L = 0;
    long long R = unos.size() - 1;
    long long ans = -1;
    while (L <= R) {
        long long mid = L + (R - L) / 2;

        if (abajo(unos[mid], cero)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    return ans;
}

bool arriba(ll cero, ll uno) {
    return uno < cero;
}

long long porEncima(vector<ll>& ceros, ll uno) {
    long long L = 0;
    long long R = ceros.size() - 1;
    long long ans = -1;
    while (L <= R) {
        long long mid = L + (R - L) / 2;

        if (arriba(ceros[mid], uno)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    return ceros.size() - 1 - ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll largo;
            cin >> largo;
            ll inversiones = 0, cunos = 0;
            vector<ll> unos, ceros;
            forr(i, largo) {
                ll num;
                cin >> num;
                if (num == 0) {
                    inversiones += cunos;
                    ceros.push_back(i);
                } else {
                    cunos++;
                    unos.push_back(i);
                }
            }

            cout << inversiones << endl;
            forr(i, largo) {
                char com;
                cin >> com;
                if (com == '1') {
                    ll subiendo = unos.front();
                }
            }
        }
    }
}