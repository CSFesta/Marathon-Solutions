#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())

#define f first
#define s second

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const ll INF = 1e18;
using namespace std;


int n;
int m;

vector<vector<vector<pair<int, int>>>> v;
vector<int> di = {0, 1, 0, -1};
vector<int> dj = {1, 0, -1, 0};

void normalize(vector<pair<int, int>> &at){ // metodo responsavel por diminuir drasticamente a quantidade de poligonos e por transforma-los em poligonos unicos
    // ex: 0 0 == 1 1 == 2 2 == 3 3 , logo vou armazenar apenas o poligono 0 0 (considerando tamanho 1 nesse exemplo)
    int mini = INT_MAX; // menor i
    int minj = INT_MAX; // menor j

    for(auto & i : at){
        mini = min(mini, i.f);
        minj = min(minj, i.s);
    }

    for(auto & i : at){ //normaliza tudo
        i.f -= mini; 
        i.s -= minj;
    }
    sort(all(at));
}



void solve(){
    v[1] = {{{0, 0}}};

    for(int i = 2; i <= m; i++){ 

        set<vector<pair<int, int>>> exist;

        for(vector<pair<int, int>> j : v[i - 1]){ // pega todos poligonos de tamanho i - 1

            for(pair<int, int> & k : j){ // para cada poligono de tamanho i - 1
                
                for(int d = 0; d < 4; d++){ 

                    int xi = di[d] + k.f; 
                    int yj = dj[d] + k.s; 
                           
                    pair<int, int> par_atual = {xi, yj}; 
                    
                    if(!binary_search(all(j), par_atual)){ // j sempre está ordenado, (metodo normalize garante isso), verifico se o ponto atual ja existe no poligono atual
                        vector<pair<int, int>> at = j;
                        at.pb(par_atual); //adiciona um ponto novo, tamanho(i - 1) -> (i)
                        normalize(at);
                        exist.insert(at); 
                    }
                }
            }
        }
       
        v[i].assign(all(exist));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    cin >> n >> m;
    v.resize(m + 1);
    solve();
    
    vector<vector<int>> nums(n, vector<int>(n));
    for(auto & i : nums){
        for(auto & j : i){
            cin >> j;
        }
    }
    int maximo = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            // para cada posicao: tentar aplicar cada polinomo de tamanho M (se possivel)
            for(vector<pair<int, int>> & poly : v[m]){
                int soma_atual = 0;

                for(pair<int, int> & point : poly){
                    int x = i + point.f;
                    int y = j + point.s;
                    
                    if(x < 0 || y < 0 || x >= n || y >= n){
                        break; //poligono invalido
                    }

                    //somar todas posicoes, pois elas sao validas
                    soma_atual += nums[x][y];
                    maximo = max(maximo, soma_atual);
                }
            }
        }
    }
    cout << maximo << "\n";
    return 0;
}