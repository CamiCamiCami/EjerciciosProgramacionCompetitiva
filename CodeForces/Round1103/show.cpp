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
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll n, k;
        cin >> n >> k;
        map<ll, ll> frecuencias;
        for (ll i = 0; i < n; i++) {
            ll num;
            cin >> num;
            if (frecuencias.count(num) == 0)
                frecuencias[num] = 0;
            frecuencias[num]++;
        }
        vector<ll> subarray;
        bool puedeGanar = false;
        auto iter = frecuencias.begin();
        ll anterior = iter->first;
        while (!puedeGanar && iter != frecuencias.end()) {
            ll valor = iter->first;
            ll frecuencia = iter->second;
            if (!(valor <= anterior + k)) {
                puedeGanar = (subarray.back() % 2L == 0L) || (subarray.size() > 1);
                subarray.clear();
            }
            subarray.push_back(frecuencia);
            anterior = valor;
            iter++;
        }
        puedeGanar = puedeGanar || (subarray.back() % 2L == 0L) || (subarray.size() > 1);
        cout << (puedeGanar ? "YES" : "NO") << endl;
    }
}