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
    ll k;
    cin >> n >> k;
    vector<ll> v(n * 2);
    for(int i = 0; i < n; i++){ 
        cin >> v[i];
        v[i + n] = v[i]; //duplicar o v
    }

    stack<pair<ll, int>> stk; //val, pos
    int m = v.size();
    vector<int> ans(n);
    for(int i = 0; i < m; i++){
        if(stk.empty()){
            if(i < n){
                stk.push({v[i], i});
                continue;
            }
            break;
        }

        ll val = stk.top().first + (k * (i - stk.top().second)); 
        if(v[i] >= val && i < n){
            stk.push({v[i], i});
            continue;
        }
        while(v[i] < val){
            ans[stk.top().second] = (i % n) + 1;
            stk.pop();
            if(stk.empty()){
                break;
            }
            val = stk.top().first + (k * (i - stk.top().second));
        }
        if(i < n){
            stk.push({v[i], i});
        }
    }

     for(int i = 0; i < n; i++){
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
