#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FORI(i, d, n) for (int i = d; i < n; i++)

int main() {
  ll Cnumeros;
  cin >> Cnumeros;

  vector<ll> numeros(Cnumeros);
  FORI(i, 0, Cnumeros) {
    ll n;
    cin >> n;
    numeros[i] = n;
  }
  sort(numeros.begin(), numeros.end());
  vector<ll> sumados;
  vector<ll> numerosSumados;
  for (ll i = 0, j = 0; i < Cnumeros; i = j) {
    ll suma = 0;
    for (; j < Cnumeros && numeros[j] == numeros[i]; j++) {
      suma += numeros[i];
    }
    numerosSumados.push_back(numeros[i]);
    sumados.push_back(suma);
  }

  vector<ll> parciales(sumados.size() + 1);
  parciales[0] = 0;
  parciales[1] = sumados[0];
  for (ll i = 1; i < sumados.size(); i++) {
    if (numerosSumados[i] == (numerosSumados[i - 1] - 1)) {
      parciales[i + 1] = sumados[i] + parciales[i];
    } else {
      ll eligiendo = sumados[i] + parciales[i + 1];
      parciales[i + 1] = parciales[i] < eligiendo ? eligiendo : parciales[i];
    }
  }

  cout << parciales.front() << endl;
}