🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/2902)
-

- 🧩 **Dificuldade:** 3 / 10  
  -
- 🗂 **Tópicos:** [**Simulação, Vetores**]  
  -
- 🧮 **Complexidade:** `O(N · M)`
  -

- 🎯 **Desafios principais**

  - Implementar corretamente as regras da simulação  
  - Controlar a vez dos jogadores e o estado das mãos  


- 🔎 **Ideia**

  - Usamos um vetor `mao`, onde cada posição guarda:
    - o valor da carta atual  
    - a quantidade de cartas acumuladas pelo jogador  

  - Usamos um vetor `morto` para contar quantas cartas de cada valor estão fora das mãos.

  - Para cada carta lida:
    - Se o jogador atual já possui essa carta, apenas incrementamos a quantidade.
    - Caso contrário, verificamos se:
      - existe essa carta em outra mão (**roubo**), ou  
      - existem cartas mortas desse tipo (**coleta**).
    - Se nenhuma das condições ocorre, a carta se torna **morta** e a vez passa.
