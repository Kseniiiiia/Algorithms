#include <iostream>
#include <set>
using namespace std;

const int ARR_SIZE = 200010;

set<long long> a [ARR_SIZE];
set<long long>:: iterator b [ARR_SIZE];
long long parent[ARR_SIZE];

long long find(long long v) {
    return (parent[v] == v) ? v : parent[v] = find(parent[v]);
}


void unite(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }

    if (a[x].size() >= a[y].size()) {
        parent[y] = x;
        long long l = a[y].size();
        for (long long i = 0; i < l; i++) {
            set<long long>::iterator it = a[y].begin();
            a[x].insert(*it);
            if ((*it > *(b[x])) && (a[x].size() % 2 == 1)) {
                b[x]++;
            } else if ( (*it < *(b[x])) && (a[x].size() % 2 == 0)) {
                b[x]--;
            }
            a[y].erase(it);
        }
    } else if (a[x].size() < a[y].size()) {
        parent[x] = y;
        long long l = a[x].size();
        for (long long i = 0; i < l; i++) {
            set<long long>::iterator it = a[x].begin();
            a[y].insert(*it);
            if ((*it > *(b[y])) && (a[y].size() % 2 == 1)) {
                b[y]++;
            } else if ((*it < *(b[y])) && (a[y].size() % 2 == 0)) {
                b[y]--;
            }
            a[x].erase(*it);
        }
    }
}


void makeSet(int n) {
    for (long long i = 0; i < n+1; i++) {
        parent[i] = i;
        a[i].insert(i);
        b[i] = a[i].begin();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, q, t;
    cin >> n >> q;

    makeSet(n);

    for(long long i=0; i<q; i++){
        cin >> t;
        if(t == 1){
            long long x, y;
            cin >> x >> y;
            unite(x,y);
        }
        else{
            long long x;
            cin >> x;
            cout<<*(b[find(x)])<<endl;
        }
    }
}