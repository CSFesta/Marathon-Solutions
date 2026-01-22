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
        vector<int> v(n);
        for(auto & i : v) cin >> i;
        int ans = 2;
        bool dir = v[1] > v[0];
        for(int i = 2; i < n; i++){
            if(dir){
                if(v[i] < v[i - 1]){
                    dir = false;
                    ans++;
                }  
            }
            else{
                if(v[i] > v[i - 1]){
                    dir = true;
                    ans++;
                }
            }
        }
        if(ans & 1) ans--;
        cout << ans << "\n";
    }
    return 0;
}
