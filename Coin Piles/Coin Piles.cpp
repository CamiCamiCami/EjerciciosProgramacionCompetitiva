#include <iostream>
#include <cmath>

bool tresEnTresFunciona(long menor, long dif) {
    return (menor - dif) % 3 == 0;
}

bool paredNoEsProblema(long menor, long dif) {
    return menor >= dif;
}

bool puede(long a, long b) {
    long dif = (long)abs(a - b);
    long menor = a < b ? a : b;
    return tresEnTresFunciona(menor, dif) && paredNoEsProblema(menor, dif);
}

int main()
{
    long pruebas;
    std::cin >> pruebas;
    long a, b;
    long dif, menor;
    for (int i = 0; i < pruebas; i++) {
        std::cin >> a;
        std::cin >> b;
        std::cout << (puede(a, b) ? "YES\n" : "NO\n");
    }
}