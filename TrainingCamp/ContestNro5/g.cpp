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

int triangulitos(int lado) {
    int rta = 0;
    for (int i = lado; lado > 0; lado--) {
        rta += (lado + lado - 1);
    }
    return rta;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num, mini = 10000;
    vector<int> lados;
    forr(i, 6) {
        cin >> num;
        mini = min(mini, num);
        lados.push_back(num);
    }
    int mini2 = 0, co = 0, mayor, mini3;
    forr(i, 6) {
        lados.push_back(lados[i]);
    }
    forr(i, 12) {
        if (lados[i] == mini && co == 0) {
            mini2 = lados[i + 2];
            mayor = lados[i + 1];
            mini3 = lados[i + 4];
            co++;
        }
    }
    int lado = mini + mini2 + mayor;

    int trianguloMayor = triangulitos(lado);
    int triangulo1 = triangulitos(mini);
    int triangulo2 = triangulitos(mini2);
    int triangulo3 = triangulitos(mini3);
    cout << trianguloMayor - triangulo1 - (triangulo2)-triangulo3 << '\n';
}