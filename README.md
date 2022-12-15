# Teoria dos Grafos - Algoritmos
##### Alunos: Micael Silva e José Janio.

#### Códigos implementados em C++:
  
  - Prim;
  - Dijkstra;
  - Bellmanford;
  - Kruskal.

`Há um makefile para os 4 algoritmos`

Para rodar o prim, dijkstra e o bellmanford, utilize o cmd/wsl/git bash para importar o txt e rodar o código, o kruskal já está importando o txt automaticamente, basta rodar.

Se quiser alterar os vértices de origem e destino nos algoritmos de prim, dijkstra e bellmanford, tem que alterar pelo txt, pois eles já estão definidos lá.

#### Como utilizar: 
  
  1. make nomedoalgoritmo
  2. ./nomedoalgoritmo < ex_algoritmo.txt

#### Exemplo:
  1. make prim
  2. ./prim < ex_prim.txt

Como o kruskal já está com o txt importado dentro do código, basta fazer o make como nos exemplos anteriores, e depois digitar ./kruskal que ele irá rodar

##### Esses comandos foram utilizados no wsl, que é o terminal do linux nativo pro windows.
