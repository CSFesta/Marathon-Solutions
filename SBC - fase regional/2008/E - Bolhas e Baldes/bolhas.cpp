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

const int neutral = 0;
#define comp(a, b) ((a) + (b))
//fenwick
class FenwickTree{
private:
    vector<int> ft1, ft2;
    void update(vector<int> &ft, int i, int v){
        for(; i < (int)ft.size(); i += (i & -i)) ft[i] += v;
    }
    int rsq (vector<int> &ft, int i){
        int sum = 0;
        for(; i; i -= (i & -i)) sum += ft[i];
        return sum;
    }
public:
    FenwickTree(int n){
        ft1.assign(n + 1, 0);
        ft2.assign(n + 1, 0);
    }
    void update(int i, int j, int v){
        update(ft1, i, v);
        update(ft1, j + 1, -v);
        update(ft2, i, v*(i-1));
        update(ft2, j + 1, -v*j);
    }
    int rsq(int i){
        return rsq(ft1, i) * i - rsq(ft2, i);
    }
    int rsq(int i, int j){
        return rsq(j) - rsq(i - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n && n > 0){

        FenwickTree fw(n);
        vector<int> in(n + 1, 0);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            in[x] = i;
        }

        ll total = 0;
        for(int i = 1; i <= n; i++){
            int val = in[i] + fw.rsq(in[i], in[i]);
            if(val - i > 0){
                total += val - i;
                fw.update(1, in[i], 1); //aumenta de 1 -> in[i] += 1
            }    
        }
        if(total & 1) cout << "Marcelo\n";
        else cout << "Carlos\n";
    }
    return 0;
}
