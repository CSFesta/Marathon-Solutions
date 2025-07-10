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
    cin.sync_with_stdio(false);
    cin.tie(nullptr);    
    int64_t n;
    cin >> n;
    cout << ceil(log2(n * 1'000'000 * 8)) << "\n";
    return 0;
}



