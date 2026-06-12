#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define vector std::vector
#define map std::map
#define set std::set
#define techo(x, k) ((x + k - 1) / k)
using Grafo = vector<vector<pair<ll, ll>>>;
using namespace std;

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {}
}

ll f(ll n);

ll busquedaBinaria(ll desde, ll hasta) {
    while (desde <= hasta) {
        ll medio = (desde + hasta) / 2;
        ll eval = f(medio);
        if (eval == 0) {
            return medio;
        }
        if (eval > 0) {
            hasta = medio - 1;
        } else {
            desde = medio + 1;
        }
    }
    return -1;
}

#define MAXN 1000000
int ft[MAXN + 1];  // for more dimensions, make ft multi-dimensional

void upd(int i0, int v) {  // add v to i0th element (0-based)
    // add extra fors for more dimensions
    for (int i = i0 + 1; i <= MAXN; i += i & -i)
        ft[i] += v;
}

int get(int i0) {  // get sum of range [0,i0)
    int r = 0;
    // add extra fors for more dimensions
    for (int i = i0; i; i -= i & -i)
        r += ft[i];
    return r;
}

int get_sum(int i0, int i1) {  // get sum of range [i0,i1) (0-based)
    return get(i1) - get(i0);
}

/* Vectores */
void vectorTutorial() {
    vector<int> v(5, 1);  // Creación con 5 elementos inicializados en 1.
    v.at(0);              // Accede al elemento verificando límites.
    v[0];                 // Acceso directo sin verificar límites.
    v.front();            // Devuelve el primer elemento.
    v.back();             // Devuelve el último elemento.
    v.push_back(5);       // Agrega al final.
    v.pop_back();         // Elimina el último elemento.
}

/* Set */  // Si no importa el order usar unordered_set
void setTutorial() {
    set<int> s;
    s.insert(1);       // Añade elementos. Si ya existe, es ignorado.
    s.erase(1);        // Elimina un elemento
    s.empty();         // Retorna true (1) si el set no tiene elementos, false (0) si
                       // tiene
    s.count(1);        // Como un set NO tiene duplicados, solo puede retornar 1 o 0.
                       // Se usa mucho para chequear existencia.
    s.lower_bound(1);  // Retorna iterador al PRIMER elemento que sea MAYOR O
                       // IGUAL a 'x'.
}

/* Map */  // Si no importa el order usar unordered_map
void mapTutorial() {
    map<int, int> m;
    m.insert({5, 10});  // Toma: pair<K, V>. Devuelve: pair<iterator, bool>
                        // (iterador al elemento y true si se insertó nuevo).
    m.at(5);            // Toma: clave K. Devuelve: referencia al valor V. (Lanza excepción
                        // si 'k' no existe, más lento que []).
    m.count(5);         // Toma: clave K. Devuelve: bool (true si existe. Solo
                        // disponible desde C++20).
    m.lower_bound(5);   // Toma: clave K. Devuelve: iterador al 1er elemento con
                        // clave >= k (o m.end()).
    m.size();           // Toma: nada. Devuelve: size_t (cantidad actual de elementos).
}

// Esta es tu función que evalúa si un valor cumple la condición.
// En CP, f(x) suele ser un algoritmo Greedy o una simulación.
bool f(long long x);

long long solve(long long min_val, long long max_val) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;  // Guarda la mejor respuesta encontrada hasta ahora
    while (L <= R) {
        // L + (R - L) / 2 previene overflow que pasaría si usas (L + R) / 2
        long long mid = L + (R - L) / 2;

        if (f(mid)) {
            ans = mid;    // mid es válido, lo guardamos como posible respuesta
            R = mid - 1;  // Como queremos el menor valor, buscamos más a la izquierda
        } else {
            L = mid + 1;  // mid no es válido (dio false), buscamos a la derecha
        }
    }

    return ans;  // Al final del ciclo, 'ans' tiene el primer 'true'
}