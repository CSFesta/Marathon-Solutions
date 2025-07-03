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
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int x;
        char c, lixo;
        cin >> x >> c >> lixo;
        if(c == '2'){
            int total = 45;
            total += x;
            if(x > 45){
                cout  << 90 << "+" << x % 45 << "\n";
                continue;
            }
            cout << total << "\n";
            continue;
        }
        if(x > 45){
            cout << 45 << "+" << x % 45 << "\n";
            continue;
        }
        cout << x << "\n";
    }
    return 0;
}
