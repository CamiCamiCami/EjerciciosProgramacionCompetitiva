#include <iostream>
#include <list>
#include <cmath>

int main()
{
    long n;
    std::cin >> n;
    double media_suma = ((double)n) * (((double)n) + 1.0) * (0.25);
    if (ceil(media_suma) != media_suma) 
    {
        std::cout << "NO\n";
        exit(0);
    }
    else {
        std::cout << "YES\n";
    }

    long objetivo_suma = (long)media_suma;
    std::list<long> prioritaria;
    long suma_prioritaria = 0;
    long largo_prioritaria = 0;
    std::list<long> secundaria;
    long largo_secundaria = 0;

    for (int i = n; i > 0; i--) {
        if (suma_prioritaria + i <= objetivo_suma) {
            prioritaria.push_front(i);
            suma_prioritaria += i;
            largo_prioritaria++;
        }
        else {
            secundaria.push_front(i);
            largo_secundaria++;
        }
    }

    std::cout << largo_prioritaria << "\n";
    while (!prioritaria.empty()) {
        std::cout << prioritaria.front() << " ";
        prioritaria.pop_front();
    }

    std::cout << "\n" << largo_secundaria << "\n";
    while (!secundaria.empty()) {
        std::cout << secundaria.front() << " ";
        secundaria.pop_front();
    }
    
}