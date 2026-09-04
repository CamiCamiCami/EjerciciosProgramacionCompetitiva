#include <algorithm>
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

ll maxSumSubarrK(vector<ll> vec, ll k) {
    ll suma = 0;
    forr(i, k) {
        suma += vec[i];
    }
    ll maxSuma = suma;
    forrr(i, k, vec.size()) {
        suma = suma - vec[i - k] + vec[i];
        maxSuma = max(maxSuma, suma);
    }
    return maxSuma;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    while (cin >> n) {
        cin >> k;
        vector<ll> vec;
        forr(i, n) {
            ll num;
            cin >> num;
            vec.push_back(num);
        }
        double suma = 0;
        forrr(i, k, n + 1) {
            suma = max(suma, ((double)maxSumSubarrK(vec, i)) / ((double)i));
        }
        cout << fixed << setprecision(15) << suma << endl;
    }
}