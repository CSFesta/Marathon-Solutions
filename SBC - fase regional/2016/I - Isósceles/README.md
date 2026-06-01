🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/2243)
-


- 🧩 **Dificuldade:** 5 / 12 
    -
- 🗂 **Tópicos:** [**DP**]  
    -
- 🧮 **Complexidade:** `O(N)`
    -
- 🎯 **Desafios principais:** 
    -
    - Estratégia não intuitiva
    - Parece muito ser uma questao de prefixo / sufixo, isso acaba atrasando bastante para descobrir a estratégia
- 🔎 **Ideia:**
    -
    - criar 2 vetores, sendo "esq", para definir o maior triangulo possível de se fazer considerando apenas o bloco central e os que estao à sua esquerda, sendo "dir", para definir o maior triangulo possivel de se fazer considerando o bloco central e os que estao à sua direita.
    - para todos valores de n: (esq)
        - MIN (i, v[i], esq[i - 1] + 1)
    - para todos valores de n: (dir) de trás pra frente
        - MIN (i, v[i], dir[i + 1] + 1)
    - para todos valores de n:
        - ans = MAX ( MIN ( esq[i], dir[i] ) , ans )
    
 
