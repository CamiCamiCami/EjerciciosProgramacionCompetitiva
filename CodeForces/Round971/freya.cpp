#include <bits/stdc++.h>
using namespace std;

#define techo(x, k) ((x + k - 1)/k)

int main()
{
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int pasosX = techo(x, k);
        int pasosY = techo(y, k);
        if (pasosY < pasosX)
        {
            cout << (2 * pasosX)-1 << endl;
        }
        else
        {
            cout << 2 * pasosY << endl;
        }
    }
}