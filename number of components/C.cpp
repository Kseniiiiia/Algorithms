
#include <iostream>
#include <vector>
using namespace std;

void DFS(int vertex, vector<bool>& visited, vector<int> graph[]) {
    visited[vertex] = true;
    for (auto i : graph[vertex])
        if (!visited[i])
            DFS(i, visited, graph);
}

int NumberCC(int n, vector<int> graph[]){

    vector<bool> visited(n+1, false);
    int count = 0;

    for (int vertex = 1; vertex <= n; vertex++) {
        if (!visited[vertex]) {
            DFS(vertex, visited, graph);
            count += 1;
        }
    }
    return count;
}

void addEdge(int v, int w, vector<int> graph[])
{
    graph[v].push_back(w);
    graph[w].push_back(v);
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<int> graph[n+1];

    for(int y = 0; y < m; y++){
        cin >> a >> b;
        addEdge(a, b, graph);
    }

    cout << NumberCC(n, graph);
}
