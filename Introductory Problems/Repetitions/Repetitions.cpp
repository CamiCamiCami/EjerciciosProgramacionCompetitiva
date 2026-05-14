//#include <string>
#include <iostream>

int main()
{
    std::string cadena;
    std::cin >> cadena;
    
    char anterior = '\0';
    long maximo = 0;
    long contando = 1;
    for (int i = 0; cadena[i]; i++) {
        if (cadena[i] == anterior) {
            contando++;
        }
        else {
            anterior = cadena[i];
            maximo = maximo > contando ? maximo : contando;
            contando = 1;
        }
    }

    maximo = maximo > contando ? maximo : contando;
    std::cout << maximo;
}