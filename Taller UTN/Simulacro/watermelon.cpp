#include <iostream>
using namespace std;
#define ll long long
#define FORI(i, d, n) for (int i = d; i < n; i++)

int main()
{
    ll w;
    cin >> w;
    cout << ((w > 2 && w % 2 == 0) ? "YES" : "NO") << endl;
}