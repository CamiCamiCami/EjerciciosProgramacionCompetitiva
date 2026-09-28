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

int main() {
    ll x, y, z;
    cin >> x >> y >> z;
    if (x > y + z) {
        cout << "+" << endl;
    } else if (y > x + z) {
        cout << "-" << endl;
    } else if (x == y && z == 0) {
        cout << "0" << endl;
    } else {
        cout << "?" << endl;
    }
}