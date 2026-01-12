🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/3439)
-


- 🧩 **Dificuldade:** 7 / 8  
    -
- 🗂 **Tópicos:** [**Grafos**, **DFS**, **Alteração de Estados**]  
    -
- 🧮 **Complexidade:** `O(E*(V + E))` = 1 * 10^8  
    -
- 🎯 **Desafios principais:** 
    - O entendimneto do problema é tranquilo, só é mais chato de testar os casos de entrada na mão, pois eles vem em string
    - Ter conhecimento de DFS já é o suficiente pra resolver

- 🔎 **Ideia:**
    - Basicamente para cada aresta u -> v, vamos rodar um DFS, "excluindo" a aresta atual (u -> v) e verificar se conseguimos chegar no vértice 0.
    - A aresta é crítica se: excluirmos essa aresta, e o vértice U não conseguir chegar no vértice 0 ao aplicar um DFS.
