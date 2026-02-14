🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/1086)
-

- 🧩 **Dificuldade:** 4 / 10  
  -
- 🗂 **Tópicos:** [**Adhoc**]  
  -
- 🧮 **Complexidade:** `O(N)`
  -

- 🎯 **Desafios principais**
 
 - Descobrir a menor quantidade de tábuas necessárias para cobrir um piso de dimensões n x m, sabendo que:

 - Cada tábua tem comprimento l

 - As dimensões estão em metros (precisa converter para centímetros → 100 * valor)

 - As tábuas podem ser combinadas para formar uma linha completa

- 🔎 **Ideia:**
 
 - ✅ Passo 1 — Verificar se é possível

Para cobrir:

Vertical → (100 * n) % l == 0

Horizontal → (100 * m) % l == 0

Se não for divisível, não dá pra montar as linhas certinho.

- ✅ Passo 2 — Quantas linhas precisam ser montadas?

Exemplo vertical:

total_linhas = (100 * n) / l


Agora você precisa montar essas linhas usando as tábuas disponíveis.

- ✅ Passo 3 — Como montar uma linha?

Uma linha pode ser formada por:

1 tábua de tamanho exato

2 tábuas que somadas dão o tamanho necessário

Para isso:

Use um map para contar quantas tábuas de cada tamanho existem

Combine:

Se x + y = tamanho necessário

Ou x == y (caso especial → usa 2 iguais)

Sempre use primeiro as maiores disponíveis.
    

