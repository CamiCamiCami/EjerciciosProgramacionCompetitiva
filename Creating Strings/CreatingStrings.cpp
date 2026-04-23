#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

tuple<char, int> chars[8];
int uniqueChars;
int totalChars;


long long factorial(long long n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}


long long permutaciónRepetición(int n) {
    long long resultado = factorial(n);
    for (int i = 0; i < uniqueChars; i++) {
        resultado /= factorial(get<1>(chars[i]));
    }
    
    return resultado;
}


void agregarChar(map<char, int>& charCount, char c) {
    if (charCount.count(c) == 0) {
        charCount[c] = 1;
    } else {
        charCount[c]++;
    }
}


void listarPermutaciones(string construido, int profundidad = 0) {
    if (profundidad == totalChars) {
        std::cout << construido << std::endl;
        return;
    }

    for(int i = 0; i < uniqueChars; i++) {
        if (get<1>(chars[i]) > 0) {
            get<1>(chars[i])--;
            listarPermutaciones(construido + get<0>(chars[i]), profundidad + 1);
            get<1>(chars[i])++;
        }
    }
}



int main() {
    string s;
    cin >> s;
    map<char, int> charCount;

    for(char &c : s) {
        agregarChar(charCount, c);
    }
    int index = 0;
    for (auto it = charCount.begin(); it != charCount.end(); ++it)
    {
        chars[index] = make_tuple(it->first, it->second);
        index++;
    }
    uniqueChars = charCount.size();
    totalChars = s.size();
    sort(chars, chars + uniqueChars);
    
    std::cout << permutaciónRepetición(s.size()) << std::endl;
    listarPermutaciones("");

    return 0;
}
