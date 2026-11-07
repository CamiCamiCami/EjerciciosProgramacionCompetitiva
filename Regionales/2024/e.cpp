#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)

using namespace std;
using Arbol = vector<vector<pair<ll, ll>>>;

int main() {
    freopen("e.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    while (cin >> N) {
        vector<ll> parcial(N);
        set<ll> resticciones;
        forr(i, N) {
            cin >> parcial[i];
            resticciones.insert(parcial[i]);
        }

        ll sig = 1, pos = 0;
        while (resticciones.count(sig)) sig++;
        while (sig < N + 1 && pos < N) {
            if (parcial[pos] == 0) {
                sig++;
            } else {
                if (sig > parcial[pos] + 1) break;
                sig = parcial[pos] + 1;
            }
            while (resticciones.count(sig)) sig++;
            pos++;
        }
        pos--;
        ll hastaSube = max(0LL, pos);
        sig = 1, pos = N - 1;
        while (resticciones.count(sig)) sig++;
        while (sig <= N && pos >= 0) {
            if (parcial[pos] == 0) {
                sig++;
            } else {
                if (sig > parcial[pos] + 1) break;
                sig = parcial[pos] + 1;
            }
            while (resticciones.count(sig)) sig++;
            pos--;
        }
        pos++;
        ll desdeBaja = min(N, pos);

        cout << hastaSube << " " << desdeBaja << endl;
    }
}