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
    int x1, x2, y1, y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        if(x1 == x2 && x2 == y1 && y1 == y2 && y2 == 0){
            break;
        }
        if(x1 == x2 && y1 == y2){  
            cout << 0 << "\n";
            continue;
        }
        if(x1 == x2 || y1 == y2 || (x1 + y1 == x2 + y2) || (x1 - y1 == x2 - y2)){
            cout << 1 << "\n";
            continue;
        }
        else{
            cout << 2 << "\n";
        }
    }
    return 0;
}
