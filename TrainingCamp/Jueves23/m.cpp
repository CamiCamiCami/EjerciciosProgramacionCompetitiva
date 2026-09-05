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

vector<ll> arr;

ll f(ll actual, ll busca) {
    return arr[actual] < busca;
}

long long solve(long long min_val, long long max_val, ll busca) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;
    while (L <= R) {
        long long mid = L + (R - L) / 2;
        bool cumple = f(mid, busca);
        if (cumple) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        arr.clear();
        ll largo, desde, hasta;
        cin >> largo >> desde >> hasta;
        forr(i, largo) {
            ll n;
            cin >> n;
            arr.push_back(n);
        }
        sort(arr.begin(), arr.end());

        ll indices = 0;
        forr(i, largo) {
            ll valor = arr[i];
            ll repetidos = 1;
            while (i + 1 < largo && arr[i + 1] == valor) {
                i++;
                repetidos++;
            }
            if (desde <= valor + valor && valor + valor <= hasta) {
                indices += (repetidos * (repetidos - 1)) / 2;
            }

            ll desdeSuma = solve(i + 1, arr.size() - 1, desde - valor);
            if (desdeSuma == -1)
                desdeSuma = i;
            ll hastaSuma = solve(i + 1, arr.size() - 1, hasta - valor + 1);
            if (hastaSuma == -1)
                hastaSuma = i;
            indices += (hastaSuma - desdeSuma) * repetidos;
        }
        cout << indices << endl;
    }
}