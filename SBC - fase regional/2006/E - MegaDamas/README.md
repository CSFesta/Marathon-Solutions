🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/1404)
-


- 🧩 **Dificuldade:** 3 / 8  
    -
- 🗂 **Tópicos:** [**Backtrack**, **Grafo**, **Matriz**]  
    -
- 🧮 **Complexidade:** `O(?)` Extremamente difícil de determinar  
    -
- 🎯 **Desafios principais:** 
    - Ter conhecimento de backtrack
    - cuidar com out of bounds
    - redefinir todos os estados de forma correta. ex: se voce derrotar uma peca inimiga, transforme ela em um espaco vazio para o caminho atual, e desfaça isso para manter o backtrack.

- 🔎 **Ideia:**
    - Para toda posição [i][j] == 1, vamos determinar a maior quantidade possivel de peças que a peça da posição [i][j] consegue eliminar.
    - Para isso aplicamos um backtrack nessas posições, e simule a eliminação e a troca de posições das peças, para evitar loops infinitos no backtrack.
    - Toda vez que entrar novamente no backtrack, tente maximizar o valor "ans" - a quantidade maxima de peças inimigas que podem ser eliminadas em uma jogada.

