#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int l = s.length();
    set<char> letras = {};
    for (int i = l-1; i >= 0; i--) {
        letras.insert(s[i]);
    }

    cout << l - letras.size() << endl;

}