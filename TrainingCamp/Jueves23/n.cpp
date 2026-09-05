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
    ll cant;
    cin >> cant;
    vector<ll> orig, ord;
    ll num;
    forr(0, cant) {
        cin >> num;
        orig.push_back(num);
        ord.push_back(num);
    }
    sort(ord.begin(), ord.end());
    ll distintos = 0;
    forr(0, cant) {
        if (ord[i] != orig[i]) {
            distintos++;
        }
    }
    if (distintos > 2) {
        cout << "NO" << '\n';

    } else {
        cout << "YES" << '\n';
    }
}