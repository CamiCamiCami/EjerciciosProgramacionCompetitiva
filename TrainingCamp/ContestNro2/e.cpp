#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#define ll int
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

ll largo, dosAlaLargo;
vector<vector<ll>> matrices;
vector<ll> binarios;

void comoBinarios(ll maximo) {
    binarios.clear();
    for (vector<ll>& a : matrices) {
        ll valor = 0;
        for (ll e : a) {
            if (e >= maximo)
                valor++;
            valor = valor << 1;
        }
        valor = valor >> 1;
        binarios.push_back(valor);
    }
}

#define niega(bin) ((bin) ^ (dosAlaLargo - 1))
#define acepta(mascara, bin) (niega(niega(mascara) | (bin)))

ll indice1, indice2;

bool f(long long maximo) {
    comoBinarios(maximo);
    unordered_map<int, bool> cubierto;
    forr(i, dosAlaLargo) {
        cubierto[i] = false;
    }
    bool match = false;
    forr(i, binarios.size()) {
        ll bin = binarios[i];
        ll necesita = niega(bin);
        if (cubierto[necesita]) {
            match = true;
            indice1 = i;
            break;
        }
        forr(mascara, dosAlaLargo) {
            if (acepta(mascara, bin) == 0) {
                cubierto[mascara] = true;
            }
        }
    }
    return match;
}

long long solve(long long min_val, long long max_val) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;
    while (L <= R) {
        long long mid = L + (R - L) / 2;
        bool cumple = f(mid);
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
    ll cantidadMatrices;
    cin >> cantidadMatrices >> largo;
    dosAlaLargo = 1;
    forr(i, largo) {
        dosAlaLargo *= 2;
    }
    forr(i, cantidadMatrices) {
        vector<ll> matriz(largo);
        forr(j, largo) {
            cin >> matriz[j];
        }
        matrices.push_back(matriz);
    }

    ll maxMinMax = solve(0, 1e9 + 5);
    comoBinarios(maxMinMax);
    ll mascaraBuscada = niega(binarios[indice1]);
    forr(i, binarios.size()) {
        ll bin = binarios[i];
        if (acepta(mascaraBuscada, bin) == 0) {
            indice2 = i;
            break;
        }
    }

    cout << indice1 + 1 << ' ' << indice2 + 1 << endl;
}