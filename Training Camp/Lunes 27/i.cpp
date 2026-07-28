#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

char siguienteLetra(char c) {
    if (c == 'z')
        return 'A';
    if (c == 'Z')
        return '0';
    return c + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        int f, c, g, arroz = 0;
        char letra;
        cin >> f >> c >> g;
        vector<vector<char>> granja(f);
        forr(i, f) {
            forr(j, c) {
                cin >> letra;
                granja[i].push_back(letra);
                if (letra == 'R') {
                    arroz++;
                }
            }
        }
        int just = arroz / g;
        int sobra = arroz % g;
        int arrozasignado = 0, coGallinassobrantes = 0;

        char pinta = 'a';

        forr(i, f) {

            int arranque = (i % 2 == 0 ? 0 : c - 1);
            if (arranque == 0) {
                for (int j = 0; j < c; j++) {

                    if (granja[i][j] == 'R') {
                        if (coGallinassobrantes < sobra) {
                            if (arrozasignado < (just + 1)) {
                                granja[i][j] = pinta;
                                arrozasignado++;
                            } else {
                                coGallinassobrantes++;
                                arrozasignado = 1;
                                pinta = siguienteLetra(pinta);
                                granja[i][j] = pinta;
                            }
                        } else {
                            if (arrozasignado < (just)) {
                                granja[i][j] = pinta;
                                arrozasignado++;
                            } else {
                                arrozasignado = 1;
                                pinta = siguienteLetra(pinta);
                                granja[i][j] = pinta;
                            }
                        }
                    } else {
                        granja[i][j] = pinta;
                    }
                }
            } else {
                for (int j = arranque; j >= 0; j--) {

                    if (granja[i][j] == 'R') {
                        if (coGallinassobrantes < sobra) {
                            if (arrozasignado < (just + 1)) {
                                granja[i][j] = pinta;
                                arrozasignado++;
                            } else {
                                coGallinassobrantes++;
                                arrozasignado = 1;
                                pinta = siguienteLetra(pinta);
                                granja[i][j] = pinta;
                            }
                        } else {
                            if (arrozasignado < (just)) {
                                granja[i][j] = pinta;
                                arrozasignado++;
                            } else {
                                arrozasignado = 1;
                                pinta = siguienteLetra(pinta);
                                granja[i][j] = pinta;
                            }
                        }
                    } else {
                        granja[i][j] = pinta;
                    }
                }
            }
        }
        forr(i, f) {
            forr(j, c) {
                cout << granja[i][j];
            }
            cout << '\n';
        }
    }
}