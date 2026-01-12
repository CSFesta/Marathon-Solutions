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
    while(cin >> n && n > 0){
        int sobra = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int l, qnt; cin >> l >> qnt;
            ans += qnt / 4;
            qnt %= 4;
            if(qnt >= 2){
                sobra += 2;
            }
        }
        ans += sobra / 4;
       
        cout << ans << "\n";
    }
    cout << "\n";
    return 0;
}
