#include <iostream>
#include <map>
using namespace std;
using Contador = map<char, int>;

bool esReordenable(int cantidad_maximo, int largo) {
  return largo + 1 - cantidad_maximo >= cantidad_maximo;
}

char siguienteCaracter(Contador& cantidades, char caracterProhibido,
                       size_t largo) {
  char frecuente, primeraLetraDisponible = '\0';
  int aparicionesMax = 0;
  for (const auto& [letra, apariciones] : cantidades) {
    if (apariciones > aparicionesMax) {
      aparicionesMax = apariciones;
      frecuente = letra;
    }
    if (primeraLetraDisponible != '\0') continue;  // Ya fue asignada
    if (letra == caracterProhibido) continue;
    if (apariciones == 0) continue;
    primeraLetraDisponible = letra;
  }
  if (!esReordenable(aparicionesMax, largo - 1)) {
    return frecuente;
  } else {
    return primeraLetraDisponible;
  }
}

string reordenaString(Contador& cantidades, size_t largo) {
  string ordenado = "";
  char caracterProhibido = '\0';
  while (largo != 0) {
    caracterProhibido = siguienteCaracter(cantidades, caracterProhibido, largo);
    cantidades[caracterProhibido]--;
    ordenado += caracterProhibido;
    largo--;
  }
  return ordenado;
}

void agregarChar(Contador& charCount, char c) {
  if (charCount.count(c) == 0) {
    charCount[c] = 1;
  } else {
    charCount[c]++;
  }
}

int main() {
  string s;
  cin >> s;
  Contador cantidades;
  for (size_t i = 0; i < s.length(); i++) {
    agregarChar(cantidades, s[i]);
  }
  int aparicionesMax = 0;
  for (const auto& [letra, apariciones] : cantidades) {
    if (apariciones > aparicionesMax) {
      aparicionesMax = apariciones;
    }
  }
  if (!esReordenable(aparicionesMax, s.length())) {
    cout << -1 << '\n';
  } else {
    cout << reordenaString(cantidades, s.length()) << '\n';
  }
}