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
    while (cin >> n >> m && n > 0) {

        vector<ll> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        int ans = n;          
        int l = 0;

        for (int r = 0; r < m; r++) {
            while (a[r] - a[l] >= n) {
                l++;
            }
            int livres_no_intervalo = r - l + 1;
            ans = min(ans, n - livres_no_intervalo);
        }

        cout << ans << "\n";
    }    

    return 0;
}
