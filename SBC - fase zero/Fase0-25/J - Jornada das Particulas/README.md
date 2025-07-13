🔗 [Link do Problema](https://codeforces.com/gym/105925/problem/J)
-

- 🧩 **Dificuldade:** 7 / 13  
    -
- 🗂 **Tópicos:** [**Vetor Circular**, **Simulação**, **Pilha Monótona**, **Otimização Linear**]  
    -
- 🧮 **Complexidade:** `O(N)`
    -

- 🎯 **Desafios principais:** 
    - 
    - Compreender o enunciado da questão, acredito que ele poderia ter sido mais simplificado.
    - Simular e compreender um vetor circular
    - Fugir de uma estratégia quadrática
    - Estratégia não intuitiva, pois pensamos muito em questões de ordenação e no final usamos uma estrutura de dados que não garante ordenação por padrão, porém utilizamos ela, garantindo que ela tenha um padrão de ordenamento
    
- 🔎 **Explicação:**
    -
    - Um vetor circular é um vetor onde o último elemento se conecta ao primeiro. 

    - No problema temos que retornar a posição do filtro que seja inferior à particula simulando os passos * K, isso nos garante que a quantidade máxima do vetor ciruclar seja 2 * N, então podemos simplesmente "dobrar" o vetor

    - Vamos ter uma pilha que garante que o topo dela é o maior elemento dela, armazenaremos nela: (filtro[i], i), valor inicial da partícula e a posição em que foi ser armazenado na pilha

    - Garantir que o maior elemento seja o topo da pilha: filtro[i] + K * passos = valor atual da partícula, podemos chamar isso de val, enquanto filtro[i] < val, iremos remover as partículas e armazenamos as respostas. Após isso adicionamos o filtro[i] na pilha, isso se ainda não demos uma volta inteira no vetor circular (para não repetir calculos e não levar run time)

    