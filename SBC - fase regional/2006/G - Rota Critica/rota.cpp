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

int n, m;
void dfs(vector<unordered_map<int, int>> &g, vector<bool> & vis, int u){
    vis[u] = true;
    if(u == 0){
        return;
    }

    for(auto & [v, qnt] : g[u]){
        if(qnt)
            if(!vis[v])
                dfs(g, vis, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> m && n > 0){
        unordered_map<string, int> vals; // transforma o input de str -> int
        vector<string> cidades(n); // destransforma de int -> str

        for(int i = 0; i < n; i++){
            string u;
            cin >> u;
            vals.insert({u, i});
            cidades[i] = u;
        }

        vector<unordered_map<int, int>> g(n);
        vector<pair<int, int>> in(m);
        for(int i = 0; i < m; i++){
            string u, v;
            cin >> u >> v;
            int u1 = vals[u];
            int v1 = vals[v];
            g[u1][v1]++; // contagem de quantos caminhos tem de u -> v, caso seja > 1, com certeza nenhum deles será um edge critico
            in[i] = {u1, v1};
        }

        bool reach = false; // ja encontrou alguma vez o index 0 (capital)
        for(auto & [u1, v1] : in){ 
            if(g[u1][v1] > 1){
                continue;
            }
            vector<bool> vis(n, false);
            g[u1][v1] = 0; // desconsidera a edge atual, para nao atrapalhar no dfs
            dfs(g, vis, u1);
            g[u1][v1] = 1; // volta edge para as proximas buscas
            if(!vis[0]){ // se nao encontrar, sao edges criticos
                reach = true;
                cout << cidades[u1] << " " << cidades[v1] << "\n";
            }
        }
        
        if(!reach){
            cout << "Nenhuma\n";
        }
        cout << "\n";

    }
    return 0;
}
