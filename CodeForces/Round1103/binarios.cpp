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
        ll largo, modulo;
        cin >> largo >> modulo;
        bool bitsPar[modulo];
        initArr(bitsPar, modulo, false) for (int i = 0; i < largo; i++) {
            char bit;
            cin >> bit;
            if (bit == '1')
                bitsPar[i % modulo] = !bitsPar[i % modulo];
        }
        bool posible = true;
        for (int i = 0; i < modulo; i++) {
            if (bitsPar[i]) {
                posible = false;
                break;
            }
        }
        cout << (posible ? "YES" : "NO") << endl;
    }
}