#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll int
#define dd long double
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;

struct Edge {
    int to;
    char c;
};

using GrafoPesado = vector<vector<Edge>>;
using Grafo = vector<vector<ll>>;

vector<ll> distancias;

void EncuentraDistancias(GrafoPesado& g, ll centro) {
    ll vertices = g.size();
    distancias = vector<ll>(vertices, -2);
    queue<ll> q;
    q.push(centro);
    distancias[centro] = 0;
    while (!q.empty()) {
        ll actual = q.front();
        ll distActual = distancias[actual];
        q.pop();
        for (auto [vecino, letra] : g[actual]) {
            if (distancias[vecino] == -2) {
                distancias[vecino] = distActual + 1;
                q.push(vecino);
            }
        }
    }
}

vector<ll> menorCamino;
vector<char> menorString;

struct NodoCola {
    int nodo;
    int padre;
    char letra;
};

void menosLexicografico(GrafoPesado& g, ll desde, ll hasta) {
    vector<ll> anterior(g.size());
    vector<char> letraLlegada(g.size());
    queue<NodoCola> nivel;
    nivel.push({desde, -1, ' '});
    ll distActual = distancias[desde];
    char minimoNivel = ' ';
    while (!nivel.empty()) {
        queue<NodoCola> sigs;
        char siguienteMinimo = 'z';
        while (!nivel.empty()) {
            auto [act, ant, car] = nivel.front();
            nivel.pop();
            if (car != minimoNivel)
                continue;
            anterior[act] = ant;
            letraLlegada[act] = minimoNivel;
            for (auto [vecino, letra] : g[act]) {
                if (distancias[vecino] >= distActual)
                    continue;
                siguienteMinimo = min(siguienteMinimo, letra);
                sigs.push({vecino, act, letra});
            }
        }
        nivel = move(sigs);
        minimoNivel = siguienteMinimo;
        distActual--;
    }
    menorCamino.clear();
    menorString.clear();
    ll actual = hasta;
    while (actual != -1) {
        menorCamino.push_back(actual);
        menorString.push_back(letraLlegada[actual]);
        actual = anterior[actual];
    }
    menorString.pop_back();
    reverse(menorCamino.begin(), menorCamino.end());
    reverse(menorString.begin(), menorString.end());
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    while (cin >> vertices >> aristas) {
        GrafoPesado g(vertices);
        forr(0, aristas) {
            ll v1, v2;
            char esp, c;
            cin >> v1 >> v2 >> c;
            v1--;
            v2--;
            g[v1].push_back({v2, c});
            g[v2].push_back({v1, c});
        }

        EncuentraDistancias(g, vertices - 1);
        menosLexicografico(g, 0, vertices - 1);
        cout << menorString.size() << endl;
        for (ll p : menorCamino) {
            cout << p + 1 << " ";
        }
        cout << endl;
        for (char c : menorString) {
            cout << c;
        }
        cout << endl;
    }
}
