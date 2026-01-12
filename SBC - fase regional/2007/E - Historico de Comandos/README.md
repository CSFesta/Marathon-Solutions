🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/2897)
-


- 🧩 **Dificuldade:** 2 / 10  
    -
- 🗂 **Tópicos:** [**ADHOC**, **Vetor**]  
    -
- 🧮 **Complexidade:** `O(N)`
    -
- 🎯 **Desafios principais:** 
    - Identificar como atualizar a quantidade de "subidas" quando o numero se repete

- 🔎 **Ideia:**
    - Usamos um vetor `pos` onde `pos[x]` guarda **a última vez (ordem)** em que o comando da posição `x` foi executado.
    - Inicialmente, todos os valores de `pos` são `INT_MAX`, indicando que o comando **nunca foi usado**.
    - Para cada comando lido na ordem `i`:
    
    - **Se for a primeira vez** que o comando aparece (`pos[x] == INT_MAX`):  
        - Precisamos subir `x` vezes no histórico inicial  
        - Além disso, o histórico já cresceu `i - 1` posições  
        - Total: `x + i - 1`
  - **Se o comando já foi usado antes**:  
    - Ele foi executado na posição `pos[x]`  
    - Agora está a `i - pos[x]` posições de distância  
    - Total: `i - pos[x]`
- Após processar o comando, atualizamos `pos[x] = i`.