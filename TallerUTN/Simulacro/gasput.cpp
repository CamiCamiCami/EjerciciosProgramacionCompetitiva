#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cantindad;
    cin >> cantindad;
    int actual, anterior, maxi = 1;
    vector<int> maxs(2, 0);
    cin >> anterior;
    maxs[anterior - 1]++;
    for (int i = 0; i < cantindad - 1; i++)
    {
        cin >> actual;
        if (actual != anterior)
        {
            maxi = max(maxi, min(maxs[0], maxs[1]));
            maxs[actual - 1] = 0;
        }
        maxs[actual - 1]++;
        anterior = actual;
    }
    maxi = max(maxi, min(maxs[0], maxs[1]));
    cout << (maxi * 2) << endl;
    return 0;
}
