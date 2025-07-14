#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
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

    vector<unordered_map<int, ll>> dp(5);
    dp[0][0] = 1;
    for(int i = 0; i < v.size(); i++){
        for(int j = 3; j >= 0; j--){
            for(auto & [sum, qnt] : dp[j]){
                dp[j + 1][sum + v[i]]+= qnt;
            }
        }
    } 

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        cout << dp[4][x] << "\n";
    }
    return 0;
}
