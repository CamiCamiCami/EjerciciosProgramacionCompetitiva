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
    ll n;
    cin >> n;
    ll cod = n % 2 == 0 ? (n * n) / 2 : ((n * n) / 2) + 1;
    char ant = '.';
    cout << cod << '\n';
    for (int i = 0; i < n; i++) {
        ant = (i % 2 == 0 ? '.' : 'C');
        for (int j = 0; j < n; j++) {
            if (ant == '.') {
                cout << 'C';
                ant = 'C';
            } else {
                cout << '.';
                ant = '.';
            }
        }
        cout << '\n';
    }
}