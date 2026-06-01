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
    cin >> n;
    vector<int> v(n);
    for(auto & i : v) cin >> i;

    vector<int> esq(n), dir(n);
    esq[0] = 1;
    for(int i = 1; i < n; i++){
        esq[i] = min({i + 1, esq[i - 1] + 1, v[i]});
    }
    dir[n - 1] = 1;

    for(int i = n - 2, j = 2; i >= 0; i--, j++){
        dir[i] = min({j, dir[i + 1] + 1, v[i]});
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(min(esq[i], dir[i]), ans);
    }
    cout << ans << "\n";
    return 0;
}
