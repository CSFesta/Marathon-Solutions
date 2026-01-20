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

struct magic{
    int mana, dano;
};

struct node{
    vector<int> adj;
    int w = 0;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, g, k;
    while(cin >> m >> n >> g >> k){
        if(n == 0 && m == 0 && g == 0 && k == 0){
            break;
        }
        vector<magic> magias(m);
        vector<node> graph(n);

        for(auto & i : magias) cin >> i.mana >> i.dano;
        for(int i = 0; i < g; i++){
            int u, v; cin >> u >> v; u--; v--;
            graph[u].adj.pb(v);
            graph[v].adj.pb(u);
        }
        vector<int> dp(1001, INT_MAX); // i = vida diferente | j = mana necessaria
        for(int i = 1; i <= 1000; i++){
            for(int j = 0; j < m; j++){
                auto cur = magias[j];
                if(cur.dano >= i){
                    dp[i] = min(dp[i], cur.mana);
                }
                else{
                    dp[i] = min(dp[i], dp[i - cur.dano] + cur.mana);
                }
            }
        }



        for(int i = 0; i < k; i++){
            int u, life;
            cin >> u >> life;
            u--;
            graph[u].w += dp[life]; // mana gasta para passar por esse vertice
        }

        // for(auto & i : graph){
        //     cout << i.w << " ";
        // }
        // cout << "\n";
        
        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > pq; // mana | vertice v

        vector<ll> dist(n, LLONG_MAX);
        pq.emplace(graph[0].w, 0); 
        dist[0] = graph[0].w;

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            
            int u = cur.second;
            if(u == n - 1){
                continue;
            } 

            for(int i = 0; i < graph[u].adj.size(); i++){

                int v = graph[u].adj[i];
                int w1 = graph[v].w;
                                
                if(dist[v] > dist[u] + w1){
                    dist[v] = dist[u] + w1;
                    pq.emplace(dist[v], v);
                }
            }
        }

      

        if(dist[n - 1] == LLONG_MAX){
            cout << -1 << "\n";
            continue;
        }
        cout << dist[n - 1] << "\n";
        
    }
    return 0;
}
