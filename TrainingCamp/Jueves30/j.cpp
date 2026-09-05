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

long long solve(long long min_val, long long max_val, vector<pair<pair<int, int>, ll>>& v, int n) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;

    while (L <= R) {
        set<int> temp1;
        set<int> temp2;
        forr(i, n) {
            temp1.insert(i);
        }
        forr(i, n) {
            temp2.insert(i);
        }
        long long mid = L + (R - L) / 2;

        for (pair p : v) {
            if (p.second <= mid) {
                temp1.erase(p.first.first);
                temp2.erase((p.first).second);
            }
        }
        if (temp1.empty() && temp2.empty()) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, ll>> v;
    int air, fac;
    int days, mini = 0, maxi = 1e9;
    forr(n, m) {
        cin >> air >> fac >> days;
        v.push_back({{air, fac}, days});
        mini = min(mini, days);
        maxi = min(maxi, days);
    }

    int dia = solve(0, maxi, v, n);
    cout << dia << '\n';
}