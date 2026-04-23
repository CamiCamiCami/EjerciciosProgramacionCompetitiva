#include <iostream>
#include <vector>
using namespace std;


void calculoGridParcial(int tamanno, int grid[100][100]) {
    if(tamanno == 1) {
        grid[0][0] = 0;
        return;
    }

    grid[0][tamanno - 1] = grid[tamanno - 1][0] = tamanno - 1;
    grid[tamanno-1][tamanno-1] = 0;


    for(int i = 1; i < tamanno - 1; i++) {
        //cout << "--- Calculando Casilla " << i << " " << tamanno - 1 << " ---\n";
        bool cumpleInvariante = false;
        int candidato = 1;
        for(; !cumpleInvariante; candidato++) {
            //cout << "Candidato: " << candidato << "\n"; 
            cumpleInvariante = true;
            for(int j = 0; j < i && cumpleInvariante; j++) {
                //cout << "grid[" << j << "][" << tamanno - 1 << "] == " << candidato << "? " << (grid[j][tamanno - 1] == candidato) << "\n";
                if (grid[j][tamanno - 1] == candidato) cumpleInvariante = false;
            }
            for(int j = 0; j < tamanno - 1 && cumpleInvariante; j++) {
                //cout << "grid[" << i << "][" << j << "] == " << candidato << "? " << (grid[i][j] == candidato) << "\n";
                if (grid[i][j] == candidato)
                    cumpleInvariante = false;
            }
        }
        //cout << "Quedo " << candidato - 1 << "\n";
        grid[tamanno-1][i] = grid[i][tamanno-1] = candidato - 1;
    }
}

    int main()
{
    int tamannoTotal;
    cin >> tamannoTotal;
    int grid[100][100];
    for (int i = 1; i <= tamannoTotal; i++) {
        calculoGridParcial(i, grid);
    }
    for (int i = 0; i < tamannoTotal; i++)
    {
        for (int j = 0; j < tamannoTotal; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}