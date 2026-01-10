🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/3438)
-


- 🧩 **Dificuldade:** 6 / 8  
    -
- 🗂 **Tópicos:** [**DP**, **Matriz**]  
    -
- 🧮 **Complexidade:** `O(F² * P)`  = 2 * 10^6
    -
- 🎯 **Desafios principais:** 
    - Achei confuso o enunciado e demorei um tempo pra entender bem o input, mas a ideia é:
        - Existem F niveis de frequência, de 1 - F. Para cada programa P existente, é passado quanto tempo demora pra ser executado no nível de frequencia f[i]. 
        - Ex: P = 2 e F = 3
            - **Programa1:**
            - F[1] = Tempo(ms)
            - F[2] = Tempo(ms)
            - F[3] = Tempo(ms)
            - **Programa2:**
            - F[1] = Tempo(ms)
            - F[2] = Tempo(ms)
            - F[3] = Tempo(ms)
        - A ideia é: executar sequencialmente todos os programas com o menor tempo possível, tendo que aplicar um atraso de tempo a cada vez que for necessário trocar de frequência de um programa para outro, pois se voce termina o programa 1 com frequencia 3, o programa 2 inicia com frequencia 3.
    - Além disso, ter uma noção de DP, para aplicar os conceitos de reutilização de calculos é extremamente importante para esse problema.

- 🔎 **Ideia:**
    - A ideia é aplicar uma DP, pegando como estado anterior a linha anterior [i], dessa maneira tende a ser mais facil, pois toda a estrutura da questão e do input já vem assim.
    - Iniciar a DP da primeira linha que representa o (Programa 1), O início da execução começa com Frequencia 1, logo todas posicoes de frequencia (1 - F), menos a primeira deve ser aplicada o atraso de troca de frequencia (e * a).
    - Após isso, aplicamos a DP buscando minimizar a quantidade EDP total de cada frequencia (1 - F) de cada programa.
    - No final de tudo, temos que pegar o menor valor de nossa matriz[Fi][P - 1], ou seja o menor EDP do último programa

- Possível otimização: trocar a Matriz de tamanho [P][F], por [2][F], pois precisamos apenas do estado anterior, logo acaba sendo um desperdicio de tempo e memória armazenar os P anteriores. Ou até separar em 2 vetores de tamanho F. 