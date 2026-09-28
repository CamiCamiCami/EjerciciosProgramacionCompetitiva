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
    string t, s, ss;
    cin >> t;
    ll na = 0, ls, lss;
    for (char c : t) {
        if (c == 'a')
            na++;
    }
    ls = t.length() + na;
    if (ls % 2 == 1) {
        cout << ":(\n";
        return 0;
    }
    ls /= 2;
    lss = ls - na;
    s = t.substr(0, ls);
    ss = t.substr(ls, lss);
    ll ps = 0, pss = 0;
    while (ps != ls && pss != lss) {
        if (s[ps] == 'a')
            ps++;
        else if (s[ps] == ss[pss]) {
            ps++;
            pss++;
        } else
            break;
    }
    if (pss != lss) {
        cout << ":(\n";
    } else {
        cout << s << '\n';
    }
}