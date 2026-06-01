
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

vector<ll> get_divisors(ll n){
    vector<ll> divs;

    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            divs.pb(i);
            if(i * i != n) divs.pb(n / i);
        }
    }
    return divs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    // A = divisor
    // B = Nao divisor (edge case)
    // C = Multiplo
    // D = Nao multiplo (edge case) 

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<ll> divs = get_divisors(c); // n esta entre os divs
    sort(all(divs));

    for(auto & i : divs){
        if(i % a == 0 && i % b != 0 && d % i != 0){
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}
