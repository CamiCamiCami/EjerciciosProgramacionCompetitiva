#include <iostream>
#include <cmath>

long double cap(long long n) {
    long double modulo = log2(pow((long double)10.0, (long double)9.0) + (long double)7.0);
    long double result = (long double)n;
    while (n >= modulo) {
        n -= modulo;
    }
    return n;
}

int main()
{
    unsigned long long n;
    unsigned long long modulo = 1000000007;
    unsigned long long treinta = 73741817;
    std::cin >> n;

    unsigned long long producto_acumulativo = 1;

    while (n > 30) {
        producto_acumulativo *= treinta;
        producto_acumulativo %= modulo;
        n = n - 30;
    }

    producto_acumulativo *= ((unsigned long long)pow(2, n)) % modulo;
    producto_acumulativo %= modulo;
    
    std::cout << producto_acumulativo;
}
