#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<long> s1;
set<long> s2;
long count1 = 0, count2 = 0;

int invert(int c){
    return c==1 ? 2 : 1;
}

void dfs(int v, int c, vector<vector<long>> &graph, vector<int> &color){
    color[v] = c;
    if (c == 1){
        s1.insert(v);
        count1++;
    }
    else {
        s2.insert(v);
        count2++;
    }
    for(long u : graph[v]){
        if(color[u] == 0){
            dfs(u, invert(c), graph, color);
        }
        else if (color[u] == c){
            cout << "NO\n";
            exit(0);
        }
    }
}

int main(){
    long n, m, a, b;
    cin >> n >> m;

    vector<vector<long>> graph(n+1);
    vector<int> color(n+1, 0);

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < n+1; i++) {
        if (color[i] == 0) {
            dfs(i, 1, graph, color);
        }
    }

    cout << "YES\n";
    if (count1 > count2){
        for (auto i: s1) {
            cout << i << " ";
        }
        cout << "\n";
        for (auto j: s2) {
            cout << j << " ";
        }
    }

    else{
        for (auto i: s2) {
            cout << i << " ";
        }
        cout << "\n";
        for (auto j: s1) {
            cout << j << " ";
        }
    }

    return 0;
}
