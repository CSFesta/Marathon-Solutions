🔗 [Link do Problema](https://codeforces.com/gym/105925/problem/E)
-


- 🧩 **Dificuldade:** 4 / 12  
    -
- 🗂 **Tópicos:** [*Math*, *Number Theory*, *Sort*]  
    -
- 🧮 **Complexidade:** `O(sqrt(Y) * log(sqrt(Y)))`
    -
    - sqrt(Y), para pegar todos os divisores de Y. Multiplicamos por log(sqrt(Y)), pois ordenamos os divisores. sort() = N(log(N)), onde na questao N = sqrt(Y).
- 🎯 **Desafios principais:** 
    - 
    - Encontrar uma estratégia eficiente
    - Pegar os divisores em sqrt(N)

- 🔎 **Explicação:**
    -
    - OBS:

        - Y pode ser até 1e9
        - K pode ser até 1e9

    - Problema: 
        - Chamar gcd(x, y) em cada passo seria muito lento:
    Complexidade O(sqrt(Y) * K) → TLE

    - Solução:

        - Como Y é fixo, seus divisores também são fixos.

        - Por base X é um divisor de Y, o próximo valor possível para x que mantém gcd(x, Y) == x, é o próximo divisor de Y que seja múltiplo de x.

        - Para cada divisor d de Y, se d % x == 0, significa que x pode crescer até d sem mudar o resultado do gcd(x, Y), pois d é multiplo de x.

        - Calculamos quantos passos seriam necessários para chegar em d a partir de x, e avançamos o máximo possível, limitado pelo valor de k.

        - Quando não houver mais divisores compatíveis ou k terminar, finalizamos com x += x * k, o que simula os passos restantes.

        - Ex: Y = 12, K = 7

        - Divisores: [1, 2, 3, 4, 6, 12]

        - Valores de X: 1 → 2 → 4 → 12 → x += x * k

        - Sempre pulando de um divisor para outro maior que seja múltiplo do x atual.
