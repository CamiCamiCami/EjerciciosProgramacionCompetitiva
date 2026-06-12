#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define vector std::vector
#define map std::map
#define set std::set
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

#define div(n, x) (n / x)
#define res(n, x) (n % x)

ll movimientos(ll a, ll b, ll x) {
    if (a == b) {
        return 0;
    }
    ll dist = (a - b) > 0 ? a - b : b - a;
    if (div(a, x) < div(b, x)) {
        ll mov = movimientos(a, div(b, x), x);
        return min(mov + 1, dist);
    } else if (div(a, x) > div(b, x)) {
        ll mov = movimientos(div(a, x), b, x);
        return min(mov + 1, dist);
    } else {
        return min(dist, 2);
    }
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll a, b, x;
        cin >> a >> b >> x;
        cout << movimientos(a, b, x) << endl;
    }
}