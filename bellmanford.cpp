#include<iostream>
#include<vector>
#include<algorithm>

#define sz 10000
#define inf (1<<28)

using namespace std;

//Bellmanford - calcula o menor caminho entre dois vertices. Alunos: Micael Silva e Jose Janio

int bellman(int st, int en, int n, int par[], int cost[], vector<int> adj[], vector<int> W[]){

    cost[st] = 0;
    for(int k = 1; k<n; k++){
        for(int i=0;i<n;i++){
            for(int j=0;j< adj[i].size();j++){
                if(cost[i] + W[i][j] < cost[adj[i][j]]){
                    cost[adj[i][j]] = cost[i] + W[i][j];
                    par[adj[i][j]] = i;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            if(cost[i] + W[i][j] < cost[adj[i][j]]){
                cout << "Ciclo Negativo Detectado!";
                return -inf;
            }
        }
    }
    return cost[en];
}

void init(int n, int par[], int cost[]){
    for(int i=0;i<n;i++)
        par[i]=-1, cost[i] = inf;
}

int main(){
    int x, y, z, n, m, origem, destino;
    int par[sz], cost[sz];
    vector<int> adj[sz], W[sz];

    cin >> n >> m; //lendo os vertices e arestas
    init(n, par, cost);

    for(int i=0;i<m;i++){
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back(y);
        W[x].push_back(z);
    }

    cin >> origem >> destino; //vertice de origem e destino respectivamente

    x = bellman(origem-1,destino-1, n, par, cost, adj, W);

    cout << "o valor de x eh " << x << endl;
    
    if(x==-inf){
        cout << "Sem fim ;-;";
        return 0;
    }
    cout << "O menor caminho de " << origem << " para " << destino << " eh " << x << endl;

    x = destino-1;
    vector<int>res;

    while(~x){
        res.push_back(x+1);
        x = par[x];
    }
    
    reverse(res.begin(),res.end()); //apenas invertendo a ordem do vetor

    cout << "O caminho: ";
    for (int i=0; i<res.size(); i++){
        cout << res[i] << ",\n"[i==res.size()-1];
    }

    return 0;
}
