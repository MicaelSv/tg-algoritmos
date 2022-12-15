#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

//Algoritmo prim - calcula o custo da AGM. Alunos: Micael Silva e Jose Janio

int main(){
    
    int n, m, i, u, v, custo, soma = 0;

    while(cin >> n >> m and n){

    vector< vector<pair <int,int> > > G(n); //criando n listas, em que cada lista eu adiciono o vertice de ligação e o custo até esse vértice

    for(i = 0; i < m; i++){ //lendo m arestas, cada aresta tem um vert inicial/final e um custo
        cin >> u >> v >> custo;
        G[u - 1].push_back({v - 1, custo}); //u indo para v com um certo custo
        G[v - 1].push_back({u - 1, custo}); //v indo para u com um certo custo
    }

    priority_queue< pair <int,int> > prim; //aqui guarda o custo e o nó que está associado a este custo
    //visitar um vértice e colocar todas as arestas desse vértice na fila de prioridade

    vector<bool> sinal(n, false); //vetor para verificar se eu já visitei o vértice
    
    sinal[0] = true; //iniciando pelo vertice 1;

    for(pair<int,int> arest: G[0]){ //arestas que saem do meu vértice 0
        prim.push({-arest.second, arest.first}); //adicionando as arestas que estão ligadas com o vértice 0 na fila de prioridade
    }
    
    while(prim.size()){ //enqt a fila de prioridade tiver algum tamanho, eu pego a aresta de menor tamanho
        pair<int, int> menor_aresta = prim.top();
        prim.pop();

        if(sinal[menor_aresta.second] == true) continue; //se a aresta me leva para um vértice que eu já visitei, eu ignoro e pego outra aresta
        soma += -menor_aresta.first;
        sinal[menor_aresta.second] = true; //marco o vértice como já visistado
            
        for(pair<int,int> arest: G[menor_aresta.second]){ //adicionando todas as arestas que saem desse vértice visitado atualmente
            prim.push({-arest.second, arest.first}); 
        }    
    }

    cout << "custo da AGM: " << soma << endl;
    exit(0);
    }
    
}


