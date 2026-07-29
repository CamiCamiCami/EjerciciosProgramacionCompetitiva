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

bool f(int x, vector<int>& v, int busc) {
    return v[x] <= (v[busc] + 2);
}

int solve(int min_val, int max_val, vector<int>& v, int busc) {
    int L = min_val;
    int R = max_val;
    int ans = -1;
    while (L <= R) {

        int mid = L + (R - L) / 2;

        if (f(mid, v, busc)) {
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
        int n;
        cin >> n;
        vector<int> v(n);
        forr(i, n) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll suma = 0;
        forr(i, n) {
            int ind = solve(i, n - 1, v, i);
            if (ind > i + 1) {
                suma += ((ind - i) * (ind - i - 1)) / 2;
            }
        }
        cout << suma << '\n';
    }
}