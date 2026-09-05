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

bool esNumero(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string bill;
    cin >> bill;
    bill += 'a';
    ll precio = 0, total = 0;
    ll dspComa = -1;
    for (char c : bill) {
        if (esNumero(c)) {
            precio = precio * 10 + (c - '0');
            dspComa = dspComa == -1 ? -1 : dspComa + 1;
        } else if (c == '.') {
            dspComa = dspComa == -1 ? 0 : dspComa;
        } else {
            ll shift = (dspComa % 3) == 0 || dspComa == -1 ? 100 : 1;
            total += precio * shift;
            precio = 0;
            dspComa = -1;
        }
    }

    string coma = "";
    if (total % 100 != 0) {
        coma += char((total % 10) + '0') + coma;
        total /= 10;
        coma = char((total % 10) + '0') + coma;
        total /= 10;
        coma = '.' + coma;
    } else {
        total /= 100;
    }

    string recibo = "";
    if (total == 0)
        recibo = "0";
    while (total != 0) {
        if (recibo.size() % 4 == 3) {
            recibo = '.' + recibo;
        }
        recibo = char((total % 10) + '0') + recibo;
        total /= 10;
    }
    cout << recibo << coma << endl;
}