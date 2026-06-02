#include <iostream>
#include <vector>
using namespace std;

int main() {
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        int lineas;
        cin >> lineas;
        vector<int> notas(lineas);
        for(int j = 0; j < lineas; j++) {
            char c1, c2, c3, c4;
            cin >> c1 >> c2 >> c3 >> c4;
            if(c1 == '#') 
                notas[j] = 1;
            else if(c2 == '#') 
                notas[j] = 2;
            else if(c3 == '#')
                notas[j] = 3;
            else    
                notas[j] = 4;
        }
        for(int j = 0; j < lineas; j++) {
            cout << notas[lineas-j-1] << ' ';
        }
        cout << '\n';
    }
}