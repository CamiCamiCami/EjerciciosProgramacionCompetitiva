#include <chrono>
#include <iostream>
using namespace std;

bool enTablero(int x, int y) { return x >= 0 && x < 7 && y >= 0 && y < 7; }

int distDestino(int x, int y) { return x + (6 - y); }

bool esCallejon(int x, int y, bool usadas[7][7]) {
  if (!enTablero(x, y) || usadas[x][y] || (x == 0 && y == 6)) return false;
  int cerradas = 0;
  if (!enTablero(x - 1, y) || usadas[x - 1][y]) cerradas++;
  if (!enTablero(x + 1, y) || usadas[x + 1][y]) cerradas++;
  if (!enTablero(x, y - 1) || usadas[x][y - 1]) cerradas++;
  if (!enTablero(x, y + 1) || usadas[x][y + 1]) cerradas++;
  return cerradas >= 3;
}

char tieneCallejon(int x, int y, bool usadas[7][7]) {
  if (esCallejon(x - 1, y, usadas)) return 'L';
  if (esCallejon(x + 1, y, usadas)) return 'R';
  if (esCallejon(x, y - 1, usadas)) return 'U';
  if (esCallejon(x, y + 1, usadas)) return 'D';
  return 'X';
}

char opuesto(char direccion) {
  switch (direccion) {
    case 'U':
      return 'D';
    case 'D':
      return 'U';
    case 'L':
      return 'R';
    case 'R':
      return 'L';
    default:
      return '?';
  }
}

int moverX(int x, char direccion) {
  switch (direccion) {
    case 'U':
      return x;
    case 'D':
      return x;
    case 'L':
      return x - 1;
    case 'R':
      return x + 1;
    default:
      return 0;
  }
}

int moverY(int y, char direccion) {
  switch (direccion) {
    case 'U':
      return y - 1;
    case 'D':
      return y + 1;
    case 'L':
      return y;
    case 'R':
      return y;
    default:
      return 0;
  }
}

bool esPerpendicular(char direccion, char conRespecto) {
  switch (conRespecto) {
    case 'U':
    case 'D':
      return direccion == 'L' || direccion == 'R';
    case 'L':
    case 'R':
      return direccion == 'U' || direccion == 'D';
    default:
      return false;
  }
}

bool tableroPartido(char forma[48], int indice, int x, int y,
                    bool usados[7][7]) {
  if (indice == 0) return false;
  int x0 = moverX(x, forma[indice - 1]);
  int y0 = moverY(y, forma[indice - 1]);
  if (enTablero(x0, y0) && !usados[x0][y0]) return false;
  bool puedeMover = true;
  for (char direccion : {'U', 'D', 'R', 'L'}) {
    if (!esPerpendicular(direccion, forma[indice - 1])) continue;
    x0 = moverX(x, direccion);
    y0 = moverY(y, direccion);
    puedeMover = enTablero(x0, y0) && !usados[x0][y0] && puedeMover;
  }
  return puedeMover;
}

int caminos(char forma[48], int indice, int y, int x, bool usados[7][7]) {
  if (indice == 48) {
    return 1;
  }
  if (x == 0 && y == 6) {
    return 0;
  }
  if (tableroPartido(forma, indice, x, y, usados)) {
    return 0;
  }
  char forzado = tieneCallejon(x, y, usados);
  int subtotal = 0;
   if (forma[indice] != '?') {
    if (indice > 0 && forma[indice - 1] == opuesto(forma[indice])) return 0;
    if (forzado != 'X' && forzado != forma[indice]) return 0;
      x = moverX(x, forma[indice]);
    y = moverY(y, forma[indice]);
    if (!enTablero(x, y)) return 0;
    if (usados[x][y]) return 0;
    usados[x][y] = true;
    subtotal = caminos(forma, indice + 1, y, x, usados);
    usados[x][y] = false;
    return subtotal;
  } else {
    for (char direccion : {'U', 'D', 'R', 'L'}) {
      if (indice > 0 && forma[indice - 1] == opuesto(direccion)) continue;
      if (forzado != 'X' && forzado != direccion) continue;
      int x0 = moverX(x, direccion);
      int y0 = moverY(y, direccion);
      if (!enTablero(x0, y0)) continue;
      if (usados[x0][y0]) continue;
      forma[indice] = direccion;
      usados[x0][y0] = true;
      subtotal += caminos(forma, indice + 1, y0, x0, usados);
      usados[x0][y0] = false;
    }
    forma[indice] = '?';
    return subtotal;
  }
  
}

int main() {
  using chrono::duration;
  using chrono::high_resolution_clock;
  char forma[49];
  bool tablero[7][7];
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++) tablero[i][j] = false;
  tablero[0][0] = true;
  for (int i = 0; i < 48; i++) {
    cin >> forma[i];
  }
  forma[48] = '\0';
  auto begin = high_resolution_clock::now();
  cout << caminos(forma, 0, 0, 0, tablero) << '\n';
  auto end = high_resolution_clock::now();
  duration<double, std::milli> ms_double = end - begin;
  // printf("%3lfs\n", ms_double.count() / 1000.0);
}