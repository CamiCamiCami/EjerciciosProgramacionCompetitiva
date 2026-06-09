#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool sepuede(pair<int,int> rango,pair<int,int>tabla){
    if(tabla.first > rango.second )
        return false;
    return true;
}

int main() {
    ll cant; 
    cin >> cant;
    set<pair<int,int>>tablas;
    int x,y;
    for(int i =0 ;i< cant ;i++){
        cin >> x >> y;
        tablas.insert({x,y});
    }
    pair<int,int> rango = {-1,-1};
    int clavos=-1;
    for(pair<int,int> clavo : tablas) {
        if(sepuede(rango,clavo)){
            rango={clavo.first,min(rango.second,clavo.second)};
        }else{
            clavos++;
            rango = clavo;
        }

    }
    cout << (clavos+1) << endl;
    return 0;
}

