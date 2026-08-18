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

bool primos[1000005];
ll minDivisor[1000005];
#define MAX 1000000

ll criba() {
    forr(i, MAX + 1) {
        primos[i] = true;
        minDivisor[i] = i;
    }

    primos[0] = primos[1] = true;

    ll cantPrimos = MAX;
    for (int p = 2; p * p <= MAX; p++) {
        if (!primos[p])
            continue;
        for (int d = p * p; d <= MAX; d += p) {
            if (primos[d]) {
                primos[d] = false;
                cantPrimos--;
                minDivisor[d] = p;
            }
        }
    }
    return cantPrimos;
}

bool multiplesFactores(ll numero) {
    if (primos[numero])
        return false;
    ll factor = minDivisor[numero];
    numero /= factor;
    while (!primos[numero]) {
        if (minDivisor[numero] != factor)
            return true;
        numero /= factor;
    }
    return numero != factor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    criba();
    while (casos--) {
        ll cant;
        cin >> cant;
        ll anterior = 0, num = 0;
        bool decrece = false;
        bool muchosFactores = false;
        bool factoresDecrece = false;
        forr(i, cant) {
            anterior = num;
            cin >> num;
            decrece = decrece || anterior > num;
            muchosFactores = muchosFactores || multiplesFactores(num);
            factoresDecrece = factoresDecrece || minDivisor[anterior] > minDivisor[num];
        }
        if (!decrece) {
            cout << "Bob" << endl;
        } else if (muchosFactores) {
            cout << "Alice" << endl;
        } else if (!factoresDecrece) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}