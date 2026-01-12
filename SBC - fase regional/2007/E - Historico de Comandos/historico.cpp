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
    int n;
    int MAXN = (int)1e6 + 3;

    while(cin >> n && n > 0){
        vector<int> pos(MAXN, INT_MAX);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(pos[x] == INT_MAX){
                ans += x + i - 1;
            }
            else{
                ans += i - pos[x] ;
            }

            pos[x] = i;
        }
        cout << ans << "\n";
    }
    return 0;
}
