#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define mk make_pair

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const ll INF = 1e18;
using namespace std;

int calc(std::string &str) {
    int min = 0, sec = 0, milli = 0;
    char colon;

    std::stringstream ss(str);
    ss >> min >> colon >> sec >> colon >> milli;

    return ((min * 60 + sec) * 1000 + milli);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, v;
    cin >> n >> v;
    
    unordered_map<int, int> num_piloto;
    vector<vector<ll>> prefix(n, vector<ll>(v));
    vector<vector<ll>> tempo(n, vector<ll>(v));
    
    for(int i = 0; i < n; i++){
        int piloto;
        cin >> piloto;
        num_piloto[i] = piloto;
        for(int j = 0; j < v; j++){
            string str;
            cin >> str;
            ll val = (ll)calc(str);
            tempo[i][j] = val;
            prefix[i][j] = (j == 0 ? val : prefix[i][j - 1] + val);
        }
    }

    // Melhor volta + desempate por tempo total
    int melhor_volta = INT_MAX;
    pair<int,int> pos;
    ll best_total = LLONG_MAX;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < v; j++){
            if(tempo[i][j] < melhor_volta){
                melhor_volta = tempo[i][j];
                pos = mk(i, j);
                best_total = prefix[i][v - 1];
            }
            else if(tempo[i][j] == melhor_volta){
                if(prefix[i][v - 1] < best_total){
                    pos = mk(i, j);
                    best_total = prefix[i][v - 1];
                }
            }
        }
    }

    // Cria ranking pelo tempo de conclusao
    vector<pair<ll, int>> ranking; // (tempo_total, indice do piloto)
    for(int i = 0; i < n; i++) {
        ranking.eb(prefix[i][v - 1], i); 
    }

    sort(all(ranking)); // Menor tempo total (tempo de conclusao)

    // Verifica se o piloto da melhor volta está no top 10
    bool classificado = false;
    for(int i = 0; i < min(10, n); i++) {
        if(ranking[i].second == pos.first) {
            classificado = true;
            break;
        }
    }

    if(classificado) {
        cout << num_piloto[pos.first] << "\n";
    } else {
        cout << "NENHUM\n";
    }

    return 0;
}
