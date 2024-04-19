#include <iostream>
#include <vector>
#include <set>
using namespace std;
int timer;

set<pair<int, int>> s;

void dfs(int v, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &low, vector<int> &tin, int parent = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;

    for(int to : graph[v]){
        if (to == parent) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else{
            dfs(to, graph,visited, low, tin,v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                if (to < v) {
                    s.insert({to, v});
                }
                else{
                    s.insert({v, to});
                }

            }
        }
    }
}


void findBridge(int n,vector<vector<int>> &graph, vector<bool> &visited, vector<int> &low, vector<int> &tin){
    timer = 0;
    for(int j = 0; j < n; j++){
        visited[j] = false;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, graph, visited, low, tin, -1);
        }
    }
}

void addEdge(vector<vector<int>> &graph, int v, int w){
    graph[v].push_back(w);
    graph[w].push_back(v);
}

int main(){
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> low(n, -1);
    vector<int> tin(n, -1); // время входа в вершину

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        addEdge(graph, a, b);
    }

    findBridge(n, graph, visited, low, tin);
    for (auto &[to, from] : s){
        cout << to+1 << " " << from+1 << "\n";
    }
}