#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll dados1, dados2;
    cin >> dados1 >> dados2;
    double promedio1 = 0, promedio2 = 0;
    while(dados1--) {
        double dado;
        cin >> dado;
        promedio1 += (dado+1)/2.0;
    }
    while(dados2--) {
        double dado;
        cin >> dado;
        promedio2 += (dado+1)/2.0;
    }
    cout << (promedio1 > promedio2 ? "ALICE" : (promedio2 > promedio1 ? "BOB" : "EMPATE")) << endl;
}