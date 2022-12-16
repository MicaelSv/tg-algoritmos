#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define sz 1000
#define inf (1<<28)

//algoritmo dikstra que calcula o custo minimo entre dois vertices; alunos: Micael Silva e Jose Janio.

using namespace std;

int dijkstra(int st, int en, int par[], int cost[], vector<int> adj[], vector<int> w[]){

    int i;
    priority_queue<pair <int,int>, 
    vector<pair<int, int> >, greater<pair <int, int> > > pq;
    
    pq.push({0, st});
    cost[st] = 0;

    int x, y;
    
    while(!pq.empty()){

        x = pq.top().first;
        y = pq.top().second;
        pq.pop();

        for(i = 0; i < adj[y].size(); i++){
            if(x + w[y][i] < cost[ adj[y][i] ]){
                cost[ adj[y][i] ] = x + w[y][i];
                pq.push({ cost[ adj[y][i] ], adj[y][i] });
                par[ adj[y][i] ] = y;
                
            }
        }
    }
    return cost[en];
}

void init(int n, int par[], int cost[]){

    for(int i = 0; i < n; i++){
        par[i] = -1, cost[i] = inf;
    }
}

int main(){

    int i, x, y, z, n, m, origem, destino;
    vector<int> adj[sz], w[sz];
    int par[sz], cost[sz];

    cin >> n >> m; //lendo a qntd de vertices e arestas
    init(n, par, cost);

    for(i = 0; i < m; i++){
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }

    cin >> origem >> destino;

    x = dijkstra(origem-1,destino-1, par, cost, adj, w);

    cout << "o custo minimo do vertice " << origem << " para o vertice " << destino << " eh " << x << endl;

    x = destino - 1;
    vector<int> res;

    while(~x){
        res.push_back(x+1);
        x = par[x];
    }

    reverse(res.begin(), res.end());

    cout << "O caminho: ";

    for(i = 0; i < res.size(); i++){
        cout << res[i] << ",\n"[i==res.size()-1];
    }

}
