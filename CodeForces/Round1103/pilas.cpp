#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define vector std::vector
#define map std::map
#define set std::set
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll Cantpilas, pilas[10];
        cin >> Cantpilas;
        ll maximo = 0;
        for (ll i = 0; i < Cantpilas; i++) {
            cin >> pilas[i];
            if (pilas[i] > maximo)
                maximo = pilas[i];
        }
        maximo++;
        ll maximoNecesario = 0;
        for (ll i = 0; i < Cantpilas; i++) {
            pilas[i] = maximo - pilas[i];
            if (pilas[i] > maximoNecesario)
                maximoNecesario = pilas[i];
        }
        cout << maximoNecesario << endl;
    }
}