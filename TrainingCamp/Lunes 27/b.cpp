#include <algorithm>
#include <bitset>
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

#define negar(bin) (((1 << 11) - 1) ^ (bin))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll acciones;
    cin >> acciones;
    int estado = 0;
    forr(i, acciones) {
        char acc;
        cin >> acc;
        if (acc == 'L') {
            int mascara = 1 << 9;
            while ((mascara & negar(estado)) == 0)
                mascara = mascara >> 1;
            estado = mascara | estado;
        } else if (acc == 'R') {
            int mascara = 1;
            while ((mascara & negar(estado)) == 0)
                mascara = mascara << 1;
            estado = mascara | estado;
        } else {
            int shift = 9 - (acc - '0');
            int mascara = 1 << shift;
            estado = estado & negar(mascara);
        }
    }
    for (int i = 9; i >= 0; i--) {
        int prendido = (estado >> i);
        prendido = 1 & prendido;
        cout << (prendido == 0 ? 0 : 1);
    }
    cout << endl;
}