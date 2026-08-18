#include <algorithm>
#include <deque>
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
        ll largo, desde, hasta;
        cin >> largo >> desde >> hasta;
        desde--;
        hasta--;
        deque<ll> externo, interno;
        ll min_interno = 10E10;
        forr(i, largo) {
            ll num;
            cin >> num;
            if (i <= desde || i > hasta) {
                externo.push_back(num);
            } else {
                interno.push_back(num);
                min_interno = min(min_interno, num);
            }
        }
        while (interno.front() != min_interno) {
            interno.push_back(interno.front());
            interno.pop_front();
        }

        while (!externo.empty() && externo.front() < min_interno) {
            cout << externo.front() << " ";
            externo.pop_front();
        }
        while (!interno.empty()) {
            cout << interno.front() << " ";
            interno.pop_front();
        }
        while (!externo.empty()) {
            cout << externo.front() << " ";
            externo.pop_front();
        }
        cout << endl;
    }
}