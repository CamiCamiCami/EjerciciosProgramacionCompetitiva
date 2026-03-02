#include <iostream>
#include <cmath>

long long factoresDeCinco(long long n) {
    long long cant = 0;
    long long posibles = n;
    while (posibles != 0) {
        posibles = floor(posibles / 5);
        cant += posibles;
    }
    return cant;
}

long long factoresDeDos(long long n) {
    long long cant = 0;
    long long posibles = n;
    while (posibles != 0) {
        posibles = floor(posibles / 2);
        cant += posibles;
    }
    return cant;
}

int main()
{
    long long n;
    std::cin >> n;
    long long cincos = factoresDeCinco(n);
    long long dos = factoresDeDos(n);

    std::cout << (cincos < dos ? cincos : dos);
}
