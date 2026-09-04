#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll ataques, vida;
        cin >> ataques >> vida;
        map<ll, ll> distancias;
        ll anterior;
        cin >> anterior;
        for (int i = 1; i < ataques; i++) {
            ll actual;
            cin >> actual;
            ll dist = actual - anterior;
            if (!distancias.count(dist))
                distancias[dist] = 0;
            distancias[dist]++;
            anterior = actual;
        }
        ll venenoNecesario = 0;
        ll aportantes = ataques;
        ll dagno = 0;
        for (auto item : distancias) {
            ll distancia = item.first;
            ll cantidad = item.second;
            ll venenoExtra = distancia - venenoNecesario;
            ll nuevoDagno = venenoExtra * aportantes;
            if (dagno + nuevoDagno >= vida)
                break;
            dagno = dagno + nuevoDagno;
            venenoNecesario = venenoNecesario + venenoExtra;
            aportantes -= cantidad;
        }
        venenoNecesario += techo((vida - dagno), aportantes);
        cout << venenoNecesario << endl;
    }
}