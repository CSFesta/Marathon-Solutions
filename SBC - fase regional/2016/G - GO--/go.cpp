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

ll query(vector<vector<ll>> &pref, int x1, int y1, int x2, int y2){ // 1 indexed (1 <= n)
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

vector<vector<ll>> build(vector<vector<ll>> &a){ //considerando a 0-index
    int n = a.size();
    int m = a[0].size();

    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0)); 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
    return pref;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q; 
    cin >> n >> q;
    vector<vector<ll>> black(n, vector<ll>(n));
    vector<vector<ll>> white(n, vector<ll>(n));

    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        black[x][y] = 1;
    }

    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        white[x][y] = 1;
    }

    vector<vector<ll>> b_pref = build(black); //1 indexed
    vector<vector<ll>> w_pref = build(white); //1 indexed

    int ans_b = q, ans_w = q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            for(int k = 2; k <= n; k++ ){
                int x1 = i;
                int y1 = j;
                int x2 = i + k - 1;
                int y2 = j + k - 1;

                if(x2 > n || y2 > n){
                    break;
                }

                ll qnt_b = query(b_pref, x1, y1, x2, y2);
                ll qnt_w = query(w_pref, x1, y1, x2, y2);
                
                if(qnt_b > 0 && qnt_w > 0){
                    break;
                }

                if(qnt_b > 0){
                    ans_b++;
                }
                if(qnt_w > 0){
                    ans_w++;
                }
            }
        }
    }

    cout << ans_b << " " << ans_w << "\n";
    return 0;
}
