#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using chrono::duration;
using chrono::duration_cast;
using chrono::high_resolution_clock;
using chrono::milliseconds;


bool enTablero(int x, int y) { return x >= 0 && x < 7 && y >= 0 && y < 7; }


bool esValido(string camino) {
  bool tablero[7][7];
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++) tablero[i][j] = false;
  int x = 0, y = 0;
  for (char c : camino) {
    switch (c) {
      case 'U':
        y--;
        break;
      case 'D':
        y++;
        break;
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      default:
        return false;
    }
    if (tablero[x][y]) {
      return false;
    }
    tablero[x][y] = true;
  }
  return x == 0 && y == 6;
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

bool tableroPartido(char forma[48], int indice, int x, int y, bool usados[7][7]) {
    if (indice == 0) return false;
    int x0 = moverX(x, forma[indice-1]);
    int y0 = moverY(y, forma[indice-1]);
    if (enTablero(x0, y0) && !usados[x0][y0]) return false;
    bool puedeMover = true;
    for (char direccion : {'U', 'D', 'R', 'L'}) {
        if (!esPerpendicular(direccion, forma[indice-1])) continue;
        x0 = moverX(x, direccion);
        y0 = moverY(y, direccion);
        puedeMover = enTablero(x0, y0) && !usados[x0][y0] && puedeMover;
    }
    return puedeMover;
}

int caminos(char forma[48], int indice, int y, int x, bool usados[7][7]) {
  if (indice == 48) {
    return x == 0 && y == 6 ? 1 : 0;
  }
  if (!enTablero(x, y)) {
    return 0;
  }
  if (x == 0 && y == 6) {
    return 0;
  }
  if(tableroPartido(forma, indice, x, y, usados)) {
    return 0;
  }
  if (forma[indice] != '?') {
    if (indice > 0 && forma[indice - 1] == opuesto(forma[indice])) return 0;
    x = moverX(x, forma[indice]);
    y = moverY(y, forma[indice]);
    if (usados[x][y]) return 0;
    usados[x][y] = true;
    int subtotal = caminos(forma, indice + 1, y, x, usados);
    usados[x][y] = false;
    return subtotal;
  }
  int subtotal = 0;
  for (char direccion : {'U', 'D', 'R', 'L'}) {
    if (indice > 0 && forma[indice - 1] == opuesto(direccion)) continue;
    int x0 = moverX(x, direccion);
    int y0 = moverY(y, direccion);
    if (usados[x0][y0]) continue;
    usados[x0][y0] = true;
    forma[indice] = direccion;
    subtotal += caminos(forma, indice + 1, y0, x0, usados);
    usados[x0][y0] = false;
  }
  forma[indice] = '?';
  return subtotal;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char forma[49];
  bool tablero[7][7];
  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 7; j++) tablero[i][j] = false;
  for (int i = 0; i < 48; i++) {
    cin >> forma[i];
  }
  auto t1 = high_resolution_clock::now();
  forma[48] = '\0';
  cout << caminos(forma, 0, 0, 0, tablero) << '\n'; 
  auto t2 = high_resolution_clock::now();
  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  std::cout << ms_int.count() << "ms\n";
}