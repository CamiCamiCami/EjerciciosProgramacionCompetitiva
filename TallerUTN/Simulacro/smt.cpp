#include <bits/stdc++.h>
using namespace std;

// Esta es tu función que evalúa si un valor cumple la condición.
// En CP, f(x) suele ser un algoritmo Greedy o una simulación.
bool f(long long k, long long dano, vector<long long> vector) {
  int danox = dano;
  for (long long maxdano : vector) {
    if (k > maxdano) {
      danox -= maxdano;
    } else {
      danox -= k;
    }
    if (danox - k <= 0) {
      return true;
    }
  }
  return false;
}

long long solve(long long min_val, long long max_val, long long dano,
                vector<long long> vector) {
  long long L = min_val;
  long long R = max_val;
  long long ans = -1;  // Guarda la mejor respuesta encontrada hasta ahora

  while (L <= R) {
    // L + (R - L) / 2 previene overflow que pasaría si usas (L + R) / 2
    long long mid = L + (R - L) / 2;

    if (f(mid, dano, vector)) {
      ans = mid;    // mid es válido, lo guardamos como posible respuesta
      R = mid - 1;  // Como queremos el menor valor, buscamos más a la izquierda
    } else {
      L = mid + 1;  // mid no es válido (dio false), buscamos a la derecha
    }
  }

  return ans;  // Al final del ciclo, 'ans' tiene el primer 'true'
}

int main() {
  long long casos, n, h, anterior, actual;
  cin >> casos;
  while (casos--) {
    cin >> n >> h;
    vector<long long> vector;
    cin >> anterior;
    for (int i = 0; i < n - 1; i++) {
      cin >> actual;
      vector.push_back(actual - anterior);
      anterior = actual;
    }
    // cout << "\n\n"<< f(3,h,vector) << "\n\n";
    long long mink = h / n;
    long long maxk = h;
    long long k = solve(mink, maxk, h, vector);
    cout << k << endl;
  }
  return 0;
}