#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll N;
    cin >> N;
    ll contador = 0, maximo = 0;
    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;
        if (maximo < num)
            contador++;
        maximo = max(maximo, num);
    }
    cout << contador << endl;
}