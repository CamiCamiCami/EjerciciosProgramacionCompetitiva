#include <bits/stdc++.h>
#define ll long long
#define dd long double
#define ull unsigned long long
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define endl '\n'
#define initArr(arr, largo, contenido)                                                                                                               \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
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
            ll n;
            cin >> n;
            vector<ll> contador(n), array(n, -1);
            forr(i, n) { cin >> contador[i]; }

            bool imposible = false;
            forr(i, n) {
                ll elem = n - 1 - i;
                ll posDeseada = contador[elem] + i;
                if (posDeseada < 0 || posDeseada >= n || array[posDeseada] != -1) {
                    imposible = true;
                    break;
                }
                array[posDeseada] = elem;
            }
            if (imposible) {
                cout << -1 << endl;
            } else {
                for (ll e : array) {
                    cout << e + 1 << " ";
                }
                cout << endl;
            }
        }
    }
}