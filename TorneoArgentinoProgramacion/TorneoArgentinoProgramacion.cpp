#include <iostream>

int main()
{
    long long actual;
    std::cin >> actual;
    
    while (actual != 1) {
        std::cout << actual << " ";
        actual = actual % 2 == 0 ? actual / 2 : 3 * actual + 1;
    }

    std::cout << actual;
}