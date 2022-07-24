#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<pii, vector<pii>, greater<pii>> pq;

void make_adj(vector<vector<pii>> &adj, int m) {
    cout<<"Making Adjacency List\n";
    int u, v, w;
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }
    cout<<"Done with list\n";
}

void dijkstra(int start, vector<vector<pii>> &adj, pq &Queue, vb &visited, vi &lengths){
    cout<<"Started djikstra\n";
    visited[start]=1;
    Queue.push({0, start});
    while (!Queue.empty()){
        int x=Queue.top().second;
        Queue.pop();
        visited[x]=1;
        cout<<"Visited "<<x+1<<"\n";
        for (auto a : adj[x]){
            int node = a.first;
            int weight = a.second;
            if (!visited[a.first]){
                if (lengths[node]>lengths[x]+weight){
                    lengths[node]=lengths[x]+weight;
                    cout<<"Updated distance of "<<node<<" to "<<lengths[node]<<"\n";
                }
                Queue.push({lengths[node], node});
            }
        }
    }
}

void print_distances(int n, vi &lengths){
    for (int i=0; i<n; i++) {
        cout<<"Distance of "<<i+1<<" is "<<lengths[i]<<"\n";
    }
}

int main(){
    int n, m; cin>>n>>m;
    int source; cin>>source;
    source--;
    vector<vector<pii>> adj;
    adj.resize(n, vector<pii>(0));
    make_adj(adj, m);

    vector<bool> visited;
    visited.resize(n, 0);
    vector<int> lengths;
    lengths.resize(n, INT32_MAX/2);
    priority_queue<pii, vector<pii>, greater<pii>> Queue;
    //greater compares the first elements of 2 pairs, and sorts the queue in ascending order
    lengths[source]=0; 
    dijkstra(source, adj, Queue, visited, lengths);

    print_distances(n, lengths);

}
