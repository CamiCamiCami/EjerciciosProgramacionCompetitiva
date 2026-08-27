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

bool intersecan(pair<ll, ll> c1, ll r1, pair<ll, ll> c2, ll r2) {
    auto [x1, y1] = c1;
    auto [x2, y2] = c2;
    ll dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    if (c1 == c2) {
        return r1 == r2;
    } else if (dist <= r1 * r1 || dist <= r2 * r2) {
        ll rM = max(r1, r2);
        ll rm = min(r1, r2);
        return dist >= (rM - rm) * (rM - rm);
    } else {
        ll r = (r1 + r2) * (r1 + r2);
        return dist <= r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<ll, ll>> puntos;
    vector<ll> radios;
    ll N;
    cin >> N;
    forr(i, N) {
        ll x, y, r;
        cin >> x >> y >> r;
        puntos.push_back({x, y});
        radios.push_back(r);
    }
    bool sePuede = true;
    forr(i, puntos.size()) {
        forrr(j, i + 1, puntos.size()) {
            sePuede = !intersecan(puntos[i], radios[i], puntos[j], radios[j]);
            if (!sePuede)
                break;
        }
        if (!sePuede)
            break;
    }

    cout << (sePuede ? "SI" : "NO") << endl;
}