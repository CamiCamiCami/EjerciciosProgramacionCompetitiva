#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
#define forr(d, h) for (int i = d; i < h; i++)
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

vector<bool> primos;
vector<ll> minDivisor;

ll criba(ll MAX) {
    primos.clear();
    minDivisor.clear();
    forr(0, MAX + 1) {
        primos.push_back(true);
        minDivisor.push_back(i);
    }

    primos[0] = primos[1] = false;

    ll cantPrimos = MAX;
    for (int p = 2; p * p <= MAX; p++) {
        if (!primos[p])
            continue;
        for (int d = p * p; d <= MAX; d += p) {
            if (primos[d]) {
                primos[d] = false;
                cantPrimos--;
                minDivisor[d] = p;
            }
        }
    }
    return cantPrimos;
}

int main() {
    ll N;
    cin >> N;
    criba(N);
    ll semiprimos = 0;
    forr(2, N + 1) {
        ll factor = i;
        while (factor % minDivisor[i] == 0)
            factor /= minDivisor[i];
        if (factor == 1)
            continue;
        ll otroFactor = factor;
        while (otroFactor % minDivisor[factor] == 0)
            otroFactor /= minDivisor[factor];
        if (otroFactor == 1) {
            semiprimos++;
        }
    }
    cout << semiprimos << endl;
}