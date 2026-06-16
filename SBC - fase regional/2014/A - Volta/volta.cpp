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
    int n, m;
    cin >> n >> m;
    int aux1 = n;
    int aux2 = m;
    int i = 1;
    for(;; i++){
        if(abs(n - m) >= aux2){
            break;
        }
        n += aux1;
        m += aux2;
    }
    cout << i << "\n";
    return 0;
}
