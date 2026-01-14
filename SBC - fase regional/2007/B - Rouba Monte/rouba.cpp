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
    
    while(cin >> n >> m && n > 0){
        int vez = 0;
        vector<int> morto(14, 0); //1 indexed
        vector<pair<int, int>> mao(m + 1, {0, 0});
        for(int i = 0; i < n; i++){ //0 indexed
            int carta;
            cin >> carta; // 1 indexed
            
            if(mao[vez + 1].first == carta) {
                mao[vez + 1].second++;
                continue;
            }
            
            if(morto[carta] > 0){
                mao[vez + 1].second += morto[carta] + 1;
                mao[vez + 1].first = carta;
                morto[carta] = 0;
                continue;
                
            }
            
            bool roubou = false;

            for(int j = 1; j <= m; j++){
                if(mao[j].first == carta){
                    mao[vez + 1].second += mao[j].second + 1;
                    mao[vez + 1].first = carta;
                    mao[j] = {0, 0};
                    roubou = true;
                    break;
                }
            }
            if(roubou) continue;

            if(!roubou){
                vez = (vez + 1) % m;
                morto[carta]++;
            }  
        }


        int maior = 0;
        for(int i = 1; i <= m; i++){
            maior = max(maior, mao[i].second);
        }
        cout << maior;
        for(int i = 1; i <= m; i++){
            if(mao[i].second == maior){
                cout << " " << i;
            }
        }
        cout << "\n";
    }
    return 0;
}
