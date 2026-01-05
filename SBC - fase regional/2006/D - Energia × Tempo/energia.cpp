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

ll n, m, e_troca, ms_troca;

struct no{
    ll e, ms, w = INF;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> m >> n >> e_troca >> ms_troca && n > 0){
        vector<vector<no>> dp(n, vector<no>(m));
        ll val_troca = e_troca * ms_troca;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> dp[i][j].e >> dp[i][j].ms;
                
                if(i == 0){
                    dp[0][j].w = dp[0][j].e * dp[0][j].ms + val_troca;
                }
            }
        }
        dp[0][0].w = dp[0][0].e * dp[0][0].ms;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    auto prev = dp[i - 1][k];
                    auto cur = dp[i][j];

                    ll val = 1LL* (cur.e * cur.ms) + prev.w;
                    if(j == k){
                        dp[i][j].w = min(dp[i][j].w, val);
                    }
                    else{
                        dp[i][j].w = min(dp[i][j].w, val + val_troca);
                    }
                }
            }
        }

        ll menor = INF;
        for(int col = 0; col < m; col++){
            menor = min(menor, dp[n - 1][col].w);            
        }
        cout << menor << "\n";
    }
    
    return 0;
}
