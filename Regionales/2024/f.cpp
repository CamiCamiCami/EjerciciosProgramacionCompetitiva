#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, K;
    while(cin >> K >> N) {
        if((2*K -1) > N || N > (3*K)) {
            cout << "*" << endl;
        } else {
            ll simples = 3*K-N-1;
            simples = max(simples, 0LL);
            ll usados = 0;
            forr(i, simples) {
                cout << "X";
                usados++;
                if(usados < N) cout << "-";
                usados++;
            }
            forr(i, K-simples) {
                cout << "-X";
                usados += 2;
                if(usados < N) cout << "-";
                usados++;
            }
            cout << endl;
        }
    }
}