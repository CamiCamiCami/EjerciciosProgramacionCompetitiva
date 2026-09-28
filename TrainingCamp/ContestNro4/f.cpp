#include <algorithm>
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

ll ig(ll n) {
    if (n <= 0)
        return 0;
    return (3 * (n / 2) + (n % 2));
}

ll M1m2(ll n, ll m) {
    if (2 * m - n >= 0) {
        return ((2 * (n - m)) + ig(2 * m - n));
    } else {
        return 2 * m;
    }
}

ll M2m1(ll N, ll n, ll m) {
    ll despues;
    if (N == n) {
        despues = ig(m);
    } else {
        despues = M1m2(N - n + m, m);
    }
    return (n - m) + despues;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    vector<ll> nums(3);
    while (casos--) {
        forr(0, 3) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        if (nums[0] == nums[1] && nums[2] == nums[1]) {
            cout << ig(nums[0]) << endl;
        } else if (nums[1] == nums[0]) {
            cout << M1m2(nums[2], nums[0]) << endl;
        } else {
            cout << M2m1(nums[2], nums[1], nums[0]) << endl;
        }
    }
}