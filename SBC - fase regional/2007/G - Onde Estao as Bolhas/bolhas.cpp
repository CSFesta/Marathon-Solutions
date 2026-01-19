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

void out(vector<int> &ans){
    int n = ans.size();
    cout << ans[0];
    for(int i = 1; i < n; i++){
        cout << " " << ans[i];
    }
    cout << "\n";
}

int main(){ //Solução O(N)
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m && n > 0){
        vector<int> ans(n);
        if(m == 0){ //Edge Case
            iota(all(ans), 1);
            out(ans);
            continue;
        }
        int ans_idx = 0;
        vector<int> v(m); for(auto & i : v) cin >> i;

        deque<int> mn(m + 1); // m menores valores de v
        deque<int> mx(n - m - 1); // n - m - 1 maiores valores de (m + 2) -> n
        vector<bool> vis(n + 1);

        iota(all(mn), 1);
        iota(all(mx), m + 2);

        for(int i = m - 1; i >= 1; i--){
            v[i] -= ans_idx;
            if(v[i] <= 0){
                mx.emplace_front(mn.back());
                mn.pop_back();
                continue;
            }
            for(int j = 0; j < v[i]; j++){
                if(j == 0){
                    int cur = mn.back(); mn.pop_back();
                    ans[ans_idx++] = cur;
                    vis[cur] = true;
                }
                else{
                    int cur = mx.front(); mx.pop_front();
                    ans[ans_idx++] = cur;
                    vis[cur] = true;
                }
            }
        }
        ans[v[0]] = 1; 
        vis[1] = true;
        for(int i = 1; i <= n; i++){
            while(ans[ans_idx] != 0) ans_idx++;
            if(!vis[i]){
                ans[ans_idx++] = i; 
                vis[i] = true;
            }

        }

        out(ans);
    }    
    return 0;
}
