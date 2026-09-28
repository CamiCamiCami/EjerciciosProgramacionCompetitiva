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

#define MOD 10
#define sum(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define res(a, b) (((a % MOD) - (b % MOD) + MOD) % MOD)
#define mul(a, b) (((a % MOD) * (b % MOD)) % MOD)

int main() {
    ll a, b;
    cin >> a >> b;
    if (b - a >= 10) {
        cout << 0 << endl;

    } else {
        ll prodMod = 1;
        for (int i = 1; a + i <= b; i++) {
            prodMod = mul(prodMod, sum(a, i));
        }
        cout << prodMod << endl;
    }
}