#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string S;
    cin >> S;
    int co = 0;
    int largo = S.size();
    for (int i = 0; i < largo - 1; i++)
    {
        if (S[i] == 'h' && S[i + 1] == 'a')
        {
            co++;
        }
    }
    for (int i = 0; i < largo - 4; i++)
    {
        if (S[i] == 'b' && S[i + 1] == 'o' && S[i + 2] == 'o' && S[i + 3] == 'o' && S[i + 4] == 'o')
        {
            co--;
        }
    }
    for (int i = 0; i < largo - 4; i++)
    {
        if (S[i] == 'b' && S[i + 1] == 'r' && S[i + 2] == 'a' && S[i + 3] == 'v' && S[i + 4] == 'o')
        {
            co += 3;
        }
    }

    cout << co << endl;
}