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
    int N, L, C;
    while ( (cin >> N >> L >> C) ) {
        int lines = 1;          
        int cur = 0;          

        for (int i = 0; i < N; ++i) {
            string w;
            cin >> w;
            int len = (int)w.size();

            if (cur == 0) {
                cur = len;
            } else if (cur + 1 + len <= C) {
                cur += 1 + len;
            } else {
                ++lines;
                cur = len;
            }
        }

        int pages = (lines + L - 1) / L; 
        cout << pages << "\n";
    }
    return 0;
}
