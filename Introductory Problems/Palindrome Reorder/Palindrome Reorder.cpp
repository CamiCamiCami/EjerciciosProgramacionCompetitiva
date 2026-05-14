#include <iostream>
#include <string>
#include <array>

int getIndice(char c) {
    return int(c) - int('A');
}

int getLetraNro(int n) {
    return char(int('A') + n);
}

int main()
{
    const int cant_letras = int('Z') - int('A') + 1;
    std::string input;
    long letras[27];
    for (int i = 0; i < cant_letras; i++) {
        letras[i] = 0;
    }

    std::cin >> input;
    int i = 0;
    for (char c = input[0]; c != '\0'; i++, c = input[i]) {
        letras[getIndice(c)]++;
    }
    bool tiene_medio = i % 2 == 1;
    bool encontro_medio = !tiene_medio;
    char letra_medio;

    for (int i = 0; i < cant_letras; i++) {
        if (letras[i] % 2 == 1) {
            if (!encontro_medio) {
                encontro_medio = true;
                letra_medio = getLetraNro(i);
            }
            else {
                std::cout << "NO SOLUTION\n";
                exit(0);
            }
        }
    }

    for (int i = 0; i < cant_letras; i++) {
        long cantidad = letras[i] / 2;
        char c = getLetraNro(i);
        if (tiene_medio && c == letra_medio) {
            continue;
        }
        while (cantidad > 0) {
            std::cout << c;
            cantidad--;
        }
    }

    if (tiene_medio) {
        long cantidad_medio = letras[getIndice(letra_medio)];
        while (cantidad_medio > 0) {
            std::cout << letra_medio;
            cantidad_medio--;
        }
    }

    for (int i = cant_letras-1; i >= 0; i--) {
        long cantidad = letras[i] / 2;
        char c = getLetraNro(i);
        if (tiene_medio && c == letra_medio) {
            continue;
        }
        while (cantidad > 0) {
            std::cout << c;
            cantidad--;
        }
    }
}
