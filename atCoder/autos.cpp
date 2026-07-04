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
    ll X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;
    ll suma = 0;
    for (int i = 0; i < 24; i++) {
        if (A <= i && i < B) {
            if (L <= i && i < R) {
                suma += X;
            } else {
                suma += Y;
            }
        }
    }
    cout << suma << endl;
}