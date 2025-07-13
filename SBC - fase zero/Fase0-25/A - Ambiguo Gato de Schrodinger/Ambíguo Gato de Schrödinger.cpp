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

    int n, m;
    cin >> n >> m;
    if(n){
        cout << "vivo e morto\n";
        return 0;
    }
    if(m){
        cout << "vivo\n";
        return 0;
    }
    cout << "morto\n";
    
    return 0;
}

