#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

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

    //bfs
    vector<int> bfs;
    queue<int> qu;
    vector<int> visited(n+1,0);
    cout<<"Enter edge where you want to start: ";
    cin>>start;
    qu.push(start);
    while(!qu.empty()){
        int front = qu.front();
        qu.pop();
        bfs.push_back(front);
        for(int x = 0;x<adj[front].size();x++){
            if(visited[adj[front][x]] == 0){
                qu.push(adj[front][x]);
                visited[adj[front][x]] = 1;
            }
        }
    }
    cout<<"BFS traversal is: \n";
    for(int i = 0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
    }
    return 0;
}
