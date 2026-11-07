#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)

using namespace std;
using Arbol = vector<vector<pair<ll, ll>>>;

vector<ll> masCercana;
void Dijkstra(Arbol g, set<ll> hojas) {
    masCercana = vector<ll>(g.size(), -1);
    priority_queue<tuple<ll, ll, ll>, std::vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;
    for(ll hoja : hojas) {
        q.push({0, hoja, hoja});
    }
    while(!q.empty()) {
        auto [dist, cercano, actual] = q.top();
        q.pop();
        if(masCercana[actual] != -1) continue;
        masCercana[actual] = cercano;
        for(auto [vecino, peso] : g[actual]) {
            if(masCercana[vecino] != -1) continue;
            q.push({dist+peso, cercano, vecino});
        }
    }
}



int main() {
    freopen("g.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    while(cin >> N) {
        Arbol g(N);
        forr(i, N-1) {
            ll v1, v2, l;
            cin >> v1 >> v2 >> l;
            v1--;
            v2--;
            g[v1].push_back({v2, l});
            g[v2].push_back({v1, l});
        }
        set<ll> hojas;
        forr(i, N) {
            if(g[i].size() != 1) continue;
            hojas.insert(i);
        }

        cout << "HOla" << endl;
        Dijkstra(g, hojas);

    }
}