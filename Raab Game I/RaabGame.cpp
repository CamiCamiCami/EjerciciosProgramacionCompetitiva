#include <iostream>
#include <vector>
using namespace std;


void printJugada(vector<int> jugada) {
    for(int i : jugada) {
        cout << i << " ";
    }
    cout << "\n";
}


void analizarCaso() {
    int cartas, puntosA, puntosB, puntosEmpate;
    cin >> cartas >> puntosA >> puntosB;
    puntosEmpate = cartas - puntosA - puntosB;
    if(puntosA + puntosB > cartas || ((puntosA == 0) ^ (puntosB == 0))) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
    }
    vector<int> jugadasA, jugadasB;
    for(int i = 0; i < puntosEmpate; i++) {
        jugadasA.push_back(cartas - i);
        jugadasB.push_back(cartas - i);
    }
    for(int i = 0; i < puntosA; i++) {
        jugadasA.push_back(cartas - puntosEmpate - i);
        jugadasB.push_back(cartas - puntosEmpate - puntosB - i);
    }
    for (int i = 0; i < puntosB; i++) {
        jugadasB.push_back(cartas - puntosEmpate - i);
        jugadasA.push_back(cartas - puntosEmpate - puntosA - i);
    }
    printJugada(jugadasA);
    printJugada(jugadasB);
}


int main() {
    int casos;
    cin >> casos;
    while(casos) {
        analizarCaso();
        casos--;
    }
}