#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int vertex, vector<bool>& visited, vector<int> graphG[], stack<int>& Stack){
    visited[vertex] = true;
    for(auto x : graphG[vertex]){
        if (!visited[x]){
            dfs1(x, visited,graphG, Stack);
        }
    }
    if(vertex != 0) {
        Stack.push(vertex);
    }
}


void dfs2(int vertex, vector<int>& component, vector<int> graphH[], int& num_scc){
    component[vertex] = num_scc;
    for(auto x : graphH[vertex]){
        if (component[x] == 0){
            dfs2(x, component, graphH, num_scc);
        }
    }
}

void addEdge(int v, int w, vector<int> graphG[], vector<int> graphH[]) {
    graphG[v].push_back(w);
    graphH[w].push_back(v);
}

int main(){
    int n, m, q, st, en;

    cin >> n >> m >> q;

    vector<int> graphG[n+1];
    vector<int> graphH[n+1];
    vector<bool> visited(n+1, false);
    vector<int>component(n+1, 0);
    stack<int> Stack;

    for (int i = 0; i < m; i++) {
        cin >> st >> en;
        addEdge( st, en, graphG, graphH);
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dfs1(i, visited, graphG, Stack);
        }
    }


    int num_scc = 1;
    while (!Stack.empty()){
        int i = Stack.top();
        Stack.pop();
        if (component[i] == 0){
            dfs2(i, component, graphH, num_scc);
            num_scc++;
        }
    }

    for(int k = 0; k < q; k++){
        cin >> st >> en;
        if(component[st] == component[en]){
            cout << "YES" << "\n";
        }
        else
            cout << "NO" << "\n";
    }
    return 0;
}