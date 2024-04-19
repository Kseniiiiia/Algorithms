/*

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;
vector<long> dijkstra(vector<vector<pair<int, int>>> &graph, int &n, int st){
    vector<bool> visited(n, false);
    vector<long> dist(n , INF);
    dist[st] = 0;

    for(int i = 0; i < n; i++){
        int near = -1;
        for(int j = 0; j < n; j++){
            if(!visited[j] && (near == -1 || dist[near] > dist[j])){
                near = j;
            }
        }
        visited[near] = true;

        for(auto &[to, weight] : graph[near]){
            if(dist[to] > dist[near] + weight){
                dist[to] =  dist[near] + weight;
            }
        }
    }
    return dist;
}

void addEdge(vector<vector<pair<int, int>>> &graph, int a, int b, int t){
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
}
int main() {
    int m, n, a, b, t;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);


    for (int k = 0; k < m; k++) {
        cin >> a >> b >> t;
        a--;
        b--;
        addEdge(graph, a, b, t);
    }

    vector<long> dist_ = dijkstra(graph, n, 0);


    for (int g = 0; g < n; g++) {
        if (dist_[n] != INF) {
            cout << dist_[g] << "\n";
        }
        else {
            cout << "-1\n";
        }
    }


    if ((n == 1) or (dist_[n-1] == INF )){
        cout << "-1\n";
    }
    else if (dist_[n-1] != INF){
        cout << dist_[n-1] << "\n";
    }
}

*/

/*

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, set<pair<int, int>> &q, int &n, int st) {
    vector<int> dist(n+1, INF);
    dist[st] = 0;

    q.insert({dist[st], st});
    while (!q.empty()){
        int near = q.begin() -> second;
        q.erase(q.begin());

        for (auto &[to, weight] : graph[near]){
            if(dist[to] > dist[near] + weight){
                q.erase({dist[to], to});
                dist[to] = dist[near] + weight;
                q.insert({dist[to], to});
            }
        }
    }
    return dist;
}

void addEdge(vector<vector<pair<int, int>>> &graph, int a, int b, int t){
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
}

int main(){
    int m, n, a, b, t;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    set<pair<int, int>> q;

    for (int k = 0; k < m; k++) {
        cin >> a >> b >> t;
        addEdge(graph, a, b, t);
    }

    vector<int> dist_ = dijkstra(graph, q, n, 1);

    if ((n == 1) or (dist_[n] == INF )){
        cout << "-1\n";
    }
    else if (dist_[n] != INF){
        cout << dist_[n] << "\n";
    }
}
 */


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> &dist,vector<bool> &visited, int &n, int st){
    dist[st] = 0;

    for(int i = 0; i <= n; i++){
        int near = -1;
        for(int j = 0; j <= n; j++){
            if(!visited[j] && (near == -1 || dist[near] > dist[j])){
                near = j;
            }
        }
        visited[near] = true;

        for(auto &[to, weight] : graph[near]){
            if(dist[to] > dist[near] + weight){
                dist[to] =  dist[near] + weight;
            }
        }
    }
    return dist;
}

void addEdge(vector<vector<pair<int, int>>> &graph, int a, int b, int t){
    graph[a].push_back({b, t});
}
int main(){
    int m, n, a, b, t;
    cin >> n >> m;

    vector<int> dist(n+1, INF);
    vector<vector<pair<int, int>>> graph(n+1);
    vector<bool> visited(n+1, false);

    for (int k = 1; k <= m; k++){
        cin >> a >> b >> t;
        addEdge(graph, a, b, t);
    }

    vector<int> dist_ = dijkstra(graph, dist, visited, n, 1);

    if (dist_[n] != INF){
        cout << dist_[n] << "\n";
    }
    else {
        cout << "-1\n";
    }
}



