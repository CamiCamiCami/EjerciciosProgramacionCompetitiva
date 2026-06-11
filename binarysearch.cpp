
#include <iostream>
using namespace std;

#define ll long long

int arr[]{1, 4, 6, 7, 8, 10, 12, 15};
int buscado = 4;
ll f(ll n);

ll busquedaBinaria(ll desde, ll hasta) {
    for (ll a = desde, b = hasta, medio = (a + b) / 2; a != b; medio = (a + b) / 2)
    {
        int eval = f(medio);
        if (eval == 0)
            return medio;
        if (eval > 1)
        {
            b = medio;
        }
        else
        {
            a = medio + 1;
        }
    }
    return 0;
}

int main()
{
    cout << busquedaBinaria(0, 8);
}