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
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];

    sort(all(v));
    if( ( v[0] == v[1] || v[1] == v[2] ) || v[0] + v[1] == v[2]){
        cout << "S\n";
    }
    else{
        cout << "N\n";
    }
    return 0;
}
