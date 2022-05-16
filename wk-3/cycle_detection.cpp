#include <iostream>
#include <vector>
#include <queue>
//#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

void make_adj(vvi &adj, int m){
    cout<<"Making Adjacency list\n";
    int u, v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool dfs(int x, vvi &adj, vi &visited, vi &parent){
    for (auto a : adj[x]){
        if (!visited[a]){
            visited[a]=1;
            parent[a]=x;
            dfs(a, adj, visited, parent);
        }
        else {
            if (a!=parent[x]){
                return true;
            }
        }
    }
    return false;
}

bool cycle_check_dfs(vvi &adj, vi &visited, vi &parent, int n) {
    for (int i=0; i<n; i+=1){
        if (!visited[i]){
            visited[i]=1;
            parent[i]=-1;
            bool cycle = dfs(i, adj, visited, parent);
            if (cycle){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m; cin>>n>>m; //n is the number of nodes, m is the number of edges
    /* First we make an adjacency list */
    vvi adj;
    adj.reserve(n);
    make_adj(adj, m);
    vi visited, parent;
    visited.resize(n, 0);
    parent.resize(n, -1);
    cout<<cycle_check_dfs(adj, visited, parent, n)<<endl;

}
