#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)
#define techo(n, d) ((n + d - 1) / d)

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
    bool cuadrado = horizontal == vertical;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    ll maxima = 0;
    ll mov = K, tHor = horizontal, tVer = vertical;
    while (mov)
    {
        if (tHor < tVer)
        {
            tHor++;
        }
        else if (tVer < tHor)
        {
            tVer++;
        }
        else
        {
            maxima += (tHor + techo(mov, 2)) * (tVer + (mov / 2));
            mov = 1;
        }
        mov--;
    }

    for (auto [x, y] : reyes)
    {
        ll dTecho = techo - y, dPiso = y - piso;
        ll dIzq = x - paredIzq, dDer = paredDer - x;
        ll dMinima = min(min(dTecho, dPiso), min(dIzq, dDer));
        ll paralela, perpendicular, p;
        bool sube = dTecho < dPiso;
        bool derechiza = dDer < dIzq;
        x += (derechiza ? 1 : -1) * K;
        y += (sube ? 1 : -1) * K;

        ll nTecho = max(techo, y), nPiso = min(piso, y), nIzq = min(paredIzq, x), nDer = max(paredDer, x);
        ll maximoEnK = (nTecho - nPiso + 1) * (nDer - nIzq + 1);
        maxima = max(maxima, maximoEnK);
    }
    cout << maxima << endl;
}