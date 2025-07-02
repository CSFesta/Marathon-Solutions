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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, q;
    cin >> n >> l >> q;
    
    int x = l;
    int val = n * q;
    l *= 1000;

    if(val % l == 0) cout << (val / l) * x << "\n";
    else cout << ((val / l) + 1) * x  << "\n";
    
    return 0;
}
