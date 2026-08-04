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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo;
        string s;
        cin >> largo;
        cin >> s;
        vector<char> letras;
        vector<ll> largos;
        letras.push_back(s[0]);
        largos.push_back(1);
        forrr(i, 1, largo) {
            if(letras.back() == s[i]) {
                largos.back()++;
            } else {
                letras.push_back(s[i]);
                largos.push_back(1);
            }
        }
        ll ahorra = 0;
        forrr(i,1, letras.size()-1) {
            if(largos[i] != 1) continue;
            ahorra = max(ahorra, 1LL);
            if(letras[i-1] != letras[i+1]) continue;
            ahorra = 2;
        }

        cout << letras.size() - ahorra << endl;

    }
}