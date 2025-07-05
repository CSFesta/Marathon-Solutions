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

// Função que calcula a distância de Levenshtein
int distanciaLevenshtein(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int custo = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            dp[i][j] = min({
                dp[i - 1][j] + 1,      // remoção
                dp[i][j - 1] + 1,      // inserção
                dp[i - 1][j - 1] + custo // substituição
            });
        }
    }

    return dp[m][n]; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    vector<double> pontuacao(5, 0);
    while(a--){
        string target;
        cin >> target;
        int n = sz(target);
        int menor = INT_MAX;
        vector<int> trocas_cur(5, INT_MAX);
        for(int i = 0; i < 5; i++){
            string cur;
            cin >> cur;
            int trocas = distanciaLevenshtein(target, cur);
            menor = min(menor, trocas);
            trocas_cur[i] = trocas;
        }
        double val;
        if(menor == 0) val = 1;
        else val = 0.5;
        for(int i = 0; i < 5; i++){
            if(menor == trocas_cur[i]){
                pontuacao[i] += val;
            }
        }
    }    
    double maior = 0;
    for(const auto & i : pontuacao){
        maior = max(maior, i);
    }
    string str = to_string(maior);

    cout << fixed << setprecision(1) << maior << "\n";
    vector<int> ans;
    for(int i = 0; i < 5; i++){
        if(maior == pontuacao[i]){
            ans.push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << (int)ans[i] + 1;
        if(i != ans.size() - 1){
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
