🔗 [Link do Problema](https://codeforces.com/gym/105925/problem/H)
-


- 🧩 **Dificuldade:** 5 / 13  
    -
- 🗂 **Tópicos:** [**Números Binarios**, **Palindromo**, **Strings**, **Greedy**, **Number Theory**]  
    -
- 🧮 **Complexidade:** `O(1)`
    -
    - Por incrível que parece a complexidade é O(1), pois todas funções e iterações que o código tem, utiliza um limite de 64, que é O(1).

- 🎯 **Desafios principais:** 
    - 
    - Encontrar uma estratégia que consiga lidar com os casos de teste que vão até 1e18
    - Fugir da ideia mais intuitiva de força bruta com todas as combinações de palindromos menores que N
    - Conversões de decimal(ll) para binario(string) e vice versa

- 🔎 **Explicação:**
    -
    - Se for N = potencia de 2, retorne N - 1, pois N - 1 resulta em apenas números 1s

    - Inicializaremos o menor palíndromo possível com o mesmo número de bits que N, que é uma string binária com ‘1’ nas extremidades e ‘0’ no meio (por exemplo: para tamanho 5, seria "10001")

    - Em seguida, tentaremos maximizar esse palíndromo bit a bit, alterando simetricamente pares de bits internos para ‘1’, começando das bordas para o centro, sempre verificando se o número formado ainda é menor ou igual a N

    - Se em algum momento a alteração faz o número ultrapassar N, desfazemos essa alteração (voltamos para '0' no indice) e continuamos

    - Dessa forma, construímos o maior palíndromo binário menor ou igual a N de forma eficiente