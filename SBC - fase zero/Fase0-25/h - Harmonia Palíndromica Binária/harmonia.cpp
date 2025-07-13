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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;

    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }

    string str = bitset<64>(n).to_string(); // transforma decimal para binario 
    str.erase(0, str.find_first_not_of('0')); // remove os valores 0 até encontrar o primeiro 1

    if(count(all(str), '1') == 1){ // se "10000" ans = "1111"
        cout << n - 1;
        return 0;
    }

    int m = str.size();

    string ans(m, '0'); 
    ans[0] = '1';
    ans[m - 1] = '1';
    // ans =  menor palindromo possivel (inicialmente)

    for(int i = 1; i < (m + 1) / 2; i++){
        ans[i] = '1';
        ans[m - i - 1] = '1';
        if(stoll(ans, nullptr, 2) > n){ // adiciona se for menor q N, assim pegando o maior palindromo possivel < n
            ans[i] = '0';
            ans[m - i - 1] = '0';
        }
    }

    cout << stoll(ans, nullptr, 2) << "\n"; // passa e binario para decimal
    return 0;
}
