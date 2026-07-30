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

ll predecesores[1000000];
ll profundidades[1000000];
ll tamagno[1000000];

ll buscarRepresentante(ll i) {
    if (predecesores[i] == i)
        return i;
    return predecesores[i] = buscarRepresentante(predecesores[i]);
}

void unirConjuntos(ll e1, ll e2) {
    e1 = buscarRepresentante(e1);
    e2 = buscarRepresentante(e2);
    if (e1 == e2)
        return;
    if (profundidades[e1] < profundidades[e2]) {
        predecesores[e1] = e2;
        tamagno[e2] = tamagno[e1] + tamagno[e2];
    } else if (profundidades[e1] > profundidades[e2]) {
        predecesores[e2] = e1;
        tamagno[e1] = tamagno[e2] + tamagno[e1];
    } else {
        predecesores[e1] = e2;
        tamagno[e2] = tamagno[e1] + tamagno[e2];
        profundidades[e1]++;
    }
}

ll ancho, alto;
#define pos2id(fila, col) ((fila - 1) * ancho + (col - 1))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> alto >> ancho;
    vector<string> matriz(alto + 2);
    initArr(predecesores, 1000000, i);
    initArr(tamagno, 1000000, 1);
    initArr(profundidades, 1000000, 0);
    matriz[0] = string(ancho + 2, '*');
    matriz[alto + 1] = string(ancho + 2, '*');
    forrr(i, 1, alto + 1) {
        matriz[i] += '*';
        forrr(j, 1, ancho + 1) {
            char c;
            cin >> c;
            matriz[i] += c;
            if (matriz[i][j] == '*')
                continue;
            if (matriz[i][j - 1] == '.') {
                unirConjuntos(pos2id(i, j), pos2id(i, j - 1));
            }
            if (matriz[i - 1][j] == '.') {
                unirConjuntos(pos2id(i, j), pos2id(i - 1, j));
            }
        }
        matriz[i] += '*';
    }

    forrr(i, 1, alto + 1) {
        forrr(j, 1, ancho + 1) {
            if (matriz[i][j] == '.')
                continue;
            set<ll> gruposConectados;
            ll nuevoTamagno = 1;
            for (auto [dFila, dCol] : {pair{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                if (matriz[i + dFila][j + dCol] != '.')
                    continue;
                ll representante = buscarRepresentante(pos2id(i + dFila, j + dCol));
                if (gruposConectados.count(representante) == 1)
                    continue;
                nuevoTamagno += tamagno[representante];
                gruposConectados.insert(representante);
            }
            matriz[i][j] = '0' + nuevoTamagno % 10;
        }
    }

    forrr(i, 1, alto + 1) {
        matriz[i].erase(matriz[i].begin());
        matriz[i].erase(matriz[i].end() - 1);
        printf("%s\n", matriz[i].c_str());
    }
}