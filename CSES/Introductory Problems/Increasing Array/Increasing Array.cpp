// Increasing Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>

int main()
{
    unsigned int largo;
    std::cin >> largo;

    long total_sumado = 0;
    long maximo = 0;

    for (long i = 0, n; i < largo; i++) {
        std::cin >> n;
        maximo = maximo > n ? maximo : n;
        total_sumado += maximo - n;
    }
    std::cout << total_sumado;
}