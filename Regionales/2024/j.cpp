#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const double PI = 3.14159265358979323846;
    int ang,N; cin >> ang >>N;
    long double tang = tan(ang* PI / 180);
    set<pair<int,long double>>segs;
    int x,h;
    long double largo;
    forr(i,N){
        cin >> x >>h; 
        largo = h / tang;
        segs.insert({x,largo});
    }
    int inicio;
    long double total=0;
    long double ultimo=-1,final;
    for(auto t : segs){
        inicio = t.first;
        final = inicio + t.second;
        if(ultimo > inicio && final > ultimo){
            total+= t.second - (ultimo -inicio);
        }else if(final > ultimo){
            total+= t.second;
        }
        ultimo=max(inicio+t.second,ultimo);
    }
    cout <<fixed << setprecision(10) << total  <<endl;

}