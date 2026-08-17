#include <deque>
#include <iostream>


int tamaño;


void moverPieza(std::deque<int> juego[3], int origen, int destino) {
    juego[destino].push_front(juego[origen].front());
    juego[origen].pop_front();
    std::cout << origen+1 << " " << destino+1 << "\n";
}


int movimientos(int n) {
    if(n == 1) {
        return 1;
    } else {
        return 2 * movimientos(n - 1) + 1;
    }
}


int espacioRestante(int origen, int destino) {
    if(origen != 0 && destino != 0) {
        return 0;
    } else if(origen != 1 && destino != 1) {
        return 1;
    } else {
        return 2;
    }
}


void moverTorre(std::deque<int> juego[3], int origen, int destino) {
    if(juego[origen].back() == 1) {
        moverPieza(juego, origen, destino);
        return;
    } 
    int restante = espacioRestante(origen, destino);
    int piezaGrande = juego[origen].back();
    juego[origen].pop_back();
    moverTorre(juego, origen, restante);
    juego[origen].push_back(piezaGrande);
    moverPieza(juego, origen, destino);
    juego[destino].pop_back();
    moverTorre(juego, restante, destino);
    juego[destino].push_back(piezaGrande);
}   


int main() {
    std::deque<int> juego[3];
    for (int i = 0; i < 3; i++)
    {
        juego[i] = std::deque<int>();
    }
    std::cin >> tamaño;
    for (int i = tamaño; i >= 1; i--)
    {
        juego[0].push_front(i);
    }
    std::cout << movimientos(tamaño) << "\n";
    moverTorre(juego, 0, 2);
}