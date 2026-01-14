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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    while(cin >> n >> p && n > 0){
        vector<vector<int>> in(p);
        vector<vector<int>> caixas(p);
        int x, y;
        
        for(int i = 0; i < p; i++){
            int q;
            cin >> q;
            for(int j = 0; j < q; j++){
                int idx; cin >> idx;
                in[i].pb((idx == 1) ? 1 : 0);
                if(idx == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        for(int i = 0; i < p; i++){
            for(int j = y; j < in[i].size(); j++){
                caixas[i].pb(in[i][j]);
            }
        }
        int total = caixas[x].size() - 1;
        int soma1 = 0;
        int soma2 = 0;
        for(int i = x - 1; i >= 0; i--){
            if(caixas[i].size() == 0){
                break;
            }
            soma1 += caixas[i].size();
        }
        for(int i = x + 1; i < p; i++){
            if(caixas[i].size() == 0){
                break;
            }
            soma2 += caixas[i].size();
        }

        total += min(soma1, soma2);
        cout << total << "\n";
       
    }
    return 0;
}
