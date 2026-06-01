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
int cur = 0;
int n, m;

void dfs(vector<vector<int>> &v, int i, int j, int procura){
    if(i < 0 || j < 0 || i >= n || j >= m || v[i][j] != procura){
        return;
    }
    cur++;
    v[i][j] = -1;
    dfs(v, i + 1, j, procura);
    dfs(v, i - 1, j, procura);
    dfs(v, i, j + 1, procura);
    dfs(v, i, j - 1, procura);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for(auto & i : v){
        for(auto & j : i){
            cin >> j;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] != -1){
                cur = 0;
                dfs(v, i, j, v[i][j]);
                ans = min(ans, cur);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
