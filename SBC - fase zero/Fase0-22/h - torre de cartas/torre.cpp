#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 1e18;
using namespace std;


ll cartas(ll n) {
    return (3 * n * n + n) / 2;
}

ll binary_search(ll target){ 
    ll r = (ll)1e9; // Limite superior seguro (não chega a 1e18 em cartas)
    ll l = 1;
    ll ans = 0;

    while(l <= r){
        ll mid = l + (r - l) / 2;
        ll val = cartas(mid);
        
        if(val <= target){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll C;
        cin >> C;
        cout << binary_search(C) << '\n';
    }
    
    return 0;
}





