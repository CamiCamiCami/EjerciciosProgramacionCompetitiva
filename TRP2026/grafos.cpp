#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;


int Dijkstra(Grafo g, ll inicial, ll objetivo, ll nodos)
{
    vector<ll> pesos(nodos, -1);
    vector<bool> visitados(nodos, false);
    pesos[inicial] = 0;
    priority_queue<pair<ll,ll>> queue;
    queue.push({inicial, 0});
    while (!queue.empty())
    {
        ll actual = queue.top().first;
        ll pesoActual = queue.top().second;
        queue.pop();
        visitados[actual] = true;
        if(pesos[actual] != pesoActual) continue;
        for (auto conexion : g[actual])
        {
            ll peso = conexion.second;
            ll vecino = conexion.first;
            if (peso == -1)
                continue;
            if (pesos[vecino] == -1 || pesos[vecino] > peso + pesos[actual])
            {
                pesos[vecino] = peso + pesos[actual];
                queue.push({vecino, pesos[vecino]});
            }
        }
    }
    return pesos[objetivo];
}

int main()
{
    ll ciudades, calles;
    cin >> ciudades >> calles;
    Grafo g(ciudades, vector<pair<ll,ll>>(0));
    for (int i = 0; i < calles; i++)
    {
        ll C1, C2, peso;
        cin >> C1 >> C2 >> peso;
        g[C1-1].push_back({C2-1, peso});
        g[C2-1].push_back({C1-1, peso});
    }
    cout << Dijkstra(g, 0, ciudades - 1, ciudades) << endl;
}
