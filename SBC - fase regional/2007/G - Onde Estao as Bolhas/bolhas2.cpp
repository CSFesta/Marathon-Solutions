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
    int n, m;
    while(cin >> n >> m && n > 0){
        vector<int> v(m);
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }
        if(m == 0){
            for(int i = 1; i <= n; i++){
                cout << i;
                if(i != n){
                    cout << " ";
                }
            }
            cout << "\n";
            continue;
        }
        if(n == 1) {
            cout << 1 << "\n";
            continue;
        }
        vector<int> ans(n, 0);
        vector<bool> vis(n + 1);
        vis[0] = true;
        vis[1] = true; // lidado
        int count = 0;
        
        set<int> others;
        for(int i = 1; i <= n; i++){
            others.insert(i);
        }
        others.erase(1); // lidado
        for(int i = m - 1; i >= 1; i--){
            int atual = i + 2;
            int loops = v[i] - count;
            if((i != m - 1 && v[i] == v[i + 1]) || loops <= 0 || vis[atual]) continue;
            
            auto it = others.find(atual);
            
            for(int j = 0; j < loops; j++, count++){
                ans[count] = atual;
                vis[atual] = true;
                it++;
                others.erase(atual);
                atual = *it;
            }
        }
        ans[v[0]] = 1;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                others.insert(i);
            }
        }
        auto it = others.begin();
        for(int i = 0; i < n; i++){
            if(ans[i] == 0){
                int x = *it++;
                ans[i] = x;
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i];
            if(i != n - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
