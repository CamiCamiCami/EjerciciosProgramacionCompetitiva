#include <iostream>
#include <vector>
using namespace std;
using Grid = vector<vector<int>>;

void initialize_grid(Grid& grid) {
    grid[0][0] = 0;
    grid[0][1] = 3;
    grid[0][2] = 2;
    grid[0][3] = 3;
    grid[1][0] = 3;
    grid[1][1] = 4;
    grid[1][2] = 1;
    grid[1][3] = 2;
    grid[2][0] = 2;
    grid[2][1] = 1;
    grid[2][2] = 4;
    grid[2][3] = 3;
    grid[3][0] = 3;
    grid[3][1] = 2;
    grid[3][2] = 3;
    grid[3][3] = 2;
}


int en_matriz(int largo, int fila, int columna) {
    return 0 <= fila && fila < largo && 0 <= columna && columna < largo;
}

int distancia(Grid& grid, int largo_busqueda, int fila, int columna) {
    int menor = 0;
    if (en_matriz(largo_busqueda, fila-2, columna-1))
        menor = menor > grid[fila - 2][columna - 1] || menor == 0 ? grid[fila - 2][columna - 1] : menor;

    if (en_matriz(largo_busqueda, fila + 2, columna - 1))
        menor = menor > grid[fila + 2][columna - 1] || menor == 0 ? grid[fila + 2][columna - 1] : menor;

    if (en_matriz(largo_busqueda, fila - 1, columna - 2))
        menor = menor > grid[fila - 1][columna - 2] || menor == 0 ? grid[fila - 1][columna - 2] : menor;

    if (en_matriz(largo_busqueda, fila + 1, columna - 2))
        menor = menor > grid[fila + 1][columna - 2] || menor == 0 ? grid[fila + 1][columna - 2] : menor;
    return menor+1;
}

void complete_grid(Grid& grid, int largo) {
    for(int i = 0; i < largo; i++) {
        grid[i][largo-1] = grid[largo-1][i] = distancia(grid, largo-1, i, largo-1);
    }
}

int main()
{
    int largo;
    cin >> largo;
    Grid grid(largo, std::vector<int>(largo));
    initialize_grid(grid);
    if(largo == 4) { 
        grid[3][0] = grid[0][3] = 5;
    } else {
        for (int i = 5; i <= largo; i++)
            complete_grid(grid, i);
    }
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo; j++) {
            printf("%i ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}