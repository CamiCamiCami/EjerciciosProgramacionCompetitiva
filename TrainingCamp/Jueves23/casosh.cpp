#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 100000;  // nodos
    int m = 200000;  // aristas

    // Usaremos dos conjuntos: A (tamaño 500) y B (tamaño 500)
    // Conectaremos cada nodo de A con muchos de B, sin exceder m.
    // Esto crea muchas aristas que van desde A hacia B, y como el
    // origen está en A y el destino en B, la BFS desde el destino
    // hará que la cola de nivel se llene con todas estas aristas.
    int a = 400, b = 400;
    // Máximo aristas entre A y B = a*b = 160000
    // Completamos hasta m con aristas adicionales.
    vector<tuple<int, int, char>> edges;
    for (int i = 0; i < a && edges.size() < m; ++i) {
        for (int j = 0; j < b && edges.size() < m; ++j) {
            char c = 'a' + (i + j) % 26;
            edges.emplace_back(i, a + j, c);
        }
    }
    // Si faltan aristas, agregamos algunas más entre otras partes
    int resto = m - edges.size();
    for (int i = 0; i < resto; ++i) {
        int u = rand() % n;
        int v = rand() % n;
        if (u == v)
            continue;
        char c = 'a' + rand() % 26;
        edges.emplace_back(u, v, c);
    }

    cout << n << " " << edges.size() << "\n";
    for (auto [u, v, c] : edges) {
        cout << u + 1 << " " << v + 1 << " " << c << "\n";
    }
    return 0;
}