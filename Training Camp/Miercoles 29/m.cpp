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
    ll n;
    cin >> n;
    int coM = 0, coC = 0;
    forr(i, n) {
        int m, c;
        cin >> m >> c;
        if (m > c) {
            coM++;
        } else if (m < c) {
            coC++;
        }
    }
    if (coM > coC) {
        cout << "Mishka" << '\n';
    } else if (coC > coM) {
        cout << "Chris" << '\n';
    } else {
        cout << "Friendship is magic!^^" << '\n';
    }
}