#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())

using namespace std;

const int LIM = 65536;
using pii = pair<ll,ll>;

vector<vector<pii>> DIRS = {
    { {0,-1}, {-1,0}, {0,1}, {1,0} }, // D L U R
    { {-1,0}, {0,1}, {1,0}, {0,-1} }, // L U R D
    { {0,1}, {1,0}, {0,-1}, {-1,0} }, // U R D L
    { {1,0}, {0,-1}, {-1,0}, {0,1} }  // R D L U
};
ll a, b, q;

int sideOfLine(ll x, ll y) {
    ll val = y - (a * x + b);

    if (val == 0) return 0;   // na reta
    if (val > 0)  return 1;   // acima da reta
                  return -1;  // abaixo da reta
}

vector<pii> generate_spiral(int n, int tipo) { // n = limite, tipo = index de DIRS
    auto dir = DIRS[tipo];
    int x = 0, y = 0;
    vector<pii> path;

    int val = 1;
    int passos = 1;
    int d = 0;

    while (val <= n) {
        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < passos && val <= n; i++) {
                if(sideOfLine(x, y) != 0){
                    path.emplace_back(x, y);
                    val++;
                    
                }               
                x += dir[d].first;
                y += dir[d].second;
            }
            d = (d + 1) % 4;
        }
        passos++;
    }
    return path;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Caso " << i + 1 << "\n";
        cin >> a >> b;

        vector<pii> espiral = generate_spiral(LIM, 1);
        cin >> q;
        for(int i = 0; i < q; i++){
            int a, b;
            cin >> a >> b;
            pii par1 = espiral[a];
            pii par2 = espiral[b];
            if(sideOfLine(par1.first, par1.second) == sideOfLine(par2.first, par2.second)) cout << "Mesmo lado da fronteira" << "\n";
            else cout << "Lados opostos da fronteira" << "\n";
    }

        
    }
    return 0;
}
