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
    ll cant, num, ant = 0, max = 0, act = 0;
    cin >> cant;
    forr(0, cant) {
        cin >> num;
        if (num >= ant) {
            act++;
            if (act > max) {
                max = act;
            }
        } else {
            act = 1;
        }
        ant = num;
    }
    if (act > max) {
        max = act;
    }
    cout << max << '\n';
}