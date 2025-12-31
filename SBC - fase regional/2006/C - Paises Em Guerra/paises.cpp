#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const ll INF = 1e18;
using namespace std;

void fw(vector<vector<int>> &g){ //algoritmo floyd warshall
    int n = g.size();
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][k] == INT_MAX || g[k][j] == INT_MAX){ // cuidar com overflow
                    continue;
                }
                g[i][j] = min(g[i][j], (g[i][k] + g[k][j]));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m && n > 0){
        
        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
    
        for(int i = 0; i < m; i++){
            int u, v, h;
            cin >> u >> v >> h; u--; v--;
    
            if(g[v][u] != INT_MAX){ //se uma cidade tem conexão direta de (u -> v) e (v -> u), viagem leva 0h para ambos lados
                g[u][v] = 0;
                g[v][u] = 0;
            }
            else{
                g[u][v] = min(g[u][v], h); //pode haver + de 1 caminho direto de u -> v, com pesos distintos
            }
        }
    
        for(int i = 0; i < n; i++){ // para ir de uma cidade para ela mesma, sempre custara 0
            g[i][i] = 0;
        }
        fw(g);
        
        int q; cin >> q;
        for(int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v; u--; v--;
            cout << ((g[u][v] == INT_MAX) ? "Nao e possivel entregar a carta" : to_string(g[u][v])) << "\n";
        }
        cout << "\n";
    }
    

    return 0;
}
