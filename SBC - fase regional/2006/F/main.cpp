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
    while(cin >> n >> m && n > 0){
        string str;
        int total = m * 3;
        int soma = 0;
        int cur;
        for(int i = 0; i < n; i++){
            cin >> str;
            cin >> cur;
            soma += cur;
        }
        cout << total - soma << "\n";
    }
    return 0;
}
