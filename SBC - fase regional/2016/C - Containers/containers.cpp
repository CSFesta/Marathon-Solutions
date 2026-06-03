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

int n = 2;
int m = 4;
vector<vector<int>> t(n, vector<int>(m));

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> v(n, vector<int>(m));
    for(auto & i : v) for(auto & j : i) cin >> j;
    for(auto & i : t) for(auto & j : i) cin >> j;
    
    
    priority_queue<
    pair<int, vector<vector<int>>>, //tipo
    vector<pair<int, vector<vector<int>>>>,
    greater<pair<int, vector<vector<int>>>>
    > pq;

    pq.push({0 , v});
    set<vector<vector<int>>> exist;

    while(!pq.empty()){
        vector<vector<int>> cur = pq.top().second;
        int peso = pq.top().first;
        pq.pop();
        if(exist.count(cur)){
            continue;
        }
        if(cur == t){
            cout << peso << "\n";
            return 0;
        }

        exist.insert(cur);

        for(int i = 0; i < n; i++){ //trocas horizontais
            for(int j = 0; j < m - 1; j++){
                swap(cur[i][j], cur[i][j + 1]);

                if(!exist.count(cur)){
                    pq.push({peso + cur[i][j] + cur[i][j + 1], cur});
                }
                
                swap(cur[i][j], cur[i][j + 1]);
            }
        }

        for(int j = 0; j < m; j++){ // trocas verticais

            swap(cur[0][j], cur[1][j]);

            if(!exist.count(cur)){
                    pq.push({peso + cur[0][j] + cur[1][j], cur});
            }

            swap(cur[0][j], cur[1][j]);
        }
        

        
    }

    return 0;
}
