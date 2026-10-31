#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)

using namespace std;

#define abs(v) (v < 0 ? -v : v)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    ll techo = -1e10, piso = 1e10, paredIzq = 1e10, paredDer = -1e10;
    vector<pair<ll, ll>> reyes;
    forr(i, N)
    {
        ll x, y;
        cin >> x >> y;
        paredDer = max(paredDer, x);
        paredIzq = min(paredIzq, x);
        techo = max(techo, y);
        piso = min(piso, y);
        reyes.push_back({x, y});
    }
    ll horizontal = paredDer - paredIzq + 1, vertical = techo - piso + 1;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    ll maximaAdicion = 0;
    for (auto [x, y] : reyes)
    {
        ll movimientos = K;
        ll dTecho = techo - y, dPiso = y - piso;
        ll dIzq = x - paredIzq, dDer = paredDer - x;
        ll dMinima = min(min(dTecho, dPiso), min(dIzq, dDer));
        ll paralela, perpendicular, p;
        bool sube = dTecho < dPiso;
        bool derechiza = dDer < dIzq;
        movimientos -= dMinima;

        if (dTecho == dMinima)
        {
            x += (derechiza ? dTecho : -dTecho);
            y += dTecho;
            paralela = horizontal;
            perpendicular = vertical;
            p = min(paredDer - x, x - paredIzq);
        }
        else if (dPiso == dMinima)
        {
            x += (derechiza ? dPiso : -dPiso);
            y -= dPiso;
            paralela = horizontal;
            perpendicular = vertical;
            p = min(paredDer - x, x - paredIzq);
        }
        else if (dIzq == dMinima)
        {
            x -= dIzq;
            y += (sube ? dIzq : -dIzq);
            perpendicular = horizontal;
            paralela = vertical;
            p = min(techo - y, y - piso);
        }
        else
        {
            x += dDer;
            y += (sube ? dDer : -dDer);
            perpendicular = horizontal;
            paralela = vertical;
            p = min(techo - y, y - piso);
        }

        ll maximoEnK = p * paralela + (movimientos - p) * paralela + (movimientos - p) * (perpendicular + p) + (movimientos - p) + (movimientos - p - 1) * (movimientos - p);
        maximaAdicion = max(maximaAdicion, maximoEnK);
    }
    cout << (horizontal) * (vertical) + maximaAdicion << endl;
}