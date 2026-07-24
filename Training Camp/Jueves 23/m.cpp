#include <algorithm>
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

bool f1(long long x, ll n, ll l, vector<ll> v) {

    return (n + v[x]) >= l;
};

bool f2(long long x, ll n, ll r, vector<ll> v) {

    return (n + v[x]) > r;
};

long long solve(long long min_val, long long max_val, ll n, ll l, vector<ll> v) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;  // Guarda la mejor respuesta encontrada hasta ahora
    while (L <= R) {
        // L + (R - L) / 2 previene overflow que pasaría si usas (L + R) / 2
        long long mid = L + (R - L) / 2;

        if (f1(mid, n, l, v)) {
            ans = mid;    // mid es válido, lo guardamos como posible respuesta
            R = mid - 1;  // Como queremos el menor valor, buscamos más a la izquierda
        } else {
            L = mid + 1;  // mid no es válido (dio false), buscamos a la derecha
        }
    }

    return ans;  // Al final del ciclo, 'ans' tiene el primer 'true'
}

long long solve2(long long min_val, long long max_val, ll n, ll l, vector<ll> v) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;  // Guarda la mejor respuesta encontrada hasta ahora
    while (L <= R) {
        // L + (R - L) / 2 previene overflow que pasaría si usas (L + R) / 2
        long long mid = L + (R - L) / 2;

        if (f2(mid, n, l, v)) {
            ans = mid;    // mid es válido, lo guardamos como posible respuesta
            R = mid - 1;  // Como queremos el menor valor, buscamos más a la izquierda
        } else {
            L = mid + 1;  // mid no es válido (dio false), buscamos a la derecha
        }
    }

    return ans - 1;  // Al final del ciclo, 'ans' tiene el primer 'true'
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> nums;
        ll num;
        forr(0, n) {
            cin >> num;
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        nums.push_back(r);
        ll min = 1, izq, der;
        ll max = n + 1;
        ll suma = 0;
        bool terminar = false;
        for (int i = 0; i < n && !terminar; i++) {
            izq = solve(min, max, nums[i], l, nums);
            der = solve2(min, max, nums[i], r, nums);
            if (izq < 0 || der < 0) {
                terminar = true;
            } else if (izq <= der) {
                suma += (der - izq + 1);
            }
            min++;
            max = der + 1;
        }
        cout << suma << '\n';
    }
}