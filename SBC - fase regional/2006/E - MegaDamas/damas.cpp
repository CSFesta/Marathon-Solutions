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


vector<pair<int, int>> dir = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int n, m;
int ans = 0;
void backtrack(vector<vector<int>> &g, int i, int j, int cap){
    ans = max(ans, cap);

    for(auto & [x, y] : dir){
        int x1 = x + i;
        int y1 = y + j;
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m){
            continue;
        }        

        if(g[x1][y1] == 2){
            int x2 = x1 + x;
            int y2 = y1 + y;
            
            if(x2 < 0 || y2 < 0 || x2 >= n || y2 >= m){
                continue;
            } 

            if(g[x2][y2] == 0){
                g[x1][y1] = 0;
                g[i][j] = 0;
                g[x2][y2] = 1;
                backtrack(g, x2, y2, cap + 1);
                g[x2][y2] = 0;
                g[i][j] = 1;
                g[x1][y1] = 2;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> n >> m && n > 0){
        ans = 0;
        vector<vector<int>> g(n, vector<int>(m));
        int count = 0;
        for(int row = n - 1; row >= 0; row--, count++){
            for(int col = 0 + (count % 2); col < m; col += 2){
                int cur; cin >> cur;
                g[row][col] = cur;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 1){
                    backtrack(g, i, j, 0);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
