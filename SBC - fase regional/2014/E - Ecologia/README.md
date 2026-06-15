🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/1712)
-


- 🧩 **Dificuldade:** 9 / 10 
    -
- 🗂 **Tópicos:** [**DP, Grafos, Sort, Força Bruta**]  
    -
- 🧮 **Complexidade:** `O(M * K * L * 4 * Log(L) * Nlog(L))`
    -
    - M = 10
    - K ~= 20.000 
    - L (1-10)
    - Log(l) - pesquisa binaria
    - Nlog(L) - Sort
    - é um valor aproximado, mas pode variar relativamente bastante

- 🎯 **Desafios principais:** 
    -
    - Encontrar uma maneira ótima de testar todos poligonos em um tempo viavel
    - Perceber que um backtracking convencional alem de não passar em tempo, tomaria WO, para um caso como:
    - 3 5
    - 0 1 0
    - 1 1 1
    - 0 1 0
    - Um backtracking padrão não conseguiria fazer um desvio, pois sempre segue a partir do vértice atual.
    - A noção de complexidade de tempo é muito perdida nessa questão, dificil saber se a sua estratégia está de fato correta ou por um pequeno detalhe você leva TLE
    - Por ser um Ad-hoc extremamente avançado, exige pré conhecimento de diversos tópicos distintos em conjunto
- 🔎 **Ideia:**
    - 
    - "Descobrir quais são todos os poligonos normalizados, comecando no tamanho 1 até M, e depois fazer força bruta para a contagem em todas posicoes i j da matriz"
    - Poligono normalizado: considere o poligono de tamanho 1: 0 0, percebemos que ele é igual à: 0 0, 1 1, 2 2, 3 3, 4 4, 5 5...
    Com isso conseguimos armazenar apenas 1 poligono o 0 0, assim economizando muita memória e consequentemente tempo de execução.
    - Para construirmos os poligonos de tamanho 3 por exemplo, precisamos saber com um vetor de DP, todos os poligonos de tamanho 2, e para isso precisamos de todos os poligonos de tamanho 1. (Down-top DP)
    - O vetor de DP é definido: vector<vector<vector<pair<int, int>>>> dp
        - pair<int, int> - Um ponto do poligono
        - vector<pair<int, int>> Poligono
        - vector<vector<pair<int, int>>> Todos poligonos do tamanho atual
        - vector<vector<vector<pair<int, int>>>> Tamanho do poligono (1 indexed)
        - ex: dp[2][0][1].first = Poligono de tamanho 2 - Primeiro poligono - segundo ponto - X
 
    
 
