🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/1148)
-


- 🧩 **Dificuldade:** 5 / 8 
    -
- 🗂 **Tópicos:** [**Grafo**, **Caminho mínimo**]  
    -
- 🧮 **Complexidade:** `O(V³)`  500³ = 1,25 * 10^8 (passa)
    -
- 🎯 **Desafios principais:** 
    - Esse é um problema extremamente clássico, que usa Floyd Warshall, algoritmo que nos traz todos os caminhos mínimos. Logo saber da teoria de grafos seria um desafio pra resolver esse problema
    - Noção de complexidade de tempo (muito importante)
- 🔎 **Ideia:**
    - Para toda conexão bidirecional, ou seja: se existe um caminho direto entre: 
        - (u -> v) e (v -> u)
        - o tempo de viagem entre as cidades u -> v ou v -> u é 0.
        - caso contrario, o tempo é ``H``
    - Com isso, construimos um Grafo, e aplicamos um Floyd Warshall clássico nele. 
