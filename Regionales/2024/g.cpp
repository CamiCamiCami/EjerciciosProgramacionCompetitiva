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

vector<pair<ll, ll>> masCercana;
vector<pair<ll, ll>> segundaCercana;
using Nodo = tuple<ll, ll, ll>;
void hojaMasCercana(GrafoPesado &g) {
    masCercana = vector<pair<ll, ll>>(g.size(), {10e10, -1});
    segundaCercana = vector<pair<ll, ll>>(g.size(), {10e10, -1});
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> q;
    forr(i, g.size()) {
        if (g[i].size() != 1) continue;
        q.push({0, i, i});
        masCercana[i] = {0, i};
    }

    while (!q.empty()) {
        auto [distHoja, cercano, actual] = q.top();
        q.pop();
        for (auto [vecino, distancia] : g[actual]) {
            pair<ll, ll> nuevoCercano = {distHoja + distancia, cercano};
            if (nuevoCercano < masCercana[vecino]) {
                masCercana[vecino] = nuevoCercano;
                q.push({distHoja + distancia, cercano, vecino});
            } else if (nuevoCercano < segundaCercana[vecino]) {
                segundaCercana[vecino] = nuevoCercano;
                q.push({distHoja + distancia, cercano, vecino});
            }
        }
    }
}

vector<vector<ll>> ancestros; // La raíz es su propio ancestro
vector<ll> profundidad;
void calculaPrimerAncestro(GrafoPesado &g, ll raiz) {
    stack<ll> p;
    p.push(raiz);
    ancestros[raiz].push_back(raiz);
    profundidad[raiz] = 0;
    while (!p.empty()) {
        auto act = p.top();
        p.pop();
        for (auto [vecino, _] : g[act]) {
            if (profundidad[vecino] == -1) {
                profundidad[vecino] = profundidad[act] + 1;
                ancestros[vecino].push_back(act);
                p.push(vecino);
            }
        }
    }
}

void calculaKesimoAncestro(GrafoPesado &g, ll k) {
    forr(i, g.size()) {
        ll ancestro = ancestros[ancestros[i][k - 1]][k - 1]; // Cuidado si se cambia el ancestro de la raíz
        ancestros[i].push_back(ancestro);
    }
}

void calcularBinaryLifting(GrafoPesado &g, ll raiz) {
    ancestros = vector<vector<ll>>(g.size());
    profundidad = vector<ll>(g.size(), -1);
    calculaPrimerAncestro(g, raiz);
    for (ll cont = 2, k = 1; cont < g.size(); cont *= 2, k++) {
        calculaKesimoAncestro(g, k);
    }
}

ll enecimoAncestro(ll nodo, unsigned ll n) {
    for (unsigned ll salto = 0; n != 0; n >>= 1, salto++) {
        if ((n & 1) != 0) {
            nodo = ancestros[nodo][salto];
        }
    }
    return nodo;
}

ll lowestCommonAncestor(GrafoPesado &g, ll a, ll b) {
    if (profundidad[a] < profundidad[b]) swap(a, b);

    a = enecimoAncestro(a, profundidad[a] - profundidad[b]);

    while (a != b) {
        ll L = 0;
        ll R = ancestros[b].size() - 1;
        ll ans = 0;
        while (L <= R) {
            ll mid = L + (R - L) / 2;
            if (ancestros[a][mid] != ancestros[b][mid]) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        a = ancestros[a][ans];
        b = ancestros[b][ans];
    }
    return a;
}

using Camino = tuple<ll, ll, ll>;
ll largoCamino(Camino c) {
    auto [d, m, h] = c;
    return profundidad[d] + profundidad[h] - 2 * profundidad[m];
}

ll enecimoPoblado(Camino c, ll n) {
    auto [d, m, h] = c;
    ll primerLargo = profundidad[d] - profundidad[m], segundoLargo = profundidad[h] - profundidad[m];
    if (n <= primerLargo) {
        return enecimoAncestro(d, n);
    } else {
        return enecimoAncestro(h, segundoLargo - (n - primerLargo));
    }
}

bool ganaPueblo(GrafoPesado g, Camino c, ll x) {
    auto [d, m, h] = c;
    ll pueblo = enecimoPoblado(c, x);
    if (pueblo == h) {
        auto [_, ganador] = masCercana[h];
        return ganador == d;
    }
    if (pueblo == d) {
        return true;
    } else {
        ll sigPueblo = enecimoPoblado(c, x + 1);
        ll ganador, distancia = 10e10;
        for (auto [vecino, peso] : g[pueblo]) {
            if (vecino == sigPueblo) continue;
            auto [distCercano, cercano] = masCercana[vecino];
            if (distancia > distCercano + peso) {
                distancia = distCercano + peso;
                ganador = cercano;
            }
        }
        return ganador == d;
    }
}

ll cuantosConquista(GrafoPesado g, Camino c) {
    ll L = 0;
    ll R = largoCamino(c);
    ll ans = -1;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (ganaPueblo(g, c, mid)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, Q;
    while (cin >> N) {
        GrafoPesado g(N);
        forr(i, N - 1) {
            ll v1, v2, largo;
            cin >> v1 >> v2 >> largo;
            v1--;
            v2--;
            g[v1].push_back({v2, largo});
            g[v2].push_back({v1, largo});
        }

        hojaMasCercana(g);
        calcularBinaryLifting(g, 0);

        cin >> Q;
        forr(i, Q) {
            ll origen, corona;
            cin >> origen >> corona;
            origen--;
            corona--;
            ll medio = lowestCommonAncestor(g, origen, corona);
            ll capturas = cuantosConquista(g, {origen, medio, corona});
            cout << capturas << endl;
        }
    }
}