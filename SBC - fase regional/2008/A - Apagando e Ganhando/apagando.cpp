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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n > 0)
    {
        string s;
        cin >> s;

        vector<int> stk;
        int remove = m;

        for (char c : s)
        {
            int d = c - '0';
            while (!stk.empty() && remove > 0 && stk.back() < d)
            {
                stk.pop_back();
                remove--;
            }
            stk.push_back(d);
        }

        while (remove > 0)
        {
            stk.pop_back();
            remove--;
        }

        for (int i = 0; i < n - m; i++)
            cout << stk[i];
        cout << "\n";
    }
    return 0;
}
