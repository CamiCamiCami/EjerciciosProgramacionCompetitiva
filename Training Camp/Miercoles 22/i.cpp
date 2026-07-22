#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ll largo;
    cin >> largo;
    vector<int> numero;
    vector<int> funcion;
    int num;
    char numchar;
    forr(0, largo) {
        cin >> numchar;
        numero.push_back(numchar - '0');
    }
    forr(0, 9) {
        cin >> num;
        funcion.push_back(num);
    }
    int terminar = 0, empezar = 0;
    for (int i = 0; i < largo && !terminar; i++) {
        if (funcion[numero[i] - 1] > numero[i]) {
            numero[i] = funcion[numero[i] - 1];
            empezar = 1;
        } else if (empezar && (funcion[numero[i] - 1] < numero[i])) {
            terminar = 1;
        }
    }
    forr(0, largo) {
        cout << numero[i];
    }
    cout << endl;
}
