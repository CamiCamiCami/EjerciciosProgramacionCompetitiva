#include <iostream>
using namespace std;

int main()
{
    int casos;
    cin >> casos;
    int a, b;
    for (int i = 0; i < casos; i++)
    {
        cin >> a >> b;
        cout << b - a << '\n';
    }
}