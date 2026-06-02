#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool hayMatch(long long buscado, long long presente, long long margen) {
    return (presente - margen) <= buscado  &&  buscado <= (presente + margen);
}


int main() {
    long long personas, dptos, tolerancia, numero, parejas = 0;
    cin >> personas >> dptos >> tolerancia;
    vector<long long> prefPersonas, tamDpto;
    for(int i = 0; i < personas; i++) {
        cin >> numero;
        prefPersonas.push_back(numero);
    }
    for(int i = 0; i < dptos; i++) {
        cin >> numero;
        tamDpto.push_back(numero);
    }
    sort(prefPersonas.begin(), prefPersonas.end());
    sort(tamDpto.begin(), tamDpto.end());
    for(int p = 0, d = 0; p < personas && d < dptos; p++) {
        for(; d < dptos && !hayMatch(prefPersonas[p],tamDpto[d],tolerancia) && tamDpto[d]<=prefPersonas[p]; d++);
        if (hayMatch(prefPersonas[p],tamDpto[d],tolerancia)) {
            parejas++;
        
            d++;
        }
    }
    cout << parejas << '\n';


}