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

#define MAXN 1000000
vector<ll> ft;  // for more dimensions, make ft multi-dimensional

void upd(int i0, int v) {  // add v to i0th element (0-based)
    // add extra fors for more dimensions
    for (int i = i0 + 1; i <= MAXN; i += i & -i)
        ft[i] += v;
}

int get(int i0) {  // get sum of range [0,i0)
    int r = 0;
    // add extra fors for more dimensions
    for (int i = i0; i; i -= i & -i)
        r += ft[i];
    return r;
}

ll sumaArr;
ll largo;

ll calcularHasta(ll idx) {
    ll corrimiento = idx / largo;
    ll posSubarr = idx % largo;
    ll posOriginal = (posSubarr + corrimiento) % largo;
    ll extra = sumaArr * corrimiento;
    ll sumaSubarr;
    if (posOriginal < posSubarr)
        sumaSubarr = sumaArr - (get(posOriginal + largo - posSubarr) - get(posOriginal));
    else
        sumaSubarr = get(posOriginal) - get(posOriginal - posSubarr);
    ll suma = extra + sumaSubarr;
    return suma;
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll queries;
        cin >> largo >> queries;
        ft = vector<ll>(MAXN + 1, 0);
        for (int i = 0; i < largo; i++) {
            ll val;
            cin >> val;
            upd(i, val);
        }
        sumaArr = get(largo);
        while (queries--) {
            ll desde, hasta;
            cin >> desde >> hasta;
            ll suma = calcularHasta(hasta) - calcularHasta(desde - 1);
            cout << suma << endl;
        }
        ft.clear();
    }
}