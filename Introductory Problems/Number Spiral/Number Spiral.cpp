#include <iostream>
#include <cmath>

long calcularAnillo(long x, long y) {
    return (x > y ? x : y);
}

bool anilloSube(long anillo) {
    return anillo % 2 == 1;
}

bool yaGiro(long x, long y, long anillo) {
    if (anilloSube(anillo)) {
        return y != anillo;
    }
    else {
        return x != anillo;
    }
}

long numero(long x, long y) {
    long anillo = calcularAnillo(x, y);
    if (anilloSube(anillo)) {
        if (yaGiro(x, y, anillo)) {
            return ((anillo - 1) * (anillo - 1)) + anillo + (anillo - y);
        }
        else {
            return ((anillo - 1) * (anillo - 1)) + x;
        }
    }
    else {
        if (yaGiro(x, y, anillo)) {
            return ((anillo - 1) * (anillo - 1)) + anillo + (anillo - x);
        }
        else {
            return ((anillo - 1) * (anillo - 1)) + y;
        }
    }
}

int main()
{
    long queries;
    long x, y;
    std::cin >> queries;
    for (int i = 0; i < queries; i++) {
        std::cin >> y;
        std::cin >> x;
        std::cout << numero(x, y) << "\n";
    }
}