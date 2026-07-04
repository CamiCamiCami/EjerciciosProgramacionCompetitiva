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
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll X, Y, K;
        cin >> X >> Y >> K;
        ll saltos = 0;
        while (X != Y) {
            if (X < Y) {
                Y /= K;
            } else {
                X /= K;
            }
            saltos++;
        }
        cout << saltos << endl;
    }
}