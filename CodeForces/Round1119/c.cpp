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
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll largo;
            cin >> largo;
            vector<ll> nums(largo);
            ll ultimo = -1;
            bool encontro = false;
            forr(i, largo) {
                cin >> nums[i];
                if (nums[i] != 0) {
                    if (!encontro)
                        nums[i] = 1;
                    encontro = true;
                    ultimo = i;
                    if (nums[i] == -1)
                        nums[i] = 0;
                }
            }
            if (ultimo != -1)
                nums[ultimo] = 1;
            forr(i, largo) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    }
}