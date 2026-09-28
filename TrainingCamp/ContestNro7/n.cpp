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
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        string s;
        ll largo;
        cin >> largo;
        cin >> s;
        char min = 'z' + 1;
        ll minIdx;
        forr(i, largo) {
            if (s[i] <= min) {
                min = s[i];
                minIdx = i;
            }
        }
        s[minIdx] = '.';
        s = min + s;
        for (char c : s) {
            if (c == '.')
                continue;
            cout << c;
        }
        cout << endl;
    }
}