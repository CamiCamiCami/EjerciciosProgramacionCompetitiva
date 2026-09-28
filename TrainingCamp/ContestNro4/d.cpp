#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
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

#define in2formato(f) (f == 2 ? -1 : 1)
#define signo(n) (n == 0 ? 0 : (n > 0 ? n : -n) / n)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll frascos;
        cin >> frascos;
        vector<ll> difIzq(frascos), difDer(frascos);
        forr(i, frascos) {
            cin >> difIzq[frascos - i - 1];
        }
        forr(i, frascos) {
            cin >> difDer[i];
        }
        difDer[0] = in2formato(difDer[0]);
        difIzq[0] = in2formato(difIzq[0]);
        forrr(i, 1, frascos) {
            difDer[i] = in2formato(difDer[i]) + difDer[i - 1];
            difIzq[i] = in2formato(difIzq[i]) + difIzq[i - 1];
        }
        ll buscado = difDer[frascos - 1] + difIzq[frascos - 1];
        if (buscado == 0) {
            cout << 0 << endl;
            continue;
        }
        set<ll> vistosIzq, vistosDer;
        vistosDer.insert(0);
        vistosIzq.insert(0);
        map<ll, ll> posIzq, posDer;
        posIzq[0] = posDer[0] = 0;
        ll resultado = 10E9;
        for (ll i = 0; i < frascos; i++) {
            bool derInteresante = signo(difDer[i]) == signo(buscado);
            bool izqInteresante = signo(difIzq[i]) == signo(buscado);
            if (derInteresante) {
                if (vistosDer.count(difDer[i]) == 0) {
                    posDer[difDer[i]] = i + 1;
                    vistosDer.insert(difDer[i]);
                }
            }
            if (izqInteresante) {
                if (vistosIzq.count(difIzq[i]) == 0) {
                    posIzq[difIzq[i]] = i + 1;
                    vistosIzq.insert(difIzq[i]);
                }
            }
            if (derInteresante) {
                ll necesita = buscado - difDer[i];
                if (vistosIzq.count(necesita) > 0) {
                    ll posibleRes = i + 1 + posIzq[necesita];
                    resultado = resultado > posibleRes ? posibleRes : resultado;
                }
            }
            if (izqInteresante) {
                ll necesita = buscado - difIzq[i];
                if (vistosDer.count(necesita) > 0) {
                    ll posibleRes = (i + 1 + posDer[necesita]);
                    resultado = resultado > posibleRes ? posibleRes : resultado;
                }
            }
        }

        cout << resultado << endl;
    }
}