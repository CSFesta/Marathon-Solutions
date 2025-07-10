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

//Pega todos os divisores de Y
vector<int> divisores(ll y){ //O(sqrt(Y))
    vector<int> vec;
    for(int i = 1; i * i <= y; i++){
        if(y % i == 0){
            vec.push_back(i);
            if(i * i != y){
                vec.push_back(y / i);
            }
        }
    }
    return vec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll y, k;
    cin >> y >> k;
    vector<int> divs = divisores(y);
    //ordena todos divisores
    sort(divs.begin(), divs.end());
    
    ll x = 1;
    
    for(int i = 1; i < divs.size(); i++){
        if(k == 0){
            break;
        }
        if(divs[i] % x == 0){ // Aumentar o valor de x, até encontrar o próximo divisor em comum que x pode chegar
            ll passos_maximos = (divs[i] / x) - 1;
            x += (x * min(passos_maximos, k));
            k -= min(passos_maximos, k);
        }
    }
    x += (x * k);
    cout << x << "\n";
    return 0;
}
