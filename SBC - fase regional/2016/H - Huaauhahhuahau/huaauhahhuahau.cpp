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
    
    string str;
    cin >> str;
    
    bool can = true;
    unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
    
    string s = "";
    
    for(auto c : str){
        if(v.count(c)){
            s.pb(c);
        }
    }
    int n = s.size();

    for(int l = 0, r = n - 1; l < r; l++, r--){
        if(s[l] != s[r]) {
            can = false;
        }
    }

    if(can) cout << "S\n";
    else cout << "N\n";

    return 0;
}
