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
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

int main() {
    ll largo;
    cin >> largo;

    map<ll, ll> numeros;
    for (ll i = 0; i < largo; i++) {
        ll num;
        cin >> num;
        if (!numeros.count(num))
            numeros[num] = 0;
        numeros[num] += num;
    }

    ll intermedios[100005];
    initArr(intermedios, 100005, 0);
    ll anterior = 0;
    ll caso = 2;
    for (const pair<ll, ll>& item : numeros) {
        ll num = item.first;
        ll suma = item.second;
        if (num != anterior + 1) {
            intermedios[caso] = intermedios[caso - 1] + suma;
        } else {
            ll opcion1 = intermedios[caso - 1];
            ll opcion2 = intermedios[caso - 2] + suma;
            intermedios[caso] = opcion1 > opcion2 ? opcion1 : opcion2;
        }
        anterior = num;
        caso++;
    }

    cout << intermedios[caso - 1] << endl;
}