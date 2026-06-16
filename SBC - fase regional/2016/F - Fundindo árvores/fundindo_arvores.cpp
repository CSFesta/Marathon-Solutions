#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define f first
#define s second

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const ll INF = 1e18;
using namespace std;

struct node{
    int mid, side;
};

int bfs(vector<node> &v, queue<pair<int, int>> &q){
    int ans = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int idx = cur.f;
        int qnt = cur.s;

        ans = max(ans, qnt);
        if(v[idx].mid != -1){
            q.push({v[idx].mid, qnt + 1});
        }
        if(v[idx].side != -1){
            q.push({v[idx].side, 1});
        }
    }
    return ans;
}

int root_mid_size(vector<node> &v){
    int ans = 1;
    int cur = 0;
    while(v[cur].mid != -1){
        cur = v[cur].mid;
        ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<node> v_l(n);

    for(int i = 0; i < n; i++){
        int u, l, m;
        cin >> u >> l >> m;
        u--; l--; m--;
        v_l[u] = {m , l};
    }
    
    int m;
    cin >> m;
    
    vector<node> v_r(m);
    for(int i = 0; i < m; i++){
        int u, m, r;
        cin >> u >> m >> r;
        u--; r--; m--;
        v_r[u] = {m , r};
    }
    

    queue<pair<int, int>> q_l;
    q_l.push({0, 1});
    
    queue<pair<int, int>> q_r;
    q_r.push({0, 1});
    
    int max_l = bfs(v_l, q_l);
    int max_r = bfs(v_r, q_r);
    int mid_l = root_mid_size(v_l);
    int mid_r = root_mid_size(v_r);
    // cout << n << " " << m << " " << max_l << " " << max_r << " " << mid_l << " " << mid_r << "\n";
    cout << (n + m) - max(min(max_r, mid_l), min(max_l, mid_r)) << "\n";

    return 0;
}
