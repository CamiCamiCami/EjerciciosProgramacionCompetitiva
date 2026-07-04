#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ll N;
    cin >> N;
    char in;
    bool ultimoAtras = true;
    list<ll> numeros;
    for (int i = 1; i <= N; i++) {
        cin >> in;
        if (ultimoAtras) {
            numeros.push_back(i);
            ultimoAtras = in == 'x';
        } else {
            numeros.push_front(i);
            ultimoAtras = in == 'o';
        }
    }
    vector<ll> final(numeros.begin(), numeros.end());
    for (int i = 0; i < N; i++) {
        if (ultimoAtras) {
            cout << final[i] << ' ';
        } else {
            cout << final[N - i - 1] << ' ';
        }
    }
}