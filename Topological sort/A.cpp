
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void DFS(vector<int> graph[], vector<bool>& visited, int vertex, int n, stack<int>& Stack){
    visited[vertex] = true;
    vector<int>::iterator it;
    for (it = graph[vertex].begin(); it != graph[vertex].end(); it++ ) {
        if (!visited[*it]) {
            DFS(graph, visited, *it, n, Stack);
        }
    }
    if (vertex != 0) {
        Stack.push(vertex);
    }
}

void topologicalSort(vector<int> graph[], int n) {
    vector<bool> visited(n, false);
    stack<int> Stack;
    int res[n];

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(graph, visited, i, n, Stack);
        }
    }
    int count = 1;
    while (!Stack.empty()) {
        res[Stack.top()] = count ;
        count++;
        Stack.pop();
    }

    for(int k = 1; k < n; k++){
        cout << res[k] << " ";
    }

}


void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

int main(){
    int n, m, a, b;
    cin >> n >> m;

    vector<int> graph[n+1];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        addEdge(graph, a,b);
    }

    topologicalSort(graph, n+1);

    return 0;
}