#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(int v, int w, vector<int> graph[]) {
    graph[v].push_back(w);
    graph[w].push_back(v);
}

int main() {
    int n, m, a, b, k, c = 0;
    cin >> n;
    cin >> m >> k;

    vector<int> graph[n+1];
    vector<bool> visited(n+1, false);
    int dst[n+1];

    for (int i = 0; i <= n; i++) {
        dst[i] = -1;
    }

    for(int y = 0; y < m; y++){
        cin >> a >> b;
        addEdge(a, b, graph);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    dst[1] = 0;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int neighbor: graph[vertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                dst[neighbor] = dst[vertex] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dst[i] == k) {
            cout << i << "\n";
        }
        else
            c++;
    }

    if (c == n){
        cout << "NO" << "\n";
    }
    return 0;
}