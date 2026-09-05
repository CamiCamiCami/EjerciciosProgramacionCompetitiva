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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n < 4) {
        cout << "NO" << '\n';
    } else if (n == 5) {
        cout << "YES\n5 - 1 = 4\n4 - 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    } else if (n == 4) {
        cout << "YES\n2 * 3 = 6\n6 * 4 = 24\n1 * 24 = 24\n";
    } else {
        cout << "YES\n6 - 1 = 5\n5 - 5 = 0\n";
        for (int i = 7; i <= n; i++) {
            cout << "0 * " << i << " = 0\n";
        }
        cout << "2 * 3 = 6\n6 * 4 = 24\n0 + 24 = 24\n";
    }
}