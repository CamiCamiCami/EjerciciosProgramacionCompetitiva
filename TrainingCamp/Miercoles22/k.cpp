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
    int n;
    cin >> n;
    int k = n - 10;
    int ochos = 0;
    for (int i = 0; i < k; i++) {
        char numchar;
        cin >> numchar;
        if (numchar == '8') {
            ochos++;
        }
    }
    cin >> n;
    if ((ochos - (k / 2)) > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}