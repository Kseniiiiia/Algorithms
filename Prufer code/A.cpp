#include <iostream>
#include <vector>

using namespace std;
int parent[200001];
int degree[200001];
vector<int> tree[200001];

void dfs (int v) {
    for (size_t i = 0; i < tree[v].size(); ++i) {
        int to = tree[v][i];
        if (to != parent[v]) {
            parent[to] = v;
            dfs (to);
        }
    }
}

vector<int> prufer(int n) {
    parent[n-1] = -1;
    dfs (n-1);

    int ptr = -1;
    for (int i = 0; i < n; ++i) {
        degree[i] = (int)tree[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }

    vector<int> result;
    int leaf = ptr;
    for (int iter = 0; iter < (n-2); ++iter) {
        int next = parent[leaf];
        result.push_back(next);
        --degree[next];
        if (degree[next] == 1 && next < ptr) {
            leaf = next;
        }
        else {
            ++ptr;
            while (ptr<n && degree[ptr] != 1) {
                ++ptr;
            }
            leaf = ptr;
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, u, v;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> res = prufer(n);
    for(int j = 0; j < res.size(); ++j){
        cout << res[j] + 1 << " ";
    }

    return 0;
}
