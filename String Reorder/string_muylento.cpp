#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
using Contador = map<char, int>;


set<char> caracteresOrdenados;
int cantidadCaracteres;

int reordenaVector(Contador &caracteres, char caracterProhibido, int pos, vector<char> &stringFormado) {
    if (pos >= cantidadCaracteres) return 1;
    for (char c : caracteresOrdenados) {
        if (caracteres[c] == 0) continue;
        if(c == caracterProhibido) continue;
        caracteres[c]--;
        int exito = reordenaVector(caracteres, c, pos + 1, stringFormado);
        if (exito) {
            stringFormado[pos] = c;
            return 1;
        } else {
            caracteres[c]++;
        }
    }
    return 0;
}

void agregarChar(Contador &charCount, char c) {
    if (charCount.count(c) == 0) {
        charCount[c] = 1;
    } else {
        charCount[c]++;
    }
}

int main()
{
    string s;
    cin >> s;
    Contador caracteres;
    cantidadCaracteres = s.length();
    vector<char> stringFormado(cantidadCaracteres);
    for (char &c : s)
    {
        agregarChar(caracteres, c);
        caracteresOrdenados.insert(c);
    }
    int exito = reordenaVector(caracteres, '\0', 0, stringFormado);
    if (!exito) {
        cout << -1 << '\n';
    } else {
        for (char c : stringFormado) {
            cout << c;
        }
        cout << '\n';
    }
    

}