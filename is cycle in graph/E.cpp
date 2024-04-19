#include <iostream>
#include <vector>
using namespace std;

void addEdge(int v, int w, vector<int> graph[]) {
    graph[v].push_back(w);
    graph[w].push_back(v);
}

bool is_Cyclic(int v, vector<bool>& visited,vector<int> graph[], int parent)
{
    visited[v] = true;
    for (auto i : graph[v]) {
        if (!visited[i]) {
            if (is_Cyclic(i, visited,graph, v))
                return true;
        }

        else if (i != parent)
            return true;
    }
    return false;
}


bool isCyclic(vector<int> graph[], int n)
{
    vector<bool> visited(n+1, false);

    for (int u = 1; u <= n; u++) {
        if (!visited[u])
            if (is_Cyclic(u, visited, graph, 0))
                return true;
    }
    return false;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<int> graph[n+1];

    for(int y = 0; y < m; y++){
        cin >> a >> b;
        addEdge(a, b, graph);
    }

    if (isCyclic(graph, n)){
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    return 0;
}
