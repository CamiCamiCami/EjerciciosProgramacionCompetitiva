#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ull unsigned long long
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

bool f(ull iteracion, ull y, int bit) {
    y += iteracion;
    return (y >> bit) == 1;
};

ll solve(ull y, ull x, int bit) {
    ll L = 0;
    ll R = x;
    ll ans = -1;
    while (L <= R) {

        ll mid = L + (R - L) / 2;

        if (f(mid, y, bit)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    return ans;
}

int bitSignificativo(ull n) {
    int bit = 0;
    for (; n >> bit; bit++)
        ;
    bit--;
    return bit;
}

ll enCuantos(ull x, ull y) {
    if (x == 0)
        return 0;
    ull suma = x + y;
    int bit = bitSignificativo(suma);
    if (y >> bit == 1) {
        y -= 1 << bit;
        return enCuantos(x, y);
    } else if (x >> bit == 1) {
        x -= 1 << bit;
        return enCuantos(x, y);
    } else {
        return solve(y, x, bit);
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull casos;
    while (cin >> casos) {
        while (casos--) {
            ull x, y;
            cin >> x >> y;
            cout << x + y << " " << enCuantos(x, y) << endl;
        }
    }
}