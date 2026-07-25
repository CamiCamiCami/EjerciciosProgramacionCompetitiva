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
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo;
        cin >> largo;
        vector<ll> arr;
        forr(0, largo) {
            ll num;
            cin >> num;
            arr.push_back(num);
        }

        ll pivotes = 0;
        ll mayor = 0;
        for (ll i = largo - 1; i >= 0; i--) {
            if (arr[i] > mayor) {
                mayor = arr[i];
                pivotes++;
            }
        }
        cout << pivotes - 1 << '\n';
    }
}