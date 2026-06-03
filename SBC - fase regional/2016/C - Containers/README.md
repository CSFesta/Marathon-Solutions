🔗 [Link do Problema](https://judge.beecrowd.com/pt/problems/view/2241)
-


- 🧩 **Dificuldade:** 7 / 12 
    -
- 🗂 **Tópicos:** [**Grafos, Dijkstra**]  
    -
- 🧮 **Complexidade:** `O( N(log(8! * 8)) )`  
    -
Posso estar um pouco equivocado na complexidade, mas estimo que contenham 8! containers diferentes, 
cada container possui 8 elementos (por isso * 8)
e Nlog(), pois estou utilizando tanto um "pq", quanto um set< container > como  validador de containers visitados.
    
- 🎯 **Desafios principais:** 
    -    
    - Perceber que Backtracking não é viavel para esta questão
    - Pode não ser tão intuitivo que um Dijkstra resolva o problema, por conta da estrutura dos dados (vector<vector< int >> = container)
- 🔎 **Ideia:**
    - Utilizar um dijkstra modificado para descobrir o menor caminho do container inicial para todos os outros.
    - Estrutura do dijkstra:
        - Vértice = cada container
        - Aresta = swap necessario para um container u -> v
        - visitados = set< container >
        - priority queue (min) = pq < peso, container >
    - Inicializar a pq com o container inicial
    - enquanto 'pq' não estiver vazio:
        -  se o container atual já tiver sido visitado da um 'continue'
        - se o container atual for igual ao container final / target, retorna o peso, pois o dijkstra garante que assim que chegamos no vertice objetivo aquele será o caminho minimo
        
        - caso contrario, vamos apenas por o container atual como visitado
        - para todas as trocas possiveis (sem repeticao):
            - swap da troca atual
            - verifica se o container atual NAO existe:
                - adiciona na 'pq' com o peso atualizado
            - swap da troca atual (para voltar ao normal)
