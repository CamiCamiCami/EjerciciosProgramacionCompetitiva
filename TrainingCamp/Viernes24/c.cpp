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
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

vector<ll> tamanno;

void calcularTamannos(Arbol& g, ll raiz, ll padre) {
    tamanno[raiz] = 1;
    for (ll hijo : g[raiz]) {
        if (hijo == padre)
            continue;
        calcularTamannos(g, hijo, raiz);
        tamanno[raiz] += tamanno[hijo];
    }
}

vector<vector<ll>> ancestros;  // La raíz es su propio ancestro
vector<ll> profundidad;

void calculaPrimerAncestro(Arbol& g, ll raiz) {
    stack<ll> p;
    p.push(raiz);
    ancestros[raiz].push_back(raiz);
    profundidad[raiz] = 0;
    while (!p.empty()) {
        auto act = p.top();
        p.pop();
        for (ll vecino : g[act]) {
            if (profundidad[vecino] == -1) {
                profundidad[vecino] = profundidad[act] + 1;
                ancestros[vecino].push_back(act);
                p.push(vecino);
            }
        }
    }
}

void calculaKesimoAncestro(Arbol& g, ll k) {
    forr(i, g.size()) {
        ll ancestro = ancestros[ancestros[i][k - 1]][k - 1];  // Cuidado si se cambia el ancestro de la raíz
        ancestros[i].push_back(ancestro);
    }
}

void calcularBinaryLifting(Arbol& g, ll raiz) {
    ancestros = vector<vector<ll>>(g.size());
    profundidad = vector<ll>(g.size(), -1);
    calculaPrimerAncestro(g, raiz);
    for (ll cont = 2, k = 1; cont < g.size(); cont *= 2, k++) {
        calculaKesimoAncestro(g, k);
    }
}

ll enecimoAncestro(Arbol& g, ll nodo, unsigned ll n) {
    for (unsigned ll salto = 0; n != 0; n >>= 1, salto++) {
        if ((n & 1) != 0) {
            nodo = ancestros[nodo][salto];
        }
    }
    return nodo;
}

ll lowestCommonAncestor(Arbol& g, ll a, ll b) {
    if (profundidad[a] < profundidad[b])
        swap(a, b);

    a = enecimoAncestro(g, a, profundidad[a] - profundidad[b]);

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

ll equidistantes(Arbol& g, ll a, ll b) {
    if (a == b)
        return tamanno[0];
    ll c = lowestCommonAncestor(g, a, b);
    if (c == a || c == b) {
        if (c == b)
            swap(a, b);
        ll dist = profundidad[b] - profundidad[a];
        if (dist % 2 == 1)
            return 0;
        ll medio = enecimoAncestro(g, b, dist / 2);
        ll subarbolB = enecimoAncestro(g, b, (dist / 2) - 1);
        return tamanno[medio] - tamanno[subarbolB];
    } else if (profundidad[a] != profundidad[b]) {
        if (profundidad[a] > profundidad[b])
            swap(a, b);
        ll dist = profundidad[a] + profundidad[b] - (2 * profundidad[c]);
        if (dist % 2 == 1)
            return 0;
        ll medio = enecimoAncestro(g, b, dist / 2);
        ll subarbolB = enecimoAncestro(g, b, (dist / 2) - 1);
        return tamanno[medio] - tamanno[subarbolB];
    } else {
        ll dist = profundidad[a] + profundidad[b] - (2 * profundidad[c]);
        ll subarbolA = enecimoAncestro(g, a, (dist / 2) - 1);
        ll subarbolB = enecimoAncestro(g, b, (dist / 2) - 1);
        return tamanno[0] - tamanno[subarbolA] - tamanno[subarbolB];
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll aulas;
    while (cin >> aulas) {
        Arbol g(aulas);
        forr(i, aulas - 1) {
            ll v1, v2;
            cin >> v1 >> v2;
            v1--;
            v2--;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        calcularBinaryLifting(g, 0);
        tamanno = vector<ll>(g.size());
        calcularTamannos(g, 0, -1);
        ll queries;
        cin >> queries;
        while (queries--) {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << equidistantes(g, a, b) << endl;
        }
    }
}