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

bool bfs(int source, vvi &adj, vi &visited, queue<int> &Queue, vi &color){
    Queue.push(source);
    color[source]=0;
    while(!Queue.empty()){
        int x = Queue.front();
        Queue.pop();
        for (auto a : adj[x]){
            if (color[a]==color[x]){
                cout<<a+1<<" and "<<x+1<<" match\n";
                return false;
            }
            if (!visited[a]){
                visited[a]=1;
                Queue.push(a);
                color[a]=(color[x]+1)%2;
            }
        }
    }
    return true;
}

bool bipartite_bfs(vvi &adj, vi visited, queue<int> Queue, vi color, int n){
    for (int i=0; i<n; i++) {
        if (!visited[i]){
            visited[i]=1;
            bool check = bfs(i, adj, visited, Queue, color);
            if (!check){

                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m; cin>>n>>m; //n is the number of nodes, m is the number of edges
    /* First we make an adjacency list */
    vvi adj;
    adj.reserve(n);
    make_adj(adj, m);
    vi visited, parent, color;
    queue<int> Queue;
    visited.resize(n, 0);
    parent.resize(n, -1);
    color.resize(n, -1);
    bipartite_bfs(adj, visited, Queue, color, n) ? (cout<<"" ) : (cout<<"Not "); cout<<"Bipartite\n";


}
