// Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int main()
{
    long largo;
    std::cin >> largo;
    if (largo == 1) {
        std::cout << 1;
        exit(0);
    }
    if (largo <= 3) {
        std::cout << "NO SOLUTION";
        exit(0);
    }
    if (largo == 4) {
        std::cout << "3 1 4 2";
        exit(0);
    }

    long salto_chiquito = largo % 2 == 0 ? largo/2 : ceil(((float)largo) / 2.0);
    long salto_grande = largo % 2 == 0 ? (largo / 2) + 1 : ceil(((float)largo) / 2.0);

    long actual = 1;
    bool hacersaltogrande = false;
    for (long i = 0; i < largo; i++) {
        std::cout << actual << " ";
        actual = (hacersaltogrande ? salto_grande + actual : salto_chiquito + actual) % largo;
        actual = actual == 0 ? largo : actual;
        hacersaltogrande = !hacersaltogrande;
    }
}

