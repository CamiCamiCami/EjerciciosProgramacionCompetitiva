#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long double> temps_suma_parcial;
    temps_suma_parcial.push_back(0);

    int temp, suma = 0;
    long double promedioMax = 0.0, promedio;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        suma += temp;
        temps_suma_parcial.push_back(suma);
    }
    for (; k <= n; k++)
    {
        for (int i = 0; i <= n - k; i++)
        {
            promedio = (temps_suma_parcial[i + k] - temps_suma_parcial[i]) / (long double)k;
            if (promedio > promedioMax)
                promedioMax = promedio;
        }
    }

    cout << setprecision(16) << promedioMax << endl;
    return 0;
}