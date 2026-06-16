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

vector<vector<ll>> desrepite(vector<ll> arr) {
    ll repetido;
    ll desde = 0;
    vector<vector<ll>> subarrays(0);
    subarrays.push_back(vector<ll>(0));
    ll subarr = 0;
    set<ll> elementos;
    for (ll i = 0; i < arr.size();) {
        if (elementos.count(arr[i]) != 0) {
            while (arr[desde] != arr[i])
                desde++;
            i = ++desde;
            subarr++;
            subarrays.push_back(vector<ll>(0));
            elementos.clear();
        } else {
            subarrays[subarr].push_back(arr[i]);
            elementos.insert(arr[i]);
            i++;
        }
    }
    return subarrays;
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo;
        cin >> largo;
        vector<ll> arr(largo);
        for (int i = 0; i < largo; i++) {
            cin >> arr[i];
        }

        vector<vector<ll>> arrays = desrepite(arr);
        cout << "Cantidad Subarrays: " << arrays.size() << endl;
        cout << "Subarrays: " << endl;
        for (vector<ll> vec : arrays) {
            for (ll val : vec) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
}