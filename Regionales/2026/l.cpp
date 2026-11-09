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

pair<ll, ll> bfs(Grafo &g, vector<ll> torres) {
    vector<ll> duenno(g.size(), -1), distancia(g.size(), 0), colisiones(g.size(), 0);
    queue<pair<ll, ll>> q;
    for (ll torre : torres) {
        duenno[torre] = torre;
        for (ll vecino : g[torre]) q.push({vecino, torre});
    }

    bool hayContacto = false;
    ll minDistancia;

    while (!hayContacto) {
        ll capa = distancia[q.front().first];
        while (!q.empty() && distancia[q.front().first] == capa) {
            auto [actual, anterior] = q.front();
            q.pop();
            if (duenno[actual] != -1) {
                hayContacto = true;
                minDistancia = distancia[actual] + distancia[anterior] + 1;
                colisiones[actual]++;
                continue;
            }
            duenno[actual] = duenno[anterior];
            distancia[actual] = distancia[anterior] + 1;
            for (ll vecino : g[actual]) {
                if (vecino == anterior) continue;
                q.push({vecino, actual});
            }
        }
    }

    ll pares = 0;
    if (minDistancia % 2 == 1) {
        for (ll nroColisiones : colisiones) {
            pares += nroColisiones;
        }
    } else {
        for (ll nroColisiones : colisiones) {
            nroColisiones++;
            pares += (nroColisiones * (nroColisiones - 1)) / 2;
        }
    }

    if (minDistancia % 2 == 1) pares /= 2;
    return {minDistancia, pares};
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    while (cin >> N) {
        vector<ll> torres;
        forr(i, N) {
            int bit;
            cin >> bit;
            if (bit == 1) torres.push_back(i);
        }

        Grafo g(N);

        forr(i, N - 1) {
            ll v1, v2;
            cin >> v1 >> v2;
            v1--;
            v2--;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }

        auto [dist, pares] = bfs(g, torres);

        cout << dist << " " << pares << endl;
    }
}