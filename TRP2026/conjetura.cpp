#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool es_primo(int x) {
    for (int i = 2; i < x/2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, x, y;
    cin >> n;
    if (n % 2 == 0) {
        x = y = n / 2;
        if (es_primo(x)) {
            x = x-1; y = y+1;
        }
    } else {
        x = n - 9;
        y = 9;
    }
    cout << x << " " << y << endl;
    return 0; 
}

