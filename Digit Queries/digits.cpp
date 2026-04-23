#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int queries;
    cin >> queries;
    long long k, numbersWithDigits, positionsCovered, digits, number;
    int digitInNbr, result;
    for (int i = 0; i < queries; i++)
    {
        cin >> k;
        if (k < 10) {
            cout << k << '\n';
            continue;
        }
        digits = 1;
        numbersWithDigits = positionsCovered = 9;
        while (positionsCovered < k)
        {
            k -= positionsCovered;
            digits++;
            numbersWithDigits *= 10;
            positionsCovered = numbersWithDigits * digits;
        }

        number = ((long long)pow(10, digits - 1)) + ((long long)(k - 1) / digits);
        digitInNbr = k - (number - (long long)pow(10, digits - 1)) * digits;
        result = ((long long)(number / ((long long)pow(10.0, (double)(digits - digitInNbr))))) % 10;
        cout << result << '\n';
    }

    return 0;
}