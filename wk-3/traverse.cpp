#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
#include <queue>
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

void dfs(int x, vvi &adj, int* arrival, int* departure, int* parent, bool* visited, int &time){
    cout<<"Running DFS on "<<x+1<<", came from "<<parent[x]+1<<endl;
    arrival[x]=time;
    time+=1;
    for (auto a : adj[x]){
        if (!visited[a]){
            visited[a]=1;
            parent[a]=x;
            dfs(a, adj, arrival, departure, parent, visited, time);
        }
    }
    departure[x]=time;
    cout<<"Leaving "<<x+1<<"\n";
}

void start_dfs(vvi &adj, int* arrival, int* departure, int* parent, bool* visited, int n, int &time){
    cout<<"Started DFS\n";
    for (int i=0; i<n; i++) {
        if (!visited[i]){
            visited[i]=1;
            parent[i]=-1; // we reached here because it was not reached by some parent
            dfs(i, adj, arrival, departure, parent, visited, time);
        }
    }
}

void bfs(int src, vvi &adj, bool* visited, int* distance, queue<int> &Queue){
    Queue.push(src);
    visited[src]=1;
    int x=src;
    while(!Queue.empty()){
        x=Queue.front();
        Queue.pop();
        cout<<"Removed "<<x+1<<"\n";
        for (auto a : adj[x]){
            if (!visited[a]){
                Queue.push(a);
                cout<<"Added "<<a+1<<"\n";
                visited[a]=1;
                distance[a]=distance[x]+1;
            }
        }
    }
}

int main(){
    int n, m; cin>>n>>m; //n is the number of nodes, m is the number of edges
    /* First we make an adjacency list */
    vvi adj;
    adj.reserve(n);
    make_adj(adj, m);
    bool visited[n]={0};

    cout<<"Enter 0 for dfs, 1 for bfs\n";
    int choice; cin>>choice;
    if (choice==0){
        int arrival[n], departure[n], parent[n];
        int time=0;
        start_dfs(adj, arrival, departure, parent, visited, n, time);
    }
    else if (choice==1){
        queue<int> Queue;
        int distance[n];
        int source=0; distance[source]=0;
        bfs(source, adj, visited, distance, Queue);
        for (int i=0; i<n; i++) {
            cout<<i+1<<"\t"<<distance[i]<<"\n";
        }
    }


}
