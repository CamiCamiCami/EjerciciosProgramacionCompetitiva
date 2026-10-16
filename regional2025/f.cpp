#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)

using namespace std;

map<ll, ll> exponentes;
ll factores = 0;
void factorizar(ll numero)
{
    for (ll i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
        {
            exponentes[i] = 0;
            factores++;
            while (numero % i == 0)
            {
                numero /= i;
                exponentes[i]++;
            }
        }
    }
    if (numero != 1)
    {
        exponentes[numero] = 1;
        factores++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string numero;
    cin >> numero;
    ll digitos = 0;
    ll valor = 0;
    for (char c : numero)
    {
        if (digitos >= 10)
            break;
        int digito = c - '0';
        valor *= 10;
        valor += digito;
        digitos++;
    }
    digitos = max((long long)numero.size() - 10LL, 0LL);
    factorizar(valor);
    if (digitos != 0)
    {
        if (!exponentes.count(2))
        {
            exponentes[2] = 0;
            factores++;
        }

        exponentes[2] += digitos;
        if (!exponentes.count(5))
        {
            exponentes[5] = 0;
            factores++;
        }

        exponentes[5] += digitos;
    }

    cout << factores << endl;
    for (auto [factor, exponente] : exponentes)
    {
        if (exponente == 0)
            continue;
        cout << factor << " " << exponente << endl;
    }
}