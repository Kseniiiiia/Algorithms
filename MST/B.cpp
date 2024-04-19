#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[100001];
int s[100001];

int dsu_find (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_find (p[v]));
}

void dsu_union(int a, int b) {
    a = dsu_find(a);
    b = dsu_find(b);
    if (s[a] > s[b])
        swap(a, b);
    s[b] += s[a];
    p[a] = b;
}

void init(int n) {
    for (int i = 0; i < n; i++)
        p[i] = i, s[i] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n, m, x, y, weight;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> graph(m);

    for (int i = 0; i < m; i++){
        cin >> x >> y >> weight;
        x--;
        y--;
        graph[i].first = weight;
        graph[i].second.first = x;
        graph[i].second.second = y;
    }

    int count = 0;

    sort(graph.begin(), graph.end());

    init(n);
    for (int i = 0; i < m; ++i) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int w = graph[i].first;

        //cout << a << " " << b << " " << w <<"\n";
        if (dsu_find(a) != dsu_find(b)) {
            count += w;
            dsu_union(a, b);
        }
    }
    cout << count;
}

