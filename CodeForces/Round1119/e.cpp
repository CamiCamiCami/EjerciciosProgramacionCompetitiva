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
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll largo;
            cin >> largo;
            vector<ll> mapa(largo), roto(largo);
            vector<ll> inicios, fines;
            forr(i, largo) {
                cin >> roto[i];
                if (roto[i] == 0)
                    mapa[i] = 1;
                else if (roto[i] == -1)
                    mapa[i] = -1;
                else {
                    inicios.push_back(i - roto[i] + 1);
                    fines.push_back(i + roto[i] - 1);
                    mapa[i] = 0;
                }
            }
            sort(inicios.begin(), inicios.end());
            sort(fines.begin(), fines.end());
            ll cini = 0, cfin = 0, abiertos = 0;
            bool posible = true;
            forr(i, largo) {
                while (cini < inicios.size() && inicios[cini] <= i) {
                    cini++;
                    abiertos++;
                }
                if (abiertos != 0) {
                    posible = posible && mapa[i] != 1;
                    mapa[i] = 0;
                } else {
                    mapa[i] = mapa[i] == -1 ? 1 : mapa[i];
                }
                while (cfin < fines.size() && fines[cfin] <= i) {
                    cfin++;
                    abiertos--;
                }
            }
            forr(i, largo) {
                if (roto[i] == -1)
                    continue;
                ll inf = i - roto[i], sup = i + roto[i];
                posible = posible && ((inf >= 0 && mapa[inf] == 1) || (sup < largo && mapa[sup] == 1));
            }
            if (!posible) {
                cout << -1 << endl;
            } else {
                for (ll e : mapa) {
                    cout << e;
                }
                cout << endl;
            }
        }
    }
}