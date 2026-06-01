🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/2238)
-


- 🧩 **Dificuldade:** 3 / 12 
    -
- 🗂 **Tópicos:** [**divisores, matematica, sort**]  
    -
- 🧮 **Complexidade:** `O(K(log(K)))` K = sqrt(n) 
    -
- 🎯 **Desafios principais:** 
    - Organizar as ideias de forma clara, dessa forma o problema fica bem fácil
- 🔎 **Ideia:**
    -  A = divisor
    -  B = Nao divisor (edge case)
    -  C = Multiplo
    -  D = Nao multiplo (edge case) 

    *C é multiplo de n, ou seja dentre os divisores de C, está n*
    - Descobrimos os divisores de C
    - Ordenamos os divisores
    - Para cada divisor (i):
        - Verificamos se o i é divisivel por A
        - Verificamos se o i NÃO é divisivel por B
        - Verificamos se o i NÃO é multiplo por D

    
    
 
