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

int m, n, c;

bool inside(vector<vector<int>> & g, int i, int j){
    return (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == 0) ? false : true;
}

int cont = 0;
void dfs(vector<vector<int>> &g, int i, int j){
    if(!inside(g, i, j)){
        return;
    }
    g[i][j] = 0;
    cont++;
    dfs(g, i + 1, j); //Move para baixo na grid  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> m >> n >> c && n > 0){
        vector<vector<int>> g(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
            }
        }

        int ans = 0;
        for(int col = 0; col < m; col++){
            for(int row = 0; row < n; row++){
                if(g[row][col] == 1){
                    cont = 0;
                    dfs(g, row, col);
                    if(cont >= c){ // se a quantidade de 1s seguidos verticalmente for >= c, aumenta ans
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
