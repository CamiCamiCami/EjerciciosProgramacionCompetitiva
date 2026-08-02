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

vector<bool> visitado;
vector<ll> tipo;
vector<ll> tamagno;
ll buenoMasPesado = 0;

ll buscaBuenos(Grafo& g, ll raiz) {
    visitado[raiz] = true;
    ll hijosHoja = 0, hijosSimples = 0, hijosGrandes = 0;
    ll peso = 1;
    for (ll hijo : g[raiz]) {
        if (visitado[hijo])
            continue;
        ll tipo = buscaBuenos(g, hijo);
        if (tipo == 0)
            hijosHoja++;
        else if (tipo == 1)
            hijosSimples++;
        else
            hijosGrandes++;
        peso += tamagno[hijo];
    }
    tamagno[raiz] = peso;
    if (hijosGrandes != 0 || hijosSimples > 2) {
        return 3;
    }
    if (hijosHoja == 0 && hijosSimples == 0) {
        buenoMasPesado = max(buenoMasPesado, 1LL);
        return 0;
    } else if (hijosSimples == 1) {
        buenoMasPesado = max(buenoMasPesado, peso);
        return 1;
    } else {
        buenoMasPesado = max(buenoMasPesado, peso);
        return 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll vertices, aristas;
        cin >> vertices;
        aristas = vertices - 1;
        Grafo g(vertices);
        visitado = vector<bool>(vertices, false);
        tipo = vector<ll>(vertices);
        tamagno = vector<ll>(vertices);
        forr(i, aristas) {
            ll n1, n2;
            cin >> n1 >> n2;
            n1--;
            n2--;
            g[n1].push_back(n2);
            g[n2].push_back(n1);
        }
        buscaBuenos(g, 0);
        cout << buenoMasPesado << endl;
    }
}