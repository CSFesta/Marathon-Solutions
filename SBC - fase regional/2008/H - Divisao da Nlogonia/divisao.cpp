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
    int n;
    while(cin >> n && n > 0){
        int x1, y1;
        cin >> x1 >> y1;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            if(x == x1 || y == y1){
                cout << "divisa\n";
                continue;
            }
            if(x > x1 && y > y1){
                cout << "NE\n";
            }
            else if(x > x1 && y < y1){
                cout << "SE\n";
            }
            else if(x < x1 && y > y1){
                cout << "NO\n";
            }
            else if(x < x1 && y < y1){
                cout << "SO\n";
            }
        }        
    }
    return 0;
}
