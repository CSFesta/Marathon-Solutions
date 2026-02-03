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

ll calc(map<int, ll> &mp, ll total, int n){
    ll tabuas = 0;
    ll linhas = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        auto [val, qnt] = *it;
        if(n == val){
            if(qnt >= total){
                return total;
            }
            tabuas = qnt;
            linhas = qnt;
        }
        else if(val * 2 == n){
            qnt /= 2;
            ll mn = min({total - linhas, qnt});
            tabuas += mn * 2;
            linhas += mn;
            mp[val] = 0;
        }
        else if(val < n){
            int val2 = n - val;
            ll qnt2 = mp[n - val];
            

            ll mn = min({total - linhas, qnt2, qnt });
            tabuas += mn * 2;
            linhas += mn;

            mp[val] = 0;
            mp[val2] = 0;
        }
        if(linhas == total) return tabuas;
    }
    return LLONG_MAX;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, l, k;
    while(cin >> n >> m && n > 0){
        cin >> l >> k; 
        ll menor = LLONG_MAX;
        map<int, ll> mp;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        map<int, ll> mp1 = mp;

        if((100 * n) % l == 0){ //vertical
            ll total = (100 * n) / l;
            menor = min(menor , calc(mp, total, m));
        }
        if((100 * m) % l == 0){ //horizontal
            ll total = (100 * m) / l;
            menor = min(menor , calc(mp1, total, n));

        }
        if(menor == LLONG_MAX){
            cout << "impossivel\n";
        }
        else{
            cout << menor << "\n";
        }
    }    
    return 0;
}
