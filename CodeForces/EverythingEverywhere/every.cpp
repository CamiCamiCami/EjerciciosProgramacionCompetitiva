#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int casos, n;
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        cin >> n;
        vector<int> permutacion(n);
        for(int j = 0; j < n; j++) {
            cin >> permutacion[j];
        }
        int buenos = 0;
        for(int j = 0; j < n-1; j++) {
            int d = abs(permutacion[j] - permutacion[j+1]);
            if((permutacion[j] % d == 0) && (permutacion[j+1] % d == 0)) {
                buenos++;
            }
        }
        cout << buenos << '\n';
    }
}