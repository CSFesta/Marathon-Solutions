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

#define MAXN 1009
#define UNVISITED -1

int num[MAXN], N, low[MAXN], parent[MAXN], counter, rootChildren, root;
vector<int> adjList[MAXN];


bool hasBridge;

void tarjan(int u){
    low[u] = num[u] = counter++;
    for(int j = 0, v; j < (int)adjList[u].size(); j++){

        v = adjList[u][j];

        if(num[v] == UNVISITED){
            parent[v] = u;
            if(u == root) rootChildren++;

            tarjan(v);

            if(low[v] > num[u]) {
                hasBridge = true;
            }

            low[u] = min(low[u], low[v]);
        }
        else if(v != parent[u]){
            low[u] = min(low[u], num[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    while(cin >> a >> b && a > 0){

        hasBridge = false;
        N = a;

        for (int i = 0; i < N; i++)
            adjList[i].clear();
        for(int j = 0; j < b; j++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        counter = 0;
        memset(&num, UNVISITED, sizeof num);
        memset(&low, 0, sizeof low);
        memset(&parent, 0, sizeof parent);


        for(int i = 0; i < N; i++){
            if(num[i] == UNVISITED){
                root = i;
                rootChildren = 0;
                tarjan(i);
            }
        }
        if(hasBridge) cout << "N\n";
        else cout << "S\n";
    }
    cout << "\n";


    return 0;
}
