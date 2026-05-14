#include <iostream>
#include <vector>

int main()
{
    unsigned int largo;
    std::cin >> largo;
    std::vector<bool> arr(largo);
      
    for (int i = 0, n; i < largo-1; i++) {
        std::cin >> n;
        arr[n-1] = true;
    }

    unsigned int numero_faltante = 1;

    while (arr[numero_faltante - 1]) {
        numero_faltante++;
    }

    std::cout << numero_faltante;
}
