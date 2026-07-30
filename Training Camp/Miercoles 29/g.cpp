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
    int casos, r = 0, g = 0, b = 0;
    char letra;
    cin >> casos;
    while (casos--) {
        cin >> letra;
        if (letra == 'R') {
            r++;
        }
        if (letra == 'G') {
            g++;
        }
        if (letra == 'B') {
            b++;
        }
    }
    if ((g >= 1 && r >= 1) || (b >= 1 && (g + r) > 1) || (b - g - r) == b) {
        cout << 'B';
    }
    if ((r >= 1 && b >= 1) || (g >= 1 && (r + b) > 1) || (g - r - b) == g) {
        cout << 'G';
    }
    if ((g >= 1 && b >= 1) || (r >= 1 && (g + b) > 1) || (r - g - b) == r) {
        cout << 'R';
    }
    cout << '\n';
}