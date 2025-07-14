🔗 [Link do Problema](https://codeforces.com/gym/105925/problem/F)
-

- 🧩 **Dificuldade:** 6 / 13  
    -
- 🗂 **Tópicos:** [**DP**, **Combinações**, **Subsets**]  
    -
- 🧮 **Complexidade:** `O(N²)`
    -
    - A complexidade TENDE a quadrático, porém pode se distanciar para ambos lados dependendo do caso de teste.

- 🎯 **Desafios principais:** 
    - 
    - Noção de limites, utilizar LL
    - Construir a lógica da DP, que não é tão intuítiva
    
- 🔎 **Explicação:**
    -
    - Para cada elemento v[i]:

    - Atualiza a DP de trás para frente (j = 3 até 0) para evitar sobrescrever valores durante o processo.

    - Para cada grupo atual de j elementos com soma sum, se adicionarmos v[i], passamos a ter um grupo de j+1 elementos com soma **sum + v[i]**.

    - Assim, incrementamos **dp[j+1][sum + v[i]] com qnt**, que é a quantidade de formas de obter sum com j elementos.
   