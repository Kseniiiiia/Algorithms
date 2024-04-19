#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int vertex, vector<bool>& used, vector<vector<pair<int, int>>> &graph) {
    used[vertex] = true;
    for (auto i : graph[vertex])
        if (!used[i.second])
            DFS(i.second, used, graph);
}

bool NumberCC(int n, vector<bool>& used,vector<vector<pair<int, int>>> &graph){
    for (int vertex = 0; vertex < n; vertex++) {
        if (!used[vertex]) {
            if(graph[vertex].size() > 0) {
                return false;
            }
        }
    }
    return true;
}

void euler(int start, vector<vector<pair<int, int>>> &graph, vector<bool> &visited, vector<int> &first, vector<int> &res){
    while (first[start] < graph[start].size()){
        int i = graph[start][first[start]].first;
        int end = graph[start][first[start]].second;
        first[start]++;

        if(!visited[i]){
            visited[i] = true;
            euler(end, graph, visited, first, res);
            res.push_back((end+1));
        }
    }
}


bool isEulerian(int n, vector<vector<pair<int, int>>> &graph) {
    for (int i = 0; i < n; i++) {
        if (graph[i].size()%2 != 0)
            return false;
    }
    return true;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    vector<bool> visited(m, false);
    vector<bool> used(n, false);
    vector<int> first(n, 0);
    vector<int> res;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back({i,b});
        graph[b].push_back({i,a});
    }

    DFS(0, used,graph);

    if (isEulerian(n, graph) && NumberCC(n,used, graph)) {

        euler(0, graph, visited, first, res);
        res.push_back(1);
        reverse(res.begin(), res.end());
        for (int re: res) {
            cout << re << " ";
        }
    }
    else
        cout << ":( ";
}
