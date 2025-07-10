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
       
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    double count1 = 0;
    double count2 = 0;
    for(auto & i : str1){
        if(i == '*') count1++;
    }
    for(auto & i : str2){
        if(i == '*') count2++;
    }
    cout << fixed << setprecision(2) << 1 - count2/count1 << "\n";

    return 0;
}



