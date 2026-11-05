#include <bits/stdc++.h>
#define ll long long
#define dd long double
#define ull unsigned long long
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

#define MOD ((ull)1e9 + 7)
#define sum(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define res(a, b) (((a % MOD) - (b % MOD) + MOD) % MOD)
#define mul(a, b) (((a % MOD) * (b % MOD)) % MOD)

ull exponenciacionBinaria(ull x, ull e) {
    ull acumulador = 1;
    ull potBinaria = x;
    while (e != 0) {
        if (e & 1) {
            acumulador = mul(acumulador, potBinaria);
        }
        e = e >> 1;
        potBinaria = mul(potBinaria, potBinaria);
    }
    return acumulador;
}

ull inversoModular(ull x) { return exponenciacionBinaria(x, MOD - 2); } // MOD DEBE ser primo

ull esBueno(ull x, ull a, ull b) {
    if (x == 0) return false;
    while (x != 0) {
        if (x % 10 != a && x % 10 != b) return false;
        x /= 10;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull a, b, n;
    while (cin >> a >> b >> n) {
        vector<ull> factoriales(n + 1);
        factoriales[0] = 1;

        forrr(i, 1, n + 1) factoriales[i] = mul(factoriales[i - 1], i);
        ull nFact = factoriales[n];
        forr(i, n + 1) factoriales[i] = inversoModular(factoriales[i]);

        ull pos = 0;
        forr(k, n + 1) {
            ull suma = a * k + b * (n - k);
            if (!esBueno(suma, a, b)) continue;
            pos = sum(mul(mul(nFact, factoriales[k]), factoriales[n - k]), pos);
        }
        cout << pos << endl;
    }
}