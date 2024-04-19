
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;
// сколько компонент
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


// есть ли путь
bool dfs(vector<int> graph[], vector<bool>& visited, int& start, int& end) {
    if (start == end)
        return true;
    visited[start] = true;
    for (auto x : graph[start]) {
        if (!visited[x]) {
            if (dfs(graph, visited, x, end)) {
                return true;
            }
        }
    }
    return false;
}


bool isPath(int st, int des, vector<int> graph[], int n) {
    vector<bool> visited(n + 1, false);
    return dfs(graph, visited, st, des);
}


struct Road {
    int from;
    int to;
};


struct RoadCompare {
    bool operator()(const Road & a, const Road& b) const {
        if (a.from != b.from) {
            return a.from < b.from;
        }
        return a.to < b.to;
    }
};


int main() {
    int n, m, st, en;

    cin >> n >> m;

    vector<int> graphG[n + 1];
    vector<int> graphH[n + 1];
    vector<bool> visited(n + 1, false);
    vector<int> component(n + 1, 0);
    stack<int> Stack;
    vector<int> families(n+1, INT_MAX);
    vector<Road> roads;

    for (int i = 0; i < m; i++) {
        cin >> st >> en;
        addEdge(st, en, graphG, graphH);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i, visited, graphG, Stack);
        }
    }


    int num_scc = 1;
    while (!Stack.empty()) {
        int i = Stack.top();
        Stack.pop();
        if (component[i] == 0) {
            dfs2(i, component, graphH, num_scc);
            num_scc++;
        }
    }

    for( int i = 1; i < component.size(); ++i) {
        int c = component[i];
        if (families[c] > i) {
            families[c] = i;
        }
    }

    set<long> uniqRoads;

    for(int g = 1; g <= n; g++){
        for(auto p : graphG[g]){
            long p0 = component[g];
            long p1 = component[p];
            if (p0 != p1){
                uniqRoads.insert(p0 + INT_MAX * p1);
            }
        }
    }

    cout << num_scc - 1 << " " << uniqRoads.size() << "\n";;

    for(int g = 1; g <= n; g++){
        for(auto p : graphG[g]) {
            long p0 = component[g];
            long p1 = component[p];
            long key = p0 + INT_MAX * p1;
            if (uniqRoads.count(key) == 1){
                Road r;
                r.from = families[component[g]];
                r.to = families[component[p]];
                roads.push_back(r);
                uniqRoads.erase(key);
            }
        }
    }

    RoadCompare roadCompare;
    sort(roads.begin(), roads.end(), roadCompare);

    for(auto r : roads) {
        cout << r.from << " " << r.to << "\n";
    }

    return 0;

}