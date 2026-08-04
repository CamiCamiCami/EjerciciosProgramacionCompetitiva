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
        ll largo;
        vector<ll> array;
        set<ll> sombras;
        map<ll, ll> cantidad, identidad;
        cin >> largo;
        bool hayCero = false;
        forr(i, largo) {
            ll num;
            cin >> num;
            array.push_back(num);
            if (num == 0)
                hayCero = true;
            if (sombras.count(num) == 1) {
                cantidad[num]++;
            } else {
                sombras.insert(num);
                cantidad[num] = 1;
            }
        }

        vector<ll> sombrasOrd;
        for (ll sombra : sombras) {
            sombrasOrd.push_back(sombra);
        }
        ll sumaAcc = 0;
        bool noSePuede = false;
        ll ultimo = 0;
        forrr(i, 1, sombrasOrd.size()) {
            ll sombraVelado = sombrasOrd[i - 1];
            ll sombraSig = sombrasOrd[i];
            ll totalVelados = sombraSig - sombraVelado;
            ll cantVelados = cantidad[sombraVelado];
            if (totalVelados % cantVelados != 0 || (totalVelados / cantVelados) <= ultimo) {
                noSePuede = true;
                break;
            }
            identidad[sombraVelado] = totalVelados / cantVelados;
            ultimo = identidad[sombraVelado];
        }
        if (noSePuede || !hayCero) {
            cout << -1 << endl;
        } else {
            identidad[sombrasOrd.back()] = ultimo + 1;
            for (ll e : array) {
                cout << identidad[e] << ' ';
            }
            cout << endl;
        }
    }
}