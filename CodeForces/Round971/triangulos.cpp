#include <bits/stdc++.h>
using namespace std;

int main() {
    long long casos; cin >> casos;
    while(casos--) {
        set<pair<long long,long long>> puntos;
        long long cantpuntos; cin >> cantpuntos;
        for(long long i = 0; i < cantpuntos; i++) {
            long long x, y; cin >> x >> y;
            puntos.insert({x, y});
        }
        long long triangulos = 0;
        for(pair<long long, long long> p : puntos) {
            if(p.second != 0) continue;
            if(puntos.find({p.first, 1}) != puntos.end()) {
                triangulos += cantpuntos - 2;
            }
            if(puntos.find({p.first+1, 1}) != puntos.end()) {
                if(puntos.find({p.first+2, 0}) != puntos.end()) {
                    triangulos++;
                }
                if(puntos.find({p.first-1, 1}) != puntos.end()) {
                    triangulos++;
                }

            }
        }
        cout << triangulos << endl;
    }
}