#include <algorithm>
#include <bitset>
#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned long long
#define dd long double
#define forr(i, h) for (ull i = 0; i < h; i++)
#define forrr(i, d, h) for (ull i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define endl '\n'
#define initArr(arr, largo, contenido)                                                                                                               \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ull, ull>;
using GrafoPesado = vector<vector<pair<ull, ull>>>;
using Grafo = vector<vector<ull>>;
using Digrafo = vector<vector<pair<ull, bool>>>;
using Arbol = vector<vector<ull>>;
using Potencias = ull;

ull random64() {
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    return rng();
}

vector<bool> primos;
vector<ull> minDivisor;
map<ull, ull> hashPrimo;
ull criba(ull MAX) {
    primos.clear();
    minDivisor.clear();
    forr(i, MAX + 1) {
        primos.push_back(true);
        minDivisor.push_back(i);
    }

    primos[0] = primos[1] = false;

    ull cantPrimos = 0;
    for (ull p = 2; p <= MAX; p++) {
        if (!primos[p]) continue;
        hashPrimo[p] = random64();
        cantPrimos++;
        for (ull d = p * p; d <= MAX; d += p) {
            if (primos[d]) {
                primos[d] = false;
                minDivisor[d] = p;
            }
        }
    }
    return cantPrimos;
}

Potencias paridades(ull num) {
    if (num == 1) {
        return 0;
    } else {
        ull menorDivisor = minDivisor[num];
        Potencias p = paridades(num / menorDivisor);
        return p ^ hashPrimo[menorDivisor];
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    criba(1e6);
    ull casos;
    while (cin >> casos) {
        while (casos--) {
            ull cajas;
            cin >> cajas;
            vector<Potencias> juntos;
            map<Potencias, ull> contador;
            forr(i, cajas) {
                ull fuerza;
                cin >> fuerza;
                Potencias p = paridades(fuerza);
                contador[p] = (contador.count(p) == 0 ? 1 : contador[p] + 1);
                juntos.push_back((i == 0 ? p : juntos[i - 1] ^ p));
            }
            ull formas = 0;
            for (Potencias p : juntos) {
                if (contador.count(p)) formas += contador[p];
            }
            cout << formas << endl;
        }
    }
}