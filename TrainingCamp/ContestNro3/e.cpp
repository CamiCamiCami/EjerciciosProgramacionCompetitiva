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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> nums;
    ll suma = 0;
    forr(0, 4) {
        ll n;
        cin >> n;
        suma = n > suma ? n : suma;
        nums.push_back(n);
    }
    vector<ll> unoauno;
    forr(0, 4) {
        if (nums[i] != suma)
            unoauno.push_back(nums[i]);
    }
    forr(0, 3) {
        cout << unoauno[(i + 1) % 3] + unoauno[(i + 2) % 3] - suma << ' ';
    }
    cout << '\n';
}