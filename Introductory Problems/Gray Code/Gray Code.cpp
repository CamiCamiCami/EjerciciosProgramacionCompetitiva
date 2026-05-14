#include <iostream>
#include <cmath>

int tamaño;

void printStep(int estado[16]) {
    for (int i = tamaño - 1 ; i >= 0; i--) {
        std::cout << estado[i];
    }
    std::cout << '\n';
}


void turnBit(int estado[16], int position) {
    estado[position-1] = estado[position-1] == 0 ? 1 : 0;
}


void recorrer(int dimension, int estado[16]) {
    if (dimension == 1) {
        printStep(estado);
        turnBit(estado, 1);
        printStep(estado);
        return;
    }
    recorrer(dimension - 1, estado);
    turnBit(estado, dimension);
    recorrer(dimension - 1, estado);
}


int main() {
    std::cin >> tamaño;
    int estado[16] = {0};
    recorrer(tamaño, estado);
    return 0;
}
