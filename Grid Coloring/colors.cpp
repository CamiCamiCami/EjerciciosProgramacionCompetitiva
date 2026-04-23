#include <iostream>
#include <vector>
using namespace std;
using ColorGrid = vector<vector<char>>;
using PossibilityGrid = vector<vector<int>>;


int main()
{
    int filas, columnas;
    cin >> filas >> columnas;
    ColorGrid colores(filas, vector<char>(columnas));
    PossibilityGrid posibilidades(filas, vector<int>(columnas, 3));
    for (int i = 0; i<filas; i++) {
        for (int j = 0; j<columnas; j++) {
            cin >> colores[i][j];
        }
        cin.ignore(1, '\n');
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            char decision = '\0';
            int restricciones = 3;
            for(char c : {'A', 'B', 'C', 'D'}) {
                if (c == colores[i][j]) continue;
                if (j != 0 && c == colores[i][j-1]) continue;
                if (i != 0 && c == colores[i-1][j]) continue;
                int restinjiria = 0;
                if (j != columnas - 1 && i != 0 && c != colores[i - 1][j + 1] && c != colores[i][j + 1]) restinjiria++;
                if (i != filas - 1 && c != colores[i + 1][j]) restinjiria++;
                decision = restinjiria < restricciones ? c : decision;
                restricciones = restinjiria < restricciones ? restinjiria : restricciones;
            }
            colores[i][j] = decision;
            if(decision == '\0') printf("NO ENCONTRO OPCION VALIDA\n");
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << colores[i][j];
        }
        cout << '\n';
    }
}