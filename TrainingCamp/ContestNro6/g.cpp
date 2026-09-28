#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
            if (k % 2 == 0) {
                if (n - k + 1 > 0) {
                    cout << "YES" << endl;
                    forr(i, k - 1) cout << 1 << " ";
                    cout << n - k + 1 << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                if (n - (k - 1) * 2 > 0) {
                    cout << "YES" << endl;
                    forr(i, k - 1) cout << 2 << " ";
                    cout << n - (k - 1) * 2 << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        } else {
            if (k % 2 == 0) {
                cout << "NO" << endl;
            } else {
                if (n - k + 1 > 0) {
                    cout << "YES" << endl;
                    forr(i, k - 1) cout << 1 << " ";
                    cout << n - k + 1 << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
}