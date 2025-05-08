#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

vector<int> dfs(int node, vector<int> adj[],vector<int> &vis, vector<int>& op){
    op.push_back(node);
    vis[node] = 1;
    for(auto neighbour: adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour,adj,vis,op);
        }
    }
    return op;
}

int main(){
    //storing our graph
    int n,m,u,v,start;
    cout<<"Enter number of vertices in the graph; ";
    cin>>n;
    vector<int> adj[n+1];
    cout<<"Enter number of edges: ";
    cin>>m;
    for(int i = 0;i<m;i++){
        cout<<"Enter edge: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Graph is entered!!!\n";
    vector<int> visited(n+1,0);
    vector<int> ls;
    cout<<"Enter start node: ";
    cin>>start;
    vector<int> op = (dfs(start,adj,visited,ls));
    for(auto it:op){
        cout<<it<<endl;
    }
    return 0;

}