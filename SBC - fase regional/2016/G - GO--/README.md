🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/2241)
-


- 🧩 **Dificuldade:** 6 / 12 
    -
- 🗂 **Tópicos:** [**2Dprefix**]  
    -
- 🧮 **Complexidade:** `O(N³)`
    -
- 🎯 **Desafios principais:** 
    - Conhecimento de prefix2d
    - Ter a sacada de criar 2 prefix 2d sum (1 para cada cor)
    - Noção de complexidade de tempo, para saber que força bruta não funciona
    
- 🔎 **Ideia:**
    - Criar 2 prefix2D, 1 para as pretas e a outra para as brancas
    - para cada i -> n (1 indexed)
        - para cada j -> n (1 indexed)
            - para cada k -> n (tamanho do quadrado)
                - verifica se o tamanho do quadrado atual não está ultrapassando os limites
                - query de quantas peças pretas existem dentro do quadrado usando prefix2d
                - query de quantas peças brancas existem dentro do quadrado usando prefix2d
                - se a quantidade de ambos for > 0
                    - break
                - se a quantidade de pecas pretas > 0
                    - ans_b++;
                - se a quantidade de pecas brancas > 0
                    - ans_w++;
    
 
