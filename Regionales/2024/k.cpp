#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)

using namespace std;
using Arbol = vector<vector<pair<ll, ll>>>;

int main() {
    freopen("k.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll K;
    string S;
    while (cin >> K >> S) {
        if (K == 2) {
            ll cont0 = 0, cont1 = 0;
            char act0 = '0', act1 = '1';
            for (char c : S) {
                if (act0 != c) cont0++;
                if (act1 != c) cont1++;
                swap(act0, act1);
            }
            cout << min(cont0, cont1) << " ";
            char act = cont0 < cont1 ? '0' : '1';
            forr(i, S.size()) {
                cout << act;
                act = act == '0' ? '1' : '0';
            }
            cout << endl;
        } else {
            vector<ll> grupos, finales;

            char ant = '\0';
            ll largoGrupo = 0;
            for (char bit : S) {
                if (bit != ant) {
                    ant = bit;
                    grupos.push_back(largoGrupo);
                    largoGrupo = 1;
                } else {
                    largoGrupo++;
                }
            }
            grupos.push_back(largoGrupo);

            ll cambios = 0;
            for (ll n : grupos) {
                if (n == 0) continue;
                while (n > K) {
                    finales.push_back(K - 1);
                    finales.push_back(1);
                    cambios++;
                    n -= K;
                }
                if (n == K) {
                    finales.push_back(1);
                    finales.push_back(1);
                    cambios++;
                    finales.push_back(K - 2);
                } else {
                    finales.push_back(n);
                }
            }
            cout << cambios << " ";
            char act = S[0];
            for (ll n : finales) {
                while (n--) {
                    cout << act;
                }
                act = act == '0' ? '1' : '0';
            }
            cout << endl;
        }
    }
}