#include <bits/stdc++.h>
using namespace std;

int main()
{
    int casos, x = 0;
    cin >> casos;
    string linea;
    for (int i = 0; i < casos; i++)
    {
        cin >> linea;
        if (linea[0] == '+' || linea[1] == '+')
            x++;
        else
            x--;
    }
    cout << x << '\n';

    return 0;
}