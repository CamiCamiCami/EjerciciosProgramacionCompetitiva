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
#define abs(n) ((n) < 0 ? -(n) : (n))
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

int main() {
    ll N;
    cin >> N;
    ll alturas[100000];
    ll parciales[100000];
    initArr(parciales, N, 0);
    for (ll i = 0; i < N; i++) {
        cin >> alturas[i];
    }
    parciales[N - 2] = abs(alturas[N - 1] - alturas[N - 2]);
    for (ll i = N - 3; i >= 0; i--) {
        ll opcion1 = parciales[i + 1] + abs(alturas[i] - alturas[i + 1]);
        ll opcion2 = parciales[i + 2] + abs(alturas[i] - alturas[i + 2]);
        parciales[i] = opcion1 < opcion2 ? opcion1 : opcion2;
    }
    cout << parciales[0] << endl;
}
