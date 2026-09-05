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
    int nums, num, cant = 0, max = 0;
    char op;
    cin >> nums;
    set<int> nuevos;
    set<int> viejos;
    vector<pair<char, int>> hist;
    for (int i = 0; i < nums; i++) {
        cin >> op >> num;
        hist.push_back({op, num});
        if (op == '+') {
            nuevos.insert(num);
        } else if (!nuevos.count(num)) {
            viejos.insert(num);
            cant++;
        }
    }
    max = cant;
    for (pair<char, int> x : hist) {
        char op = x.first;
        int num = x.second;
        if (op == '+') {
            cant++;
            if (cant > max) {
                max = cant;
            }
        } else {
            cant--;
        }
    }
    cout << max << '\n';
}