#include <iostream>
using namespace std;

int main() {
    long long viajes, precioUnitario, cantidadCombo, precioCombo;
    cin >> viajes >> cantidadCombo >> precioUnitario >> precioCombo;
    if((double)precioCombo/(double)cantidadCombo >= (double)precioUnitario) {
        cout << precioUnitario * viajes;
        return 0;
    }
    int combos = 0;
    for(;combos*cantidadCombo < viajes; combos++);
    combos--;
    long long viajesRestantes = viajes - combos*cantidadCombo;
    long long precioUltimosViajes = precioUnitario*viajesRestantes > precioCombo ? precioCombo : precioUnitario*viajesRestantes;
    cout << combos*precioCombo + precioUltimosViajes << '\n';
}