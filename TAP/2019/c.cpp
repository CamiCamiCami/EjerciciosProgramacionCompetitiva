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

ll componentes = 0;
vector<pair<ll, ll>> centroComponente;
vector<ll> tamannoComponente;
vector<bool> validaComponente;
vector<vector<int>> matriz;

void visitaComponente(ll dx, ll dy) {
    bool esValida = true;
    bool encontroCentro = false;
    ll tamanno = 0;
    pair<ll, ll> centro = {dx, dy};
    int puntas = 0;
    queue<pair<ll, ll>> q;
    q.push({dx, dy});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (matriz[x][y] != -2)
            continue;
        matriz[x][y] = componentes;
        tamanno++;
        ll vecinos = 0;
        for (auto [dx, dy] : {pair{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            ll nx = x + dx, ny = y + dy;
            if (matriz[nx][ny] != -1)
                vecinos++;
            if (matriz[nx][ny] != -2)
                continue;
            q.push({nx, ny});
        }
        if (vecinos == 1) {
            puntas++;
            if (puntas > 4)
                esValida = false;
        } else if (vecinos == 4) {
            if (encontroCentro)
                esValida = false;
            centro = {x, y};
            encontroCentro = true;
        } else if (vecinos != 2)
            esValida = false;
    }
    if (puntas != 4 || !encontroCentro)
        esValida = false;
    centroComponente.push_back(centro);
    validaComponente.push_back(esValida);
    tamannoComponente.push_back(tamanno);
    componentes++;
}

bool esCruz(pair<ll, ll> centro) {
    auto [cx, cy] = centro;
    ll componente = matriz[cx][cy];
    ll lArr = 0, lAba = 0, lDer = 0, lIzq = 0;
    while (matriz[cx - (lArr + 1)][cy] == componente)
        lArr++;
    while (matriz[cx + (lAba + 1)][cy] == componente)
        lAba++;
    while (matriz[cx][cy - (lIzq + 1)] == componente)
        lIzq++;
    while (matriz[cx][cy + (lDer + 1)] == componente)
        lDer++;
    return (lArr == lIzq) && (lIzq == lDer) && (lAba > lArr) && (tamannoComponente[componente] == (lArr + lAba + lDer + lIzq + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll alto, ancho;
    cin >> alto >> ancho;
    matriz = vector<vector<int>>(alto + 2, vector<int>(ancho + 2, -1));
    forrr(i, 1, alto + 1) {
        forrr(j, 1, ancho + 1) {
            char c;
            cin >> c;
            matriz[i][j] = (c == '.' ? -1 : -2);
        }
    }
    forrr(i, 1, alto + 1) {
        forrr(j, 1, ancho + 1) {
            if (matriz[i][j] == -2) {
                visitaComponente(i, j);
            }
        }
    }
    ll cruces = 0;
    for (auto [x, y] : centroComponente) {
        if (validaComponente[matriz[x][y]] && esCruz({x, y}))
            cruces++;
    }

    cout << cruces << endl;
}